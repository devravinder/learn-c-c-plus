cmake_minimum_required(VERSION 3.20)
project(TaskManager C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find cJSON package
find_package(cJSON CONFIG REQUIRED)

# Source files
set(SOURCES
    src/main.c
    src/task.c
    src/storage.c
)

# Headers
set(HEADERS
    include/task.h
    include/storage.h
)

# Create executable
add_executable(task_manager ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(task_manager PRIVATE include)

# Link libraries
target_link_libraries(task_manager PRIVATE cjson)

# Installation
install(TARGETS task_manager DESTINATION bin)