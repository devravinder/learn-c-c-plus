cmake_minimum_required(VERSION 3.20)
project(task_manager C)

set(CMAKE_C_STANDARD 11)

find_package(cJSON CONFIG REQUIRED)

add_executable(task_manager
    src/main.c
    src/task.c
)

target_link_libraries(task_manager PRIVATE cjson)
