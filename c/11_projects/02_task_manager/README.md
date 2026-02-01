# Task Manger

## Prerequisites (Linux) [Ref](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-bash)

### vcpkg setup (One Time)

1. Clone and bootstrap vcpkg:

   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg && ./bootstrap-vcpkg.sh
   ```

2. Set environment variables (add to your `~/.bashrc` or `~/.zshrc`): ( One Time)

   ```bash
   export VCPKG_ROOT=/path/to/vcpkg
   export PATH=$VCPKG_ROOT:$PATH
   ```

### install build tools ( One Time)

```bash
sudo apt update
sudo apt install cmake pkg-config ninja-build
```

### Set vcpkg path

- update vcpkg path in `CMakeUserPresets.json`
  - "VCPKG_ROOT": "path/to/vcpkg"

## Build & Run

1. Prepare Data Directory

   ```bash
   mkdir -p data
   ```

2. Configure & Build:

   ```bash
      cmake --preset=default
      cmake --build build
   ```

3. Run

   ```bash
   ./build/task_manager
   ```

## Architecture

- CMake: Build system generator.
- Ninja: Fast build system (acts as the make tool).
- vcpkg: C/C++ Package Manager (handles `cjson`).
- GCC/Clang: Compiler.
