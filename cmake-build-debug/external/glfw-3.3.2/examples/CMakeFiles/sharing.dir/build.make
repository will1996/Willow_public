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
include external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/flags.make

external/glfw-3.3.2/examples/sharing.app/Contents/Resources/glfw.icns: ../external/glfw-3.3.2/examples/glfw.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content external/glfw-3.3.2/examples/sharing.app/Contents/Resources/glfw.icns"
	$(CMAKE_COMMAND) -E copy /Users/w/Projects/Willow/external/glfw-3.3.2/examples/glfw.icns external/glfw-3.3.2/examples/sharing.app/Contents/Resources/glfw.icns

external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/sharing.c.o: external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/flags.make
external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/sharing.c.o: ../external/glfw-3.3.2/examples/sharing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/w/Projects/Willow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/sharing.c.o"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sharing.dir/sharing.c.o   -c /Users/w/Projects/Willow/external/glfw-3.3.2/examples/sharing.c

external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/sharing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sharing.dir/sharing.c.i"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/w/Projects/Willow/external/glfw-3.3.2/examples/sharing.c > CMakeFiles/sharing.dir/sharing.c.i

external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/sharing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sharing.dir/sharing.c.s"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/w/Projects/Willow/external/glfw-3.3.2/examples/sharing.c -o CMakeFiles/sharing.dir/sharing.c.s

external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.o: external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/flags.make
external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.o: ../external/glfw-3.3.2/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/w/Projects/Willow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.o"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sharing.dir/__/deps/glad_gl.c.o   -c /Users/w/Projects/Willow/external/glfw-3.3.2/deps/glad_gl.c

external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sharing.dir/__/deps/glad_gl.c.i"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/w/Projects/Willow/external/glfw-3.3.2/deps/glad_gl.c > CMakeFiles/sharing.dir/__/deps/glad_gl.c.i

external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sharing.dir/__/deps/glad_gl.c.s"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/w/Projects/Willow/external/glfw-3.3.2/deps/glad_gl.c -o CMakeFiles/sharing.dir/__/deps/glad_gl.c.s

# Object files for target sharing
sharing_OBJECTS = \
"CMakeFiles/sharing.dir/sharing.c.o" \
"CMakeFiles/sharing.dir/__/deps/glad_gl.c.o"

# External object files for target sharing
sharing_EXTERNAL_OBJECTS =

external/glfw-3.3.2/examples/sharing.app/Contents/MacOS/sharing: external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/sharing.c.o
external/glfw-3.3.2/examples/sharing.app/Contents/MacOS/sharing: external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.o
external/glfw-3.3.2/examples/sharing.app/Contents/MacOS/sharing: external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/build.make
external/glfw-3.3.2/examples/sharing.app/Contents/MacOS/sharing: external/glfw-3.3.2/src/libglfw3.a
external/glfw-3.3.2/examples/sharing.app/Contents/MacOS/sharing: external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/w/Projects/Willow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable sharing.app/Contents/MacOS/sharing"
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sharing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/build: external/glfw-3.3.2/examples/sharing.app/Contents/MacOS/sharing
external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/build: external/glfw-3.3.2/examples/sharing.app/Contents/Resources/glfw.icns

.PHONY : external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/build

external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/clean:
	cd /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/examples && $(CMAKE_COMMAND) -P CMakeFiles/sharing.dir/cmake_clean.cmake
.PHONY : external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/clean

external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/depend:
	cd /Users/w/Projects/Willow/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/w/Projects/Willow /Users/w/Projects/Willow/external/glfw-3.3.2/examples /Users/w/Projects/Willow/cmake-build-debug /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/examples /Users/w/Projects/Willow/cmake-build-debug/external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.3.2/examples/CMakeFiles/sharing.dir/depend
