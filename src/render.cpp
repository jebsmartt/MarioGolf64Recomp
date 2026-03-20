#include <memory>
#include <cstring>
#include <algorithm>
#include <cstdio>

#define HLSL_CPU
#include "hle/rt64_application.h"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"
#include "ultramodern/renderer_context.hpp"

// ─── RDP register state ──────────────────────────────────────────────────────

static uint8_t DMEM[0x1000];
static uint8_t IMEM[0x1000];

static unsigned int MI_INTR_REG      = 0;
static unsigned int DPC_START_REG    = 0;
static unsigned int DPC_END_REG      = 0;
static unsigned int DPC_CURRENT_REG  = 0;
static unsigned int DPC_STATUS_REG   = 0;
static unsigned int DPC_CLOCK_REG    = 0;
static unsigned int DPC_BUFBUSY_REG  = 0;
static unsigned int DPC_PIPEBUSY_REG = 0;
static unsigned int DPC_TMEM_REG     = 0;

void dummy_check_interrupts() {}

// ─── Config conversion helpers ───────────────────────────────────────────────

static RT64::UserConfiguration::AspectRatio to_rt64(ultramodern::renderer::AspectRatio option) {
    switch (option) {
        case ultramodern::renderer::AspectRatio::Original: return RT64::UserConfiguration::AspectRatio::Original;
        case ultramodern::renderer::AspectRatio::Expand:   return RT64::UserConfiguration::AspectRatio::Expand;
        case ultramodern::renderer::AspectRatio::Manual:   return RT64::UserConfiguration::AspectRatio::Manual;
        default:                                           return RT64::UserConfiguration::AspectRatio::Original;
    }
}

static RT64::UserConfiguration::Antialiasing to_rt64(ultramodern::renderer::Antialiasing option) {
    switch (option) {
        case ultramodern::renderer::Antialiasing::None:   return RT64::UserConfiguration::Antialiasing::None;
        case ultramodern::renderer::Antialiasing::MSAA2X: return RT64::UserConfiguration::Antialiasing::MSAA2X;
        case ultramodern::renderer::Antialiasing::MSAA4X: return RT64::UserConfiguration::Antialiasing::MSAA4X;
        case ultramodern::renderer::Antialiasing::MSAA8X: return RT64::UserConfiguration::Antialiasing::MSAA8X;
        default:                                          return RT64::UserConfiguration::Antialiasing::None;
    }
}

static RT64::UserConfiguration::RefreshRate to_rt64(ultramodern::renderer::RefreshRate option) {
    switch (option) {
        case ultramodern::renderer::RefreshRate::Original: return RT64::UserConfiguration::RefreshRate::Original;
        case ultramodern::renderer::RefreshRate::Display:  return RT64::UserConfiguration::RefreshRate::Display;
        case ultramodern::renderer::RefreshRate::Manual:   return RT64::UserConfiguration::RefreshRate::Manual;
        default:                                           return RT64::UserConfiguration::RefreshRate::Display;
    }
}

static void set_application_user_config(RT64::Application* app,
                                        const ultramodern::renderer::GraphicsConfig& config) {
    switch (config.res_option) {
        default:
        case ultramodern::renderer::Resolution::Auto:
            app->userConfig.resolution = RT64::UserConfiguration::Resolution::WindowIntegerScale;
            app->userConfig.downsampleMultiplier = 1;
            break;
        case ultramodern::renderer::Resolution::Original:
            app->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
            app->userConfig.resolutionMultiplier = std::max(config.ds_option, 1);
            app->userConfig.downsampleMultiplier = std::max(config.ds_option, 1);
            break;
        case ultramodern::renderer::Resolution::Original2x:
            app->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
            app->userConfig.resolutionMultiplier = 2.0 * std::max(config.ds_option, 1);
            app->userConfig.downsampleMultiplier = std::max(config.ds_option, 1);
            break;
    }
    app->userConfig.aspectRatio    = to_rt64(config.ar_option);
    app->userConfig.antialiasing   = to_rt64(config.msaa_option);
    app->userConfig.refreshRate    = to_rt64(config.rr_option);
    app->userConfig.refreshRateTarget = config.rr_manual_value;
    app->userConfig.internalColorFormat = RT64::UserConfiguration::InternalColorFormat::Standard;
    app->userConfig.displayBuffering    = RT64::UserConfiguration::DisplayBuffering::Triple;
}

static ultramodern::renderer::SetupResult map_setup_result(RT64::Application::SetupResult r) {
    switch (r) {
        case RT64::Application::SetupResult::Success:                return ultramodern::renderer::SetupResult::Success;
        case RT64::Application::SetupResult::DynamicLibrariesNotFound: return ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
        case RT64::Application::SetupResult::InvalidGraphicsAPI:     return ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
        case RT64::Application::SetupResult::GraphicsAPINotFound:    return ultramodern::renderer::SetupResult::GraphicsAPINotFound;
        case RT64::Application::SetupResult::GraphicsDeviceNotFound: return ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
    }
    return ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
}

static ultramodern::renderer::GraphicsApi map_graphics_api(RT64::UserConfiguration::GraphicsAPI api) {
    switch (api) {
        case RT64::UserConfiguration::GraphicsAPI::D3D12:    return ultramodern::renderer::GraphicsApi::D3D12;
        case RT64::UserConfiguration::GraphicsAPI::Vulkan:   return ultramodern::renderer::GraphicsApi::Vulkan;
        case RT64::UserConfiguration::GraphicsAPI::Metal:    return ultramodern::renderer::GraphicsApi::Metal;
        case RT64::UserConfiguration::GraphicsAPI::Automatic: return ultramodern::renderer::GraphicsApi::Auto;
    }
    return ultramodern::renderer::GraphicsApi::Auto;
}

// ─── RT64RendererContext ──────────────────────────────────────────────────────

class RT64RendererContext : public ultramodern::renderer::RendererContext {
public:
    std::unique_ptr<RT64::Application> app;

    RT64RendererContext(uint8_t* rdram,
                        ultramodern::renderer::WindowHandle window_handle,
                        bool debug) {
        static unsigned char dummy_rom_header[0x40] = {};

        RT64::Application::Core appCore{};

        // Use a common SDL helper to get native info for all platforms
        SDL_SysWMinfo wmInfo;
        SDL_VERSION(&wmInfo.version);
        const bool hasInfo = SDL_GetWindowWMInfo(window_handle, &wmInfo);

#if defined(_WIN32)
        // Check member access only if the compiler knows we're on Windows
        appCore.window = hasInfo ? wmInfo.info.win.window : nullptr;
#elif defined(__linux__) || defined(__ANDROID__)
        appCore.window = window_handle;
#elif defined(__APPLE__)
        if (hasInfo) {
            appCore.window.window = wmInfo.info.cocoa.window;
            // RT64 usually needs a Metal Layer; SDL_Metal_CreateView provides this
            appCore.window.view = SDL_Metal_CreateView(window_handle);
        }
#endif
        appCore.checkInterrupts     = dummy_check_interrupts;
        appCore.HEADER              = dummy_rom_header;
        appCore.RDRAM               = rdram;
        appCore.DMEM                = DMEM;
        appCore.IMEM                = IMEM;
        appCore.MI_INTR_REG         = &MI_INTR_REG;
        appCore.DPC_START_REG       = &DPC_START_REG;
        appCore.DPC_END_REG         = &DPC_END_REG;
        appCore.DPC_CURRENT_REG     = &DPC_CURRENT_REG;
        appCore.DPC_STATUS_REG      = &DPC_STATUS_REG;
        appCore.DPC_CLOCK_REG       = &DPC_CLOCK_REG;
        appCore.DPC_BUFBUSY_REG     = &DPC_BUFBUSY_REG;
        appCore.DPC_PIPEBUSY_REG    = &DPC_PIPEBUSY_REG;
        appCore.DPC_TMEM_REG        = &DPC_TMEM_REG;

        ultramodern::renderer::ViRegs* vi = ultramodern::renderer::get_vi_regs();
        appCore.VI_STATUS_REG        = &vi->VI_STATUS_REG;
        appCore.VI_ORIGIN_REG        = &vi->VI_ORIGIN_REG;
        appCore.VI_WIDTH_REG         = &vi->VI_WIDTH_REG;
        appCore.VI_INTR_REG          = &vi->VI_INTR_REG;
        appCore.VI_V_CURRENT_LINE_REG = &vi->VI_V_CURRENT_LINE_REG;
        appCore.VI_TIMING_REG        = &vi->VI_TIMING_REG;
        appCore.VI_V_SYNC_REG        = &vi->VI_V_SYNC_REG;
        appCore.VI_H_SYNC_REG        = &vi->VI_H_SYNC_REG;
        appCore.VI_LEAP_REG          = &vi->VI_LEAP_REG;
        appCore.VI_H_START_REG       = &vi->VI_H_START_REG;
        appCore.VI_V_START_REG       = &vi->VI_V_START_REG;
        appCore.VI_V_BURST_REG       = &vi->VI_V_BURST_REG;
        appCore.VI_X_SCALE_REG       = &vi->VI_X_SCALE_REG;
        appCore.VI_Y_SCALE_REG       = &vi->VI_Y_SCALE_REG;

        RT64::ApplicationConfiguration appConfig;
        appConfig.useConfigurationFile = false;

        app = std::make_unique<RT64::Application>(appCore, appConfig);

        auto& cur_config = ultramodern::renderer::get_graphics_config();
        set_application_user_config(app.get(), cur_config);
        app->userConfig.developerMode = debug;

        // Force GBI depth branches to prevent LODs from kicking in
        app->enhancementConfig.f3dex.forceBranch = true;
        // Scale LODs based on output resolution
        app->enhancementConfig.textureLOD.scale = true;

        switch (cur_config.api_option) {
            case ultramodern::renderer::GraphicsApi::D3D12:  app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::D3D12;    break;
            case ultramodern::renderer::GraphicsApi::Vulkan: app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Vulkan;   break;
            case ultramodern::renderer::GraphicsApi::Metal:  app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Metal;    break;
            case ultramodern::renderer::GraphicsApi::Auto:   app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Automatic; break;
        }

        uint32_t thread_id = 0;
#ifdef _WIN32
        thread_id = window_handle.thread_id;
#endif
        setup_result = map_setup_result(app->setup(thread_id));
        chosen_api   = map_graphics_api(app->chosenGraphicsAPI);

        if (setup_result != ultramodern::renderer::SetupResult::Success) {
            app = nullptr;
            return;
        }

        app->setFullScreen(cur_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
    }

    ~RT64RendererContext() override = default;

    bool valid() override {
        return app != nullptr;
    }

    bool update_config(const ultramodern::renderer::GraphicsConfig& old_config,
                       const ultramodern::renderer::GraphicsConfig& new_config) override {
        // Manually check if anything actually changed. 
        // If these are all the same, we don't need to do anything.
        if (old_config.res_option  == new_config.res_option &&
            old_config.msaa_option == new_config.msaa_option &&
            old_config.wm_option   == new_config.wm_option &&
            old_config.api_option  == new_config.api_option) 
        {
            return false;
        }
        if (new_config.wm_option != old_config.wm_option) {
            app->setFullScreen(new_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
        }
        set_application_user_config(app.get(), new_config);
        app->updateUserConfig(true);
        if (new_config.msaa_option != old_config.msaa_option) {
            app->updateMultisampling();
        }
        return true;
    }

    void enable_instant_present() override {
        app->enhancementConfig.presentation.mode =
            RT64::EnhancementConfiguration::Presentation::Mode::PresentEarly;
        app->updateEnhancementConfig();
    }

    void send_dl(const OSTask* task) override {
        fprintf(stdout, "send_dl called, task type: %u\n", task->t.type);
        fflush(stdout);
        app->state->rsp->reset();
        app->interpreter->loadUCodeGBI(
            task->t.ucode      & 0x3FFFFFF,
            task->t.ucode_data & 0x3FFFFFF,
            true);
        app->processDisplayLists(app->core.RDRAM, task->t.data_ptr & 0x3FFFFFF, 0, true);
    }

    void update_screen() override {
        app->updateScreen();
    }

    void shutdown() override {
        if (app != nullptr) {
            app->end();
        }
    }

    uint32_t get_display_framerate() const override {
        return app->presentQueue->ext.sharedResources->swapChainRate;
    }

    float get_resolution_scale() const override {
        constexpr int ReferenceHeight = 240;
        switch (app->userConfig.resolution) {
            case RT64::UserConfiguration::Resolution::WindowIntegerScale:
                if (app->sharedQueueResources->swapChainHeight > 0) {
                    return std::max(
                        float((app->sharedQueueResources->swapChainHeight + ReferenceHeight - 1)
                              / ReferenceHeight),
                        1.0f);
                }
                return 1.0f;
            case RT64::UserConfiguration::Resolution::Manual:
                return float(app->userConfig.resolutionMultiplier);
            default:
                return 1.0f;
        }
    }
};

// ─── Factory ─────────────────────────────────────────────────────────────────

std::unique_ptr<ultramodern::renderer::RendererContext>
create_render_context(uint8_t* rdram,
                      ultramodern::renderer::WindowHandle window_handle,
                      bool developer_mode) {
    return std::make_unique<RT64RendererContext>(rdram, window_handle, developer_mode);
}