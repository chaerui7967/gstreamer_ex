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
include CMakeFiles/filter1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/filter1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/filter1.dir/flags.make

CMakeFiles/filter1.dir/filter1.c.o: CMakeFiles/filter1.dir/flags.make
CMakeFiles/filter1.dir/filter1.c.o: ../filter1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/filter1.dir/filter1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/filter1.dir/filter1.c.o   -c /media/user/SSD/Projects/csample-cg/filter1.c

CMakeFiles/filter1.dir/filter1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filter1.dir/filter1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/user/SSD/Projects/csample-cg/filter1.c > CMakeFiles/filter1.dir/filter1.c.i

CMakeFiles/filter1.dir/filter1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filter1.dir/filter1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/user/SSD/Projects/csample-cg/filter1.c -o CMakeFiles/filter1.dir/filter1.c.s

CMakeFiles/filter1.dir/filter1.c.o.requires:

.PHONY : CMakeFiles/filter1.dir/filter1.c.o.requires

CMakeFiles/filter1.dir/filter1.c.o.provides: CMakeFiles/filter1.dir/filter1.c.o.requires
	$(MAKE) -f CMakeFiles/filter1.dir/build.make CMakeFiles/filter1.dir/filter1.c.o.provides.build
.PHONY : CMakeFiles/filter1.dir/filter1.c.o.provides

CMakeFiles/filter1.dir/filter1.c.o.provides.build: CMakeFiles/filter1.dir/filter1.c.o


# Object files for target filter1
filter1_OBJECTS = \
"CMakeFiles/filter1.dir/filter1.c.o"

# External object files for target filter1
filter1_EXTERNAL_OBJECTS =

filter1: CMakeFiles/filter1.dir/filter1.c.o
filter1: CMakeFiles/filter1.dir/build.make
filter1: CMakeFiles/filter1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable filter1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/filter1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/filter1.dir/build: filter1

.PHONY : CMakeFiles/filter1.dir/build

CMakeFiles/filter1.dir/requires: CMakeFiles/filter1.dir/filter1.c.o.requires

.PHONY : CMakeFiles/filter1.dir/requires

CMakeFiles/filter1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/filter1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/filter1.dir/clean

CMakeFiles/filter1.dir/depend:
	cd /media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/user/SSD/Projects/csample-cg /media/user/SSD/Projects/csample-cg /media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host /media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host /media/user/SSD/Projects/csample-cg/cmake-build-debug-xavier-remote-host/CMakeFiles/filter1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/filter1.dir/depend

