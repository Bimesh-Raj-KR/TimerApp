
# Compiler
CC = gcc

# Cross Compiler
CROSS_CC = aarch64-linux-gnu-$(CC)

# All W Flags
CFLAGS = -Wall -Werror -Wextra

# All .h Includes
INCLUDES = -IappTimer -ILedSimulation -I. -ILed_rpi/usr/include -fanalyzer

# .h Includes for Led Blinking
BLINK_INCLUDES = -IGpioController -LLed_rpi/usr/lib -lgpiod

# Build Macro and Executable for LED Blinking
LED_BLINK = -DENABLE_LED_BLINK -o release/Blink_Led

# All source files
source_files = $(wildcard *.c appTimer/*.c LedSimulation/*.c)

# All directory paths are removed from source file names
file_names = $(notdir $(source_files))

# All object file names are created with path to release folder
object_files = $(patsubst %.c, release/%.o, $(file_names))

# All assembly file names are created with path to release folder
assembly_files = $(patsubst %.c, release/%.s, $(file_names))

# All object file names are created with path to debug folder
debug_files = $(patsubst %.c, debug/%.o, $(file_names))

VPATH = .:appTimer:LedSimulation:GpioController

# Runs both linux and rpi
all: linux rpi

# Generate executable, object and assembly file and store them in release folder
# Generate object file for debugging and store them in debug
linux: Create_release Create_debug Executable Object Debug Assembly

# Stores cross compiler executable in release folder
rpi: Create_release cross_cmp

# Stores cross compiler executable in release folder for blinking LED
ledblink: Create_release cross_cmp_and_blink

# Create release folder
Create_release:
	mkdir -p release

# Create debug folder
Create_debug:
	mkdir -p debug

# Generate executable and store it in release folder
Executable: $(source_files)
	$(CC) $(CFLAGS) $(INCLUDES) $(source_files) -o release/timeandled.exe

# Generate object file in release folder
Object: $(object_files)
release/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -c -o $@

# Generate object file for debugging in debug folder
Debug: $(debug_files)
debug/%.o: %.c
	$(CC) -g -O0 $(CFLAGS) $(INCLUDES) $^ -c -o $@

# Generate assembly file
Assembly: $(assembly_files)
release/%.s: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -S -o $@

# Generate executable for cross compiling
cross_cmp: $(source_files)
	$(CROSS_CC) $(CFLAGS) $(INCLUDES) $(source_files) -o release/ARM64Timeandled

# Generate executable for LED Blinking
cross_cmp_and_blink: $(source_files)
	$(CROSS_CC) $(LED_BLINK) $(CFLAGS) $(INCLUDES) $(source_files) \
	$(BLINK_INCLUDES) $(wildcard GpioController/*.c)

# Remove release, Debug and Build directories

clean: $(source_files)
	rm -rf release
	rm -rf debug
	rm -rf build