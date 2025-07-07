
# Generate linux executable
cmake_minimum_required(VERSION 3.10)
project(GccBuild C)

include_directories(
    ${CMAKE_SOURCE_DIR}/..
    ${CMAKE_SOURCE_DIR}/../appTimer
    ${CMAKE_SOURCE_DIR}/../LedSimulation
)

# In release directory
add_executable(TimerandLed_linux 
    ${CMAKE_SOURCE_DIR}/../main.c
    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
    ${CMAKE_SOURCE_DIR}/../LedSimulation/LedSimulation.c)
target_compile_options(TimerandLed_linux PRIVATE -Wall -Wextra -Werror)
set_target_properties(TimerandLed_linux PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../release)

# In debug directory for debugging
add_executable(TimerandLed_debug
    ${CMAKE_SOURCE_DIR}/../main.c
    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
    ${CMAKE_SOURCE_DIR}/../LedSimulation/LedSimulation.c)
target_compile_options(TimerandLed_debug PRIVATE -g -O0)
set_target_properties(TimerandLed_debug PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../debug)
