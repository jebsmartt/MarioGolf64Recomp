cmake_minimum_required(VERSION 3.20)
project(mariogolf64_port)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Recomp output path — must be provided by the user
if(NOT DEFINED RECOMP_OUTPUT)
    message(FATAL_ERROR
        "RECOMP_OUTPUT not set. Please provide the path to your N64Recomp "
        "recomp_output directory:\n"
        "  cmake -DRECOMP_OUTPUT=/path/to/N64Recomp/recomp_output ...")
endif()

message(STATUS "Using recomp output from: ${RECOMP_OUTPUT}")
