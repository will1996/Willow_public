# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/willchambers/Projects/astral

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/willchambers/Projects/astral

# Include any dependencies generated for this target.
include wilo/rendr/CMakeFiles/wilorendr.dir/depend.make

# Include the progress variables for this target.
include wilo/rendr/CMakeFiles/wilorendr.dir/progress.make

# Include the compile flags for this target's objects.
include wilo/rendr/CMakeFiles/wilorendr.dir/flags.make

wilo/rendr/CMakeFiles/wilorendr.dir/renderer.cpp.o: wilo/rendr/CMakeFiles/wilorendr.dir/flags.make
wilo/rendr/CMakeFiles/wilorendr.dir/renderer.cpp.o: wilo/rendr/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/willchambers/Projects/astral/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object wilo/rendr/CMakeFiles/wilorendr.dir/renderer.cpp.o"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wilorendr.dir/renderer.cpp.o -c /Users/willchambers/Projects/astral/wilo/rendr/renderer.cpp

wilo/rendr/CMakeFiles/wilorendr.dir/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wilorendr.dir/renderer.cpp.i"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/willchambers/Projects/astral/wilo/rendr/renderer.cpp > CMakeFiles/wilorendr.dir/renderer.cpp.i

wilo/rendr/CMakeFiles/wilorendr.dir/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wilorendr.dir/renderer.cpp.s"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/willchambers/Projects/astral/wilo/rendr/renderer.cpp -o CMakeFiles/wilorendr.dir/renderer.cpp.s

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.o: wilo/rendr/CMakeFiles/wilorendr.dir/flags.make
wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.o: wilo/vk/vkdevice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/willchambers/Projects/astral/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.o"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.o -c /Users/willchambers/Projects/astral/wilo/vk/vkdevice.cpp

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.i"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/willchambers/Projects/astral/wilo/vk/vkdevice.cpp > CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.i

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.s"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/willchambers/Projects/astral/wilo/vk/vkdevice.cpp -o CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.s

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.o: wilo/rendr/CMakeFiles/wilorendr.dir/flags.make
wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.o: wilo/vk/vkcore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/willchambers/Projects/astral/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.o"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.o -c /Users/willchambers/Projects/astral/wilo/vk/vkcore.cpp

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.i"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/willchambers/Projects/astral/wilo/vk/vkcore.cpp > CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.i

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.s"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/willchambers/Projects/astral/wilo/vk/vkcore.cpp -o CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.s

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.o: wilo/rendr/CMakeFiles/wilorendr.dir/flags.make
wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.o: wilo/vk/vkinit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/willchambers/Projects/astral/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.o"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.o -c /Users/willchambers/Projects/astral/wilo/vk/vkinit.cpp

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.i"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/willchambers/Projects/astral/wilo/vk/vkinit.cpp > CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.i

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.s"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/willchambers/Projects/astral/wilo/vk/vkinit.cpp -o CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.s

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.o: wilo/rendr/CMakeFiles/wilorendr.dir/flags.make
wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.o: wilo/vk/vkutil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/willchambers/Projects/astral/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.o"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.o -c /Users/willchambers/Projects/astral/wilo/vk/vkutil.cpp

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.i"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/willchambers/Projects/astral/wilo/vk/vkutil.cpp > CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.i

wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.s"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/willchambers/Projects/astral/wilo/vk/vkutil.cpp -o CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.s

wilo/rendr/CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.o: wilo/rendr/CMakeFiles/wilorendr.dir/flags.make
wilo/rendr/CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.o: wilo/dev_core/logr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/willchambers/Projects/astral/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object wilo/rendr/CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.o"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.o -c /Users/willchambers/Projects/astral/wilo/dev_core/logr.cpp

wilo/rendr/CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.i"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/willchambers/Projects/astral/wilo/dev_core/logr.cpp > CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.i

wilo/rendr/CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.s"
	cd /Users/willchambers/Projects/astral/wilo/rendr && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/willchambers/Projects/astral/wilo/dev_core/logr.cpp -o CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.s

# Object files for target wilorendr
wilorendr_OBJECTS = \
"CMakeFiles/wilorendr.dir/renderer.cpp.o" \
"CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.o" \
"CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.o" \
"CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.o" \
"CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.o" \
"CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.o"

# External object files for target wilorendr
wilorendr_EXTERNAL_OBJECTS =

wilo/rendr/libwilorendr.a: wilo/rendr/CMakeFiles/wilorendr.dir/renderer.cpp.o
wilo/rendr/libwilorendr.a: wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkdevice.cpp.o
wilo/rendr/libwilorendr.a: wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkcore.cpp.o
wilo/rendr/libwilorendr.a: wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkinit.cpp.o
wilo/rendr/libwilorendr.a: wilo/rendr/CMakeFiles/wilorendr.dir/__/vk/vkutil.cpp.o
wilo/rendr/libwilorendr.a: wilo/rendr/CMakeFiles/wilorendr.dir/__/dev_core/logr.cpp.o
wilo/rendr/libwilorendr.a: wilo/rendr/CMakeFiles/wilorendr.dir/build.make
wilo/rendr/libwilorendr.a: wilo/rendr/CMakeFiles/wilorendr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/willchambers/Projects/astral/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libwilorendr.a"
	cd /Users/willchambers/Projects/astral/wilo/rendr && $(CMAKE_COMMAND) -P CMakeFiles/wilorendr.dir/cmake_clean_target.cmake
	cd /Users/willchambers/Projects/astral/wilo/rendr && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wilorendr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
wilo/rendr/CMakeFiles/wilorendr.dir/build: wilo/rendr/libwilorendr.a

.PHONY : wilo/rendr/CMakeFiles/wilorendr.dir/build

wilo/rendr/CMakeFiles/wilorendr.dir/clean:
	cd /Users/willchambers/Projects/astral/wilo/rendr && $(CMAKE_COMMAND) -P CMakeFiles/wilorendr.dir/cmake_clean.cmake
.PHONY : wilo/rendr/CMakeFiles/wilorendr.dir/clean

wilo/rendr/CMakeFiles/wilorendr.dir/depend:
	cd /Users/willchambers/Projects/astral && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/willchambers/Projects/astral /Users/willchambers/Projects/astral/wilo/rendr /Users/willchambers/Projects/astral /Users/willchambers/Projects/astral/wilo/rendr /Users/willchambers/Projects/astral/wilo/rendr/CMakeFiles/wilorendr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : wilo/rendr/CMakeFiles/wilorendr.dir/depend
