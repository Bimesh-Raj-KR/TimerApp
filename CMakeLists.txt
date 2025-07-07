
# Main CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(AppTimer C)

include(ExternalProject)

# Linux Build
ExternalProject_Add(Build_Linux
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/build_gcc
    BINARY_DIR ${CMAKE_BINARY_DIR}/build_gcc
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install
    INSTALL_COMMAND ""  # Skip install step
)

# Raspberry Pi Cross-Compilation
ExternalProject_Add(Build_Rpi
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/build_rpi
    BINARY_DIR ${CMAKE_BINARY_DIR}/build_rpi
    CMAKE_ARGS
        -DCMAKE_TOOLCHAIN_FILE=${CMAKE_SOURCE_DIR}/toolchain.cmake
        -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install
    INSTALL_COMMAND "" 
)

# Group both targets under one
add_custom_target(AllTargets ALL
    DEPENDS Build_Linux Build_Rpi
)

