# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /media/user/SSD/Projects/csample-cg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host

# Include any dependencies generated for this target.
include CMakeFiles/tuto12.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tuto12.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tuto12.dir/flags.make

CMakeFiles/tuto12.dir/tuto12.c.o: CMakeFiles/tuto12.dir/flags.make
CMakeFiles/tuto12.dir/tuto12.c.o: ../tuto12.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tuto12.dir/tuto12.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tuto12.dir/tuto12.c.o   -c /media/user/SSD/Projects/csample-cg/tuto12.c

CMakeFiles/tuto12.dir/tuto12.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tuto12.dir/tuto12.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/user/SSD/Projects/csample-cg/tuto12.c > CMakeFiles/tuto12.dir/tuto12.c.i

CMakeFiles/tuto12.dir/tuto12.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tuto12.dir/tuto12.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/user/SSD/Projects/csample-cg/tuto12.c -o CMakeFiles/tuto12.dir/tuto12.c.s

CMakeFiles/tuto12.dir/tuto12.c.o.requires:

.PHONY : CMakeFiles/tuto12.dir/tuto12.c.o.requires

CMakeFiles/tuto12.dir/tuto12.c.o.provides: CMakeFiles/tuto12.dir/tuto12.c.o.requires
	$(MAKE) -f CMakeFiles/tuto12.dir/build.make CMakeFiles/tuto12.dir/tuto12.c.o.provides.build
.PHONY : CMakeFiles/tuto12.dir/tuto12.c.o.provides

CMakeFiles/tuto12.dir/tuto12.c.o.provides.build: CMakeFiles/tuto12.dir/tuto12.c.o


# Object files for target tuto12
tuto12_OBJECTS = \
"CMakeFiles/tuto12.dir/tuto12.c.o"

# External object files for target tuto12
tuto12_EXTERNAL_OBJECTS =

tuto12: CMakeFiles/tuto12.dir/tuto12.c.o
tuto12: CMakeFiles/tuto12.dir/build.make
tuto12: CMakeFiles/tuto12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable tuto12"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tuto12.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tuto12.dir/build: tuto12

.PHONY : CMakeFiles/tuto12.dir/build

CMakeFiles/tuto12.dir/requires: CMakeFiles/tuto12.dir/tuto12.c.o.requires

.PHONY : CMakeFiles/tuto12.dir/requires

CMakeFiles/tuto12.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tuto12.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tuto12.dir/clean

CMakeFiles/tuto12.dir/depend:
	cd /media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/user/SSD/Projects/csample-cg /media/user/SSD/Projects/csample-cg /media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host /media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host /media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host/CMakeFiles/tuto12.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tuto12.dir/depend
