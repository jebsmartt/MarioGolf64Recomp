# Mario Golf 64 Port

A native port of Mario Golf (N64) using N64Recomp and N64ModernRuntime.

## Prerequisites

This project requires output from two other repositories before building.
See [BUILD.md](BUILD.md) for the full three-step setup process.

## Quick Start
```bash
cmake -B build -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang \
      -DRECOMP_OUTPUT=/path/to/N64Recomp/recomp_output \
      -DCMAKE_BUILD_TYPE=Release
cmake --build build
```
