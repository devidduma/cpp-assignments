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
CMAKE_COMMAND = /home/devidduma/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/devidduma/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/frequencyOfWords.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/frequencyOfWords.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/frequencyOfWords.dir/flags.make

CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.o: CMakeFiles/frequencyOfWords.dir/flags.make
CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.o: ../frequencyOfWords.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.o -c "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6/frequencyOfWords.cpp"

CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6/frequencyOfWords.cpp" > CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.i

CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6/frequencyOfWords.cpp" -o CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.s

# Object files for target frequencyOfWords
frequencyOfWords_OBJECTS = \
"CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.o"

# External object files for target frequencyOfWords
frequencyOfWords_EXTERNAL_OBJECTS =

frequencyOfWords: CMakeFiles/frequencyOfWords.dir/frequencyOfWords.cpp.o
frequencyOfWords: CMakeFiles/frequencyOfWords.dir/build.make
frequencyOfWords: CMakeFiles/frequencyOfWords.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable frequencyOfWords"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/frequencyOfWords.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/frequencyOfWords.dir/build: frequencyOfWords

.PHONY : CMakeFiles/frequencyOfWords.dir/build

CMakeFiles/frequencyOfWords.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/frequencyOfWords.dir/cmake_clean.cmake
.PHONY : CMakeFiles/frequencyOfWords.dir/clean

CMakeFiles/frequencyOfWords.dir/depend:
	cd "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6" "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6" "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6/cmake-build-debug" "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6/cmake-build-debug" "/home/devidduma/MEGA/Epoka University/Second Semester SS20/C Programming/Assignment 6/cmake-build-debug/CMakeFiles/frequencyOfWords.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/frequencyOfWords.dir/depend

