# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/w/Projects/Willow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/w/Projects/Willow/cmake-build-debug

# Include any dependencies generated for this target.
include external/glfw-3.3.2/tests/CMakeFiles/windows.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.3.2/tests/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.3.2/tests/CMakeFiles/windows.dir/flags.make

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/windows.c.o: external/glfw-3.3.2/tests/CMakeFiles/windows.dir/flags.make
external/glfw-3.3.2/tests/CMakeFiles/windows.dir/windows.c.o: ../external/glfw-3.3.2/tests/windows.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/w/Projects/Willow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.3.2/tests/CMakeFiles/windows.dir/windows.c.o"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/windows.c.o   -c /Users/w/Projects/Willow/external/glfw-3.3.2/tests/windows.c

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/windows.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.c.i"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/w/Projects/Willow/external/glfw-3.3.2/tests/windows.c > CMakeFiles/windows.dir/windows.c.i

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/windows.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.c.s"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/w/Projects/Willow/external/glfw-3.3.2/tests/windows.c -o CMakeFiles/windows.dir/windows.c.s

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/getopt.c.o: external/glfw-3.3.2/tests/CMakeFiles/windows.dir/flags.make
external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/getopt.c.o: ../external/glfw-3.3.2/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/w/Projects/Willow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/getopt.c.o"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/__/deps/getopt.c.o   -c /Users/w/Projects/Willow/external/glfw-3.3.2/deps/getopt.c

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/__/deps/getopt.c.i"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/w/Projects/Willow/external/glfw-3.3.2/deps/getopt.c > CMakeFiles/windows.dir/__/deps/getopt.c.i

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/__/deps/getopt.c.s"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/w/Projects/Willow/external/glfw-3.3.2/deps/getopt.c -o CMakeFiles/windows.dir/__/deps/getopt.c.s

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.o: external/glfw-3.3.2/tests/CMakeFiles/windows.dir/flags.make
external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.o: ../external/glfw-3.3.2/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/w/Projects/Willow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.o"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/__/deps/glad_gl.c.o   -c /Users/w/Projects/Willow/external/glfw-3.3.2/deps/glad_gl.c

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/__/deps/glad_gl.c.i"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/w/Projects/Willow/external/glfw-3.3.2/deps/glad_gl.c > CMakeFiles/windows.dir/__/deps/glad_gl.c.i

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/__/deps/glad_gl.c.s"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/w/Projects/Willow/external/glfw-3.3.2/deps/glad_gl.c -o CMakeFiles/windows.dir/__/deps/glad_gl.c.s

# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.c.o" \
"CMakeFiles/windows.dir/__/deps/getopt.c.o" \
"CMakeFiles/windows.dir/__/deps/glad_gl.c.o"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

external/glfw-3.3.2/tests/windows.app/Contents/MacOS/windows: external/glfw-3.3.2/tests/CMakeFiles/windows.dir/windows.c.o
external/glfw-3.3.2/tests/windows.app/Contents/MacOS/windows: external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/getopt.c.o
external/glfw-3.3.2/tests/windows.app/Contents/MacOS/windows: external/glfw-3.3.2/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.o
external/glfw-3.3.2/tests/windows.app/Contents/MacOS/windows: external/glfw-3.3.2/tests/CMakeFiles/windows.dir/build.make
external/glfw-3.3.2/tests/windows.app/Contents/MacOS/windows: external/glfw-3.3.2/src/libglfw3.a
external/glfw-3.3.2/tests/windows.app/Contents/MacOS/windows: external/glfw-3.3.2/tests/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/w/Projects/Willow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable windows.app/Contents/MacOS/windows"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/windows.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.3.2/tests/CMakeFiles/windows.dir/build: external/glfw-3.3.2/tests/windows.app/Contents/MacOS/windows

.PHONY : external/glfw-3.3.2/tests/CMakeFiles/windows.dir/build

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/clean:
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests && $(CMAKE_COMMAND) -P CMakeFiles/windows.dir/cmake_clean.cmake
.PHONY : external/glfw-3.3.2/tests/CMakeFiles/windows.dir/clean

external/glfw-3.3.2/tests/CMakeFiles/windows.dir/depend:
	cd /Users/w/Projects/Willow/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/w/Projects/Willow /Users/w/Projects/Willow/external/glfw-3.3.2/tests /Users/w/Projects/Willow/cmake-build-debug /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/tests/CMakeFiles/windows.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.3.2/tests/CMakeFiles/windows.dir/depend

