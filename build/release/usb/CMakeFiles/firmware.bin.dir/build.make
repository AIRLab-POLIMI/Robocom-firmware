# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/airlab/robocom/robocom_controller/Robocom-firmware/src/targets/usb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/airlab/robocom/robocom_controller/Robocom-firmware/build/release/usb

# Utility rule file for firmware.bin.

# Include the progress variables for this target.
include CMakeFiles/firmware.bin.dir/progress.make

CMakeFiles/firmware.bin: firmware
	/home/airlab/robocom/Core/core/gcc-arm-none-eabi/bin/arm-none-eabi-objcopy -Obinary firmware firmware.bin

firmware.bin: CMakeFiles/firmware.bin
firmware.bin: CMakeFiles/firmware.bin.dir/build.make

.PHONY : firmware.bin

# Rule to build all files generated by this target.
CMakeFiles/firmware.bin.dir/build: firmware.bin

.PHONY : CMakeFiles/firmware.bin.dir/build

CMakeFiles/firmware.bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/firmware.bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/firmware.bin.dir/clean

CMakeFiles/firmware.bin.dir/depend:
	cd /home/airlab/robocom/robocom_controller/Robocom-firmware/build/release/usb && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/airlab/robocom/robocom_controller/Robocom-firmware/src/targets/usb /home/airlab/robocom/robocom_controller/Robocom-firmware/src/targets/usb /home/airlab/robocom/robocom_controller/Robocom-firmware/build/release/usb /home/airlab/robocom/robocom_controller/Robocom-firmware/build/release/usb /home/airlab/robocom/robocom_controller/Robocom-firmware/build/release/usb/CMakeFiles/firmware.bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/firmware.bin.dir/depend

