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
include CMakeFiles/serial_results.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/serial_results.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/serial_results.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serial_results.dir/flags.make

CMakeFiles/serial_results.dir/output/serial_results.cpp.o: CMakeFiles/serial_results.dir/flags.make
CMakeFiles/serial_results.dir/output/serial_results.cpp.o: ../output/serial_results.cpp
CMakeFiles/serial_results.dir/output/serial_results.cpp.o: CMakeFiles/serial_results.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serial_results.dir/output/serial_results.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serial_results.dir/output/serial_results.cpp.o -MF CMakeFiles/serial_results.dir/output/serial_results.cpp.o.d -o CMakeFiles/serial_results.dir/output/serial_results.cpp.o -c "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/output/serial_results.cpp"

CMakeFiles/serial_results.dir/output/serial_results.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial_results.dir/output/serial_results.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/output/serial_results.cpp" > CMakeFiles/serial_results.dir/output/serial_results.cpp.i

CMakeFiles/serial_results.dir/output/serial_results.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial_results.dir/output/serial_results.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/output/serial_results.cpp" -o CMakeFiles/serial_results.dir/output/serial_results.cpp.s

# Object files for target serial_results
serial_results_OBJECTS = \
"CMakeFiles/serial_results.dir/output/serial_results.cpp.o"

# External object files for target serial_results
serial_results_EXTERNAL_OBJECTS =

../serial_results: CMakeFiles/serial_results.dir/output/serial_results.cpp.o
../serial_results: CMakeFiles/serial_results.dir/build.make
../serial_results: CMakeFiles/serial_results.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../serial_results"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial_results.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serial_results.dir/build: ../serial_results
.PHONY : CMakeFiles/serial_results.dir/build

CMakeFiles/serial_results.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serial_results.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serial_results.dir/clean

CMakeFiles/serial_results.dir/depend:
	cd "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1" "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1" "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build" "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build" "/home/aaroneponymous/Aaron's Folder/University/Semesters/spring_2024/assignment_1/build/CMakeFiles/serial_results.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/serial_results.dir/depend

