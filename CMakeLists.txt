cmake_minimum_required(VERSION 3.10)
project(TimerApp)

set(CMAKE_C_STANDARD 17)
set(source_files main.c appTimer/appTimer.c LedSimulation/LedSimulation.c)

include_directories(
    ${CMAKE_SOURCE_DIR} appTimer LedSimulation
)

# Release build
add_executable(TimeandLed ${source_files})

target_compile_options(TimeandLed PRIVATE -Wall -Werror -Wextra)
set_target_properties(TimeandLed PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/release
)

# Debug build
add_executable(TimeandLed_debug ${source_files})

target_compile_options(TimeandLed_debug PRIVATE -Wall -Werror -Wextra -g -O0)
set_target_properties(TimeandLed_debug PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/debug
)