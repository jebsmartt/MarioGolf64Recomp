#include <cstdio>
#include <vector>
#include <stdexcept>
#include <cinttypes>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"
#undef None
#undef Status
#undef LockMask
#undef ControlMask
#undef Success
#undef Always
#endif

#include "ultramodern/ultra64.h"
#include "ultramodern/ultramodern.hpp"
#include "librecomp/game.hpp"
#include "librecomp/helpers.hpp"

// ─── Error handling ───────────────────────────────────────────────────────────

template<typename... Ts>
void exit_error(const char* str, Ts ...args) {
    ((void)fprintf(stderr, str, args), ...);
    ultramodern::error_handling::quick_exit(__FILE__, __LINE__, __FUNCTION__);
}

// ─── Graphics ────────────────────────────────────────────────────────────────

// Forward declaration from render.cpp
std::unique_ptr<ultramodern::renderer::RendererContext>
create_render_context(uint8_t* rdram,
                      ultramodern::renderer::WindowHandle window_handle,
                      bool developer_mode);

SDL_Window* window;

ultramodern::gfx_callbacks_t::gfx_data_t create_gfx() {
    SDL_SetHint(SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS5_RUMBLE, "1");
    SDL_SetHint(SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) > 0) {
        exit_error("Failed to initialize SDL2: %s\n", SDL_GetError());
    }
    fprintf(stdout, "SDL Video Driver: %s\n", SDL_GetCurrentVideoDriver());
    return {};
}

ultramodern::renderer::WindowHandle create_window(ultramodern::gfx_callbacks_t::gfx_data_t) {
    uint32_t flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN;
    window = SDL_CreateWindow("Mario Golf 64",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 960, flags);
    if (window == nullptr) {
        exit_error("Failed to create window: %s\n", SDL_GetError());
    }
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    SDL_GetWindowWMInfo(window, &wmInfo);
    return ultramodern::renderer::WindowHandle{ window };
}

void update_gfx(void*) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            ultramodern::error_handling::quick_exit(__FILE__, __LINE__, __FUNCTION__);
        }
    }
}

void on_gfx_init() {
    fprintf(stdout, "GFX initialized, starting game\n");
    fflush(stdout);
    recomp::start_game(u8"mariogolf.n64.us.1.0");
}

// ─── Audio ───────────────────────────────────────────────────────────────────

static SDL_AudioCVT audio_convert;
static SDL_AudioDeviceID audio_device = 0;
static uint32_t sample_rate = 48000;
static uint32_t output_sample_rate = 48000;
constexpr uint32_t input_channels = 2;
static uint32_t output_channels = 2;
constexpr uint32_t duplicated_input_frames = 4;
static uint32_t discarded_output_frames;
constexpr uint32_t bytes_per_frame = input_channels * sizeof(float);

void update_audio_converter() {
    int ret = SDL_BuildAudioCVT(&audio_convert,
        AUDIO_F32, input_channels, sample_rate,
        AUDIO_F32, output_channels, output_sample_rate);
    if (ret < 0) {
        printf("Error creating SDL audio converter: %s\n", SDL_GetError());
        throw std::runtime_error("Error creating SDL audio converter");
    }
    discarded_output_frames = duplicated_input_frames * output_sample_rate / sample_rate;
}

void set_frequency(uint32_t freq) {
    sample_rate = freq;
    update_audio_converter();
}

void reset_audio(uint32_t output_freq) {
    SDL_AudioSpec spec_desired{
        .freq = (int)output_freq,
        .format = AUDIO_F32,
        .channels = (Uint8)output_channels,
        .silence = 0,
        .samples = 0x100,
        .padding = 0,
        .size = 0,
        .callback = nullptr,
        .userdata = nullptr
    };
    audio_device = SDL_OpenAudioDevice(nullptr, false, &spec_desired, nullptr, 0);
    if (audio_device == 0) {
        exit_error("SDL error opening audio device: %s\n", SDL_GetError());
    }
    SDL_PauseAudioDevice(audio_device, 0);
    output_sample_rate = output_freq;
    update_audio_converter();
}

void queue_samples(int16_t* audio_data, size_t sample_count) {
    static std::vector<float> swap_buffer;
    static std::array<float, duplicated_input_frames * input_channels> duplicated_sample_buffer;

    size_t resampled_sample_count = sample_count + duplicated_input_frames * input_channels;
    size_t max_sample_count = std::max(resampled_sample_count,
        resampled_sample_count * (size_t)audio_convert.len_mult);
    if (max_sample_count > swap_buffer.size()) {
        swap_buffer.resize(max_sample_count);
    }
    for (size_t i = 0; i < duplicated_input_frames * input_channels; i++) {
        swap_buffer[i] = duplicated_sample_buffer[i];
    }
    for (size_t i = 0; i < sample_count; i += input_channels) {
        swap_buffer[i + 0 + duplicated_input_frames * input_channels] =
            audio_data[i + 1] * (0.5f / 32768.0f);
        swap_buffer[i + 1 + duplicated_input_frames * input_channels] =
            audio_data[i + 0] * (0.5f / 32768.0f);
    }
    for (size_t i = 0; i < duplicated_input_frames * input_channels; i++) {
        duplicated_sample_buffer[i] = swap_buffer[i + sample_count];
    }
    audio_convert.buf = reinterpret_cast<Uint8*>(swap_buffer.data());
    audio_convert.len = (sample_count + duplicated_input_frames * input_channels)
        * sizeof(swap_buffer[0]);
    SDL_ConvertAudio(&audio_convert);
    uint32_t num_bytes_to_queue = audio_convert.len_cvt
        - output_channels * discarded_output_frames * sizeof(swap_buffer[0]);
    float* samples_to_queue = swap_buffer.data() + output_channels * discarded_output_frames / 2;
    SDL_QueueAudio(audio_device, samples_to_queue, num_bytes_to_queue);
}

size_t get_frames_remaining() {
    constexpr float buffer_offset_frames = 1.0f;
    uint64_t buffered_byte_count = SDL_GetQueuedAudioSize(audio_device);
    buffered_byte_count = buffered_byte_count * 2 * sample_rate / output_sample_rate / output_channels;
    uint32_t frames_per_vi = (sample_rate / 60);
    if (buffered_byte_count > (buffer_offset_frames * bytes_per_frame * frames_per_vi)) {
        buffered_byte_count -= (buffer_offset_frames * bytes_per_frame * frames_per_vi);
    } else {
        buffered_byte_count = 0;
    }
    return static_cast<uint32_t>(buffered_byte_count / bytes_per_frame);
}

// ─── RSP ─────────────────────────────────────────────────────────────────────

extern RspUcodeFunc aspMain;

RspUcodeFunc* get_rsp_microcode(const OSTask* task) {
    fprintf(stdout, "RSP task type: %u\n", task->t.type);
    fflush(stdout);
    switch (task->t.type) {
    case M_AUDTASK:
        return aspMain;
    default:
        fprintf(stderr, "Unknown RSP task type: %" PRIu32 "\n", task->t.type);
        return nullptr;
    }
}

// ─── Input ───────────────────────────────────────────────────────────────────

void poll_input() {
    // TODO: implement controller polling
}

bool get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
    // TODO: implement input reading
    *buttons = 0;
    *x = 0.0f;
    *y = 0.0f;
    return false;
}

void set_rumble(int controller_num, bool on) {
    // TODO: implement rumble
}

// ─── Entrypoint ──────────────────────────────────────────────────────────────

extern "C" void static_6_80025C50(uint8_t* rdram, recomp_context* ctx);
gpr get_entrypoint_address() { return (gpr)(int32_t)0x80025C50u; }

std::vector<recomp::GameEntry> supported_games = {
    {
        .rom_hash          = 0xC44360A904011B02ULL,
        .internal_name     = "MarioGolf64",
        .game_id           = u8"mariogolf.n64.us.1.0",
        .mod_game_id       = "mariogolf",
        .save_type         = recomp::SaveType::Sram,
        .is_enabled        = true,
        .has_compressed_code = false,
        .entrypoint_address = get_entrypoint_address(),
        .entrypoint        = static_6_80025C50,
    },
};

// ─── Main ─────────────────────────────────────────────────────────────────────

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    // Register the game
    for (const auto& game : supported_games) {
        recomp::register_game(game);
    }

    // Initialize audio
    SDL_InitSubSystem(SDL_INIT_AUDIO);
    reset_audio(48000);

    // Set up callbacks
    recomp::rsp::callbacks_t rsp_callbacks{
        .get_rsp_microcode = get_rsp_microcode,
    };

    ultramodern::renderer::callbacks_t renderer_callbacks{
        .create_render_context = create_render_context,
    };

    ultramodern::gfx_callbacks_t gfx_callbacks{
        .create_gfx    = create_gfx,
        .create_window = create_window,
        .update_gfx    = update_gfx,
    };

    ultramodern::audio_callbacks_t audio_callbacks{
        .queue_samples      = queue_samples,
        .get_frames_remaining = get_frames_remaining,
        .set_frequency      = set_frequency,
    };

    ultramodern::input::callbacks_t input_callbacks{
        .poll_input = poll_input,
        .get_input  = get_input,
        .set_rumble = set_rumble,
    };

    ultramodern::events::callbacks_t events_callbacks{
    .gfx_init_callback = on_gfx_init,
    };

    recomp::Configuration cfg{
        .project_version    = { 0, 1, 0 },
        .rsp_callbacks      = rsp_callbacks,
        .renderer_callbacks = renderer_callbacks,
        .audio_callbacks    = audio_callbacks,
        .input_callbacks    = input_callbacks,
        .events_callbacks   = events_callbacks,
        .gfx_callbacks      = gfx_callbacks,
    };

    recomp::register_config_path("/home/jebsmartt/repos/mariogolf_recomp/MarioGolf64Recomp");
    recomp::check_all_stored_roms();
    std::u8string game_id = u8"mariogolf.n64.us.1.0";
    fprintf(stdout, "ROM valid: %s\n", recomp::is_rom_valid(game_id) ? "yes" : "no");
    fprintf(stdout, "Starting game...\n");
    fflush(stdout);
    recomp::start(cfg);
    return EXIT_SUCCESS;
}