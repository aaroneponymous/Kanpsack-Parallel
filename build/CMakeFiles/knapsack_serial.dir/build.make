# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build"

# Include any dependencies generated for this target.
include CMakeFiles/knapsack_serial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/knapsack_serial.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/knapsack_serial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/knapsack_serial.dir/flags.make

CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.o: CMakeFiles/knapsack_serial.dir/flags.make
CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.o: ../src/knapsack_serial.cpp
CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.o: CMakeFiles/knapsack_serial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.o -MF CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.o.d -o CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.o -c "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/src/knapsack_serial.cpp"

CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/src/knapsack_serial.cpp" > CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.i

CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/src/knapsack_serial.cpp" -o CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.s

# Object files for target knapsack_serial
knapsack_serial_OBJECTS = \
"CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.o"

# External object files for target knapsack_serial
knapsack_serial_EXTERNAL_OBJECTS =

../knapsack_serial: CMakeFiles/knapsack_serial.dir/src/knapsack_serial.cpp.o
../knapsack_serial: CMakeFiles/knapsack_serial.dir/build.make
../knapsack_serial: CMakeFiles/knapsack_serial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../knapsack_serial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/knapsack_serial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/knapsack_serial.dir/build: ../knapsack_serial
.PHONY : CMakeFiles/knapsack_serial.dir/build

CMakeFiles/knapsack_serial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/knapsack_serial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/knapsack_serial.dir/clean

CMakeFiles/knapsack_serial.dir/depend:
	cd "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1" "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1" "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build" "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build" "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build/CMakeFiles/knapsack_serial.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/knapsack_serial.dir/depend

