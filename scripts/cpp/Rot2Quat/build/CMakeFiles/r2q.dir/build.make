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
CMAKE_SOURCE_DIR = /home/suirui/scripts/cpp/Rot2Quat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/suirui/scripts/cpp/Rot2Quat/build

# Include any dependencies generated for this target.
include CMakeFiles/r2q.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/r2q.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/r2q.dir/flags.make

CMakeFiles/r2q.dir/r2q.cpp.o: CMakeFiles/r2q.dir/flags.make
CMakeFiles/r2q.dir/r2q.cpp.o: ../r2q.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suirui/scripts/cpp/Rot2Quat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/r2q.dir/r2q.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r2q.dir/r2q.cpp.o -c /home/suirui/scripts/cpp/Rot2Quat/r2q.cpp

CMakeFiles/r2q.dir/r2q.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r2q.dir/r2q.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suirui/scripts/cpp/Rot2Quat/r2q.cpp > CMakeFiles/r2q.dir/r2q.cpp.i

CMakeFiles/r2q.dir/r2q.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r2q.dir/r2q.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suirui/scripts/cpp/Rot2Quat/r2q.cpp -o CMakeFiles/r2q.dir/r2q.cpp.s

CMakeFiles/r2q.dir/r2q.cpp.o.requires:

.PHONY : CMakeFiles/r2q.dir/r2q.cpp.o.requires

CMakeFiles/r2q.dir/r2q.cpp.o.provides: CMakeFiles/r2q.dir/r2q.cpp.o.requires
	$(MAKE) -f CMakeFiles/r2q.dir/build.make CMakeFiles/r2q.dir/r2q.cpp.o.provides.build
.PHONY : CMakeFiles/r2q.dir/r2q.cpp.o.provides

CMakeFiles/r2q.dir/r2q.cpp.o.provides.build: CMakeFiles/r2q.dir/r2q.cpp.o


# Object files for target r2q
r2q_OBJECTS = \
"CMakeFiles/r2q.dir/r2q.cpp.o"

# External object files for target r2q
r2q_EXTERNAL_OBJECTS =

r2q: CMakeFiles/r2q.dir/r2q.cpp.o
r2q: CMakeFiles/r2q.dir/build.make
r2q: CMakeFiles/r2q.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suirui/scripts/cpp/Rot2Quat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable r2q"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/r2q.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/r2q.dir/build: r2q

.PHONY : CMakeFiles/r2q.dir/build

CMakeFiles/r2q.dir/requires: CMakeFiles/r2q.dir/r2q.cpp.o.requires

.PHONY : CMakeFiles/r2q.dir/requires

CMakeFiles/r2q.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/r2q.dir/cmake_clean.cmake
.PHONY : CMakeFiles/r2q.dir/clean

CMakeFiles/r2q.dir/depend:
	cd /home/suirui/scripts/cpp/Rot2Quat/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suirui/scripts/cpp/Rot2Quat /home/suirui/scripts/cpp/Rot2Quat /home/suirui/scripts/cpp/Rot2Quat/build /home/suirui/scripts/cpp/Rot2Quat/build /home/suirui/scripts/cpp/Rot2Quat/build/CMakeFiles/r2q.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/r2q.dir/depend

