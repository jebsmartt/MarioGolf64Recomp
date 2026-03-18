cmake_minimum_required(VERSION 3.20)
project(MarioGolf64Recomp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Require clang
if(NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message(WARNING "This project is developed with Clang. Other compilers may work but are not regularly tested.")
endif()

# Recomp output path
if(NOT DEFINED RECOMP_OUTPUT)
    message(FATAL_ERROR
        "RECOMP_OUTPUT not set. Provide the path to your N64Recomp recomp_output directory:\n"
        "  cmake -DRECOMP_OUTPUT=/path/to/N64Recomp/recomp_output ...")
endif()
message(STATUS "Using recomp output from: ${RECOMP_OUTPUT}")

# RT64 options
set(RT64_STATIC ON CACHE BOOL "Build RT64 as static library" FORCE)
set(RT64_SDL_WINDOW_VULKAN ON CACHE BOOL "Build RT64 with SDL/Vulkan for Linux" FORCE)

# Add dependencies
add_subdirectory(lib/N64ModernRuntime)
add_subdirectory(lib/rt64)

# Collect recomp output sources
file(GLOB RECOMP_SOURCES "${RECOMP_OUTPUT}/*.c")
if(NOT RECOMP_SOURCES)
    message(FATAL_ERROR "No .c files found in RECOMP_OUTPUT: ${RECOMP_OUTPUT}")
endif()
message(STATUS "Found ${CMAKE_CURRENT_LIST_DIR} recomp sources")

# Main executable
add_executable(MarioGolf64Recomp
    rsp/aspMain.cpp
    src/main.cpp
    ${RECOMP_SOURCES}
)

target_include_directories(MarioGolf64Recomp PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/N64Recomp/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/ultramodern/include
    ${CMAKE_SOURCE_DIR}/lib/N64ModernRuntime/librecomp/include
    ${CMAKE_SOURCE_DIR}/lib/rt64/src
    ${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib
    ${CMAKE_SOURCE_DIR}/lib/rt64/src/contrib/hlslpp/include
    ${RECOMP_OUTPUT}
)

target_compile_options(MarioGolf64Recomp PRIVATE -msse4.1)

target_link_libraries(MarioGolf64Recomp PRIVATE
    librecomp
    rt64
)

# Linux-specific
if(UNIX AND NOT APPLE)
    target_compile_options(MarioGolf64Recomp PRIVATE -msse4.1)

target_link_libraries(MarioGolf64Recomp PRIVATE
        "-latomic"
        ${CMAKE_DL_LIBS}
        Threads::Threads
    )
    find_package(Threads REQUIRED)
endif()
