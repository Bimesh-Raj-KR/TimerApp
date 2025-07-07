
# Generate rpi executable in release directory
cmake_minimum_required(VERSION 3.10)
project(RpiBuild C)

include_directories(
    ${CMAKE_SOURCE_DIR}/..
    ${CMAKE_SOURCE_DIR}/../appTimer
    ${CMAKE_SOURCE_DIR}/../LedSimulation
)

add_executable(TimerandLed_rpi
    ${CMAKE_SOURCE_DIR}/../main.c
    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
    ${CMAKE_SOURCE_DIR}/../LedSimulation/LedSimulation.c)
target_compile_options(TimerandLed_rpi PRIVATE -Wall -Wextra -Werror)
set_target_properties(TimerandLed_rpi PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../release)