# Task Manger

## cmake install (one time)

```bash
sudo apt update
sudo apt install cmake
sudo apt install ninja-build


```

## vcpkg setup (one time) [Ref](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-bash)

- `git clone https://github.com/microsoft/vcpkg.git`
- `cd vcpkg && ./bootstrap-vcpkg.sh`

- ```bash

    export VCPKG_ROOT=/path/to/vcpkg
    export PATH=$VCPKG_ROOT:$PATH

  ```

## Project Setup

- `mkdir helloworld && cd helloworld`
- `vcpkg new --application`
- `vcpkg add port cjson`

## Build & Run

```bash
mkdir data
echo [] > data/tasks.json
```

```bash
cmake --preset=default
cmake --build build
./build/task_manager
```

## Things to know

CMake  → generates build files
Ninja  → actually builds the code
gcc/clang → compiles
