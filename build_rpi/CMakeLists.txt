
# Generate rpi executable in release directory for LED Blinking
cmake_minimum_required(VERSION 3.10)
project(RpiBuild C)

include_directories(
    ${CMAKE_SOURCE_DIR}/..
    ${CMAKE_SOURCE_DIR}/../appTimer
    ${CMAKE_SOURCE_DIR}/../LedSimulation
    ${CMAKE_SOURCE_DIR}/../GpioController
    ${CMAKE_SOURCE_DIR}/../Led_rpi/usr/include

)

add_executable(TimerandLed_rpi
    ${CMAKE_SOURCE_DIR}/../main.c
    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
    ${CMAKE_SOURCE_DIR}/../LedSimulation/LedSimulation.c
    ${CMAKE_SOURCE_DIR}/../GpioController/GpioController.c)
target_compile_options(TimerandLed_rpi PRIVATE 
                        -Wall -Wextra -Werror -fanalyzer -DENABLE_LED_BLINK)
target_link_directories(TimerandLed_rpi PRIVATE 
                        ${CMAKE_SOURCE_DIR}/../Led_rpi/usr/lib)
target_link_libraries(TimerandLed_rpi PRIVATE 
                        ${CMAKE_SOURCE_DIR}/../Led_rpi/usr/lib/libgpiod.so)
set_target_properties(TimerandLed_rpi PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../release)