# TimerApp

A cross-platform C project that builds a timer application for both Linux and Raspberry Pi, using either **CMake** or **Make** as the build system.

## Features

Organized source code in multiple directories
Separate **release** and **debug** builds
Cross-compilation support for Raspberry Pi (aarch64)
Clean, portable build system

## Prerequisites

**CMake** ≥ 3.10
**Make**
**GCC** (for Linux build)
**aarch64-linux-gnu-gcc** (for Raspberry Pi cross-compilation)


## Building with Make

### 1. Linux

$ make linux

Output: release/timeandled.exe
        release/appTimer.o
        release/appTimer.s
        release/LedSimulation.o
        release/LedSimulation.s
        release/main.o
        release/main.s
        debug/appTimer.o
        debug/LedSimulation.o
        debug/main.o
        

### 2. Raspberry Pi (cross-compile)

$ make rpi

Output: release/ARM64Timeandled

### 3. Raspberry Pi (cross-compile and Blink LED)

$ make ledblink

Output: release/Blink_Led

### 4. Build All

$ make all

Builds both Linux and Raspberry Pi (cross-compile) release targets.

### 5. Clean Build Artifacts

$ make clean

Removes all files from release/, debug/ and build/ folders.

## Building with CMake

### 1. Release Build

$ cmake -B build
$ cmake --build build