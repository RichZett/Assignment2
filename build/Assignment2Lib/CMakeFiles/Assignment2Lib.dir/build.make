# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/richardzetterman/Documents/RealTime/Assignment2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/richardzetterman/Documents/RealTime/Assignment2/build

# Include any dependencies generated for this target.
include Assignment2Lib/CMakeFiles/Assignment2Lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Assignment2Lib/CMakeFiles/Assignment2Lib.dir/compiler_depend.make

# Include the progress variables for this target.
include Assignment2Lib/CMakeFiles/Assignment2Lib.dir/progress.make

# Include the compile flags for this target's objects.
include Assignment2Lib/CMakeFiles/Assignment2Lib.dir/flags.make

Assignment2Lib/CMakeFiles/Assignment2Lib.dir/codegen:
.PHONY : Assignment2Lib/CMakeFiles/Assignment2Lib.dir/codegen

Assignment2Lib/CMakeFiles/Assignment2Lib.dir/cmdproc.c.o: Assignment2Lib/CMakeFiles/Assignment2Lib.dir/flags.make
Assignment2Lib/CMakeFiles/Assignment2Lib.dir/cmdproc.c.o: /Users/richardzetterman/Documents/RealTime/Assignment2/Assignment2Lib/cmdproc.c
Assignment2Lib/CMakeFiles/Assignment2Lib.dir/cmdproc.c.o: Assignment2Lib/CMakeFiles/Assignment2Lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/richardzetterman/Documents/RealTime/Assignment2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Assignment2Lib/CMakeFiles/Assignment2Lib.dir/cmdproc.c.o"
	cd /Users/richardzetterman/Documents/RealTime/Assignment2/build/Assignment2Lib && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Assignment2Lib/CMakeFiles/Assignment2Lib.dir/cmdproc.c.o -MF CMakeFiles/Assignment2Lib.dir/cmdproc.c.o.d -o CMakeFiles/Assignment2Lib.dir/cmdproc.c.o -c /Users/richardzetterman/Documents/RealTime/Assignment2/Assignment2Lib/cmdproc.c

Assignment2Lib/CMakeFiles/Assignment2Lib.dir/cmdproc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Assignment2Lib.dir/cmdproc.c.i"
	cd /Users/richardzetterman/Documents/RealTime/Assignment2/build/Assignment2Lib && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/richardzetterman/Documents/RealTime/Assignment2/Assignment2Lib/cmdproc.c > CMakeFiles/Assignment2Lib.dir/cmdproc.c.i

Assignment2Lib/CMakeFiles/Assignment2Lib.dir/cmdproc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Assignment2Lib.dir/cmdproc.c.s"
	cd /Users/richardzetterman/Documents/RealTime/Assignment2/build/Assignment2Lib && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/richardzetterman/Documents/RealTime/Assignment2/Assignment2Lib/cmdproc.c -o CMakeFiles/Assignment2Lib.dir/cmdproc.c.s

# Object files for target Assignment2Lib
Assignment2Lib_OBJECTS = \
"CMakeFiles/Assignment2Lib.dir/cmdproc.c.o"

# External object files for target Assignment2Lib
Assignment2Lib_EXTERNAL_OBJECTS =

Assignment2Lib/libAssignment2Lib.a: Assignment2Lib/CMakeFiles/Assignment2Lib.dir/cmdproc.c.o
Assignment2Lib/libAssignment2Lib.a: Assignment2Lib/CMakeFiles/Assignment2Lib.dir/build.make
Assignment2Lib/libAssignment2Lib.a: Assignment2Lib/CMakeFiles/Assignment2Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/richardzetterman/Documents/RealTime/Assignment2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libAssignment2Lib.a"
	cd /Users/richardzetterman/Documents/RealTime/Assignment2/build/Assignment2Lib && $(CMAKE_COMMAND) -P CMakeFiles/Assignment2Lib.dir/cmake_clean_target.cmake
	cd /Users/richardzetterman/Documents/RealTime/Assignment2/build/Assignment2Lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment2Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Assignment2Lib/CMakeFiles/Assignment2Lib.dir/build: Assignment2Lib/libAssignment2Lib.a
.PHONY : Assignment2Lib/CMakeFiles/Assignment2Lib.dir/build

Assignment2Lib/CMakeFiles/Assignment2Lib.dir/clean:
	cd /Users/richardzetterman/Documents/RealTime/Assignment2/build/Assignment2Lib && $(CMAKE_COMMAND) -P CMakeFiles/Assignment2Lib.dir/cmake_clean.cmake
.PHONY : Assignment2Lib/CMakeFiles/Assignment2Lib.dir/clean

Assignment2Lib/CMakeFiles/Assignment2Lib.dir/depend:
	cd /Users/richardzetterman/Documents/RealTime/Assignment2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/richardzetterman/Documents/RealTime/Assignment2 /Users/richardzetterman/Documents/RealTime/Assignment2/Assignment2Lib /Users/richardzetterman/Documents/RealTime/Assignment2/build /Users/richardzetterman/Documents/RealTime/Assignment2/build/Assignment2Lib /Users/richardzetterman/Documents/RealTime/Assignment2/build/Assignment2Lib/CMakeFiles/Assignment2Lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Assignment2Lib/CMakeFiles/Assignment2Lib.dir/depend

