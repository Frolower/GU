# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/frolower/Desktop/Code/GU/pa7-Frolower

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/frolower/Desktop/Code/GU/pa7-Frolower/build

# Include any dependencies generated for this target.
include CMakeFiles/runPA7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/runPA7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/runPA7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runPA7.dir/flags.make

CMakeFiles/runPA7.dir/Main.cpp.o: CMakeFiles/runPA7.dir/flags.make
CMakeFiles/runPA7.dir/Main.cpp.o: /Users/frolower/Desktop/Code/GU/pa7-Frolower/Main.cpp
CMakeFiles/runPA7.dir/Main.cpp.o: CMakeFiles/runPA7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frolower/Desktop/Code/GU/pa7-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runPA7.dir/Main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runPA7.dir/Main.cpp.o -MF CMakeFiles/runPA7.dir/Main.cpp.o.d -o CMakeFiles/runPA7.dir/Main.cpp.o -c /Users/frolower/Desktop/Code/GU/pa7-Frolower/Main.cpp

CMakeFiles/runPA7.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPA7.dir/Main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frolower/Desktop/Code/GU/pa7-Frolower/Main.cpp > CMakeFiles/runPA7.dir/Main.cpp.i

CMakeFiles/runPA7.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPA7.dir/Main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frolower/Desktop/Code/GU/pa7-Frolower/Main.cpp -o CMakeFiles/runPA7.dir/Main.cpp.s

CMakeFiles/runPA7.dir/PA7.cpp.o: CMakeFiles/runPA7.dir/flags.make
CMakeFiles/runPA7.dir/PA7.cpp.o: /Users/frolower/Desktop/Code/GU/pa7-Frolower/PA7.cpp
CMakeFiles/runPA7.dir/PA7.cpp.o: CMakeFiles/runPA7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frolower/Desktop/Code/GU/pa7-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runPA7.dir/PA7.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runPA7.dir/PA7.cpp.o -MF CMakeFiles/runPA7.dir/PA7.cpp.o.d -o CMakeFiles/runPA7.dir/PA7.cpp.o -c /Users/frolower/Desktop/Code/GU/pa7-Frolower/PA7.cpp

CMakeFiles/runPA7.dir/PA7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPA7.dir/PA7.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frolower/Desktop/Code/GU/pa7-Frolower/PA7.cpp > CMakeFiles/runPA7.dir/PA7.cpp.i

CMakeFiles/runPA7.dir/PA7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPA7.dir/PA7.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frolower/Desktop/Code/GU/pa7-Frolower/PA7.cpp -o CMakeFiles/runPA7.dir/PA7.cpp.s

CMakeFiles/runPA7.dir/LinkedList.cpp.o: CMakeFiles/runPA7.dir/flags.make
CMakeFiles/runPA7.dir/LinkedList.cpp.o: /Users/frolower/Desktop/Code/GU/pa7-Frolower/LinkedList.cpp
CMakeFiles/runPA7.dir/LinkedList.cpp.o: CMakeFiles/runPA7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frolower/Desktop/Code/GU/pa7-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/runPA7.dir/LinkedList.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runPA7.dir/LinkedList.cpp.o -MF CMakeFiles/runPA7.dir/LinkedList.cpp.o.d -o CMakeFiles/runPA7.dir/LinkedList.cpp.o -c /Users/frolower/Desktop/Code/GU/pa7-Frolower/LinkedList.cpp

CMakeFiles/runPA7.dir/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPA7.dir/LinkedList.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frolower/Desktop/Code/GU/pa7-Frolower/LinkedList.cpp > CMakeFiles/runPA7.dir/LinkedList.cpp.i

CMakeFiles/runPA7.dir/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPA7.dir/LinkedList.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frolower/Desktop/Code/GU/pa7-Frolower/LinkedList.cpp -o CMakeFiles/runPA7.dir/LinkedList.cpp.s

CMakeFiles/runPA7.dir/Stack.cpp.o: CMakeFiles/runPA7.dir/flags.make
CMakeFiles/runPA7.dir/Stack.cpp.o: /Users/frolower/Desktop/Code/GU/pa7-Frolower/Stack.cpp
CMakeFiles/runPA7.dir/Stack.cpp.o: CMakeFiles/runPA7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frolower/Desktop/Code/GU/pa7-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/runPA7.dir/Stack.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runPA7.dir/Stack.cpp.o -MF CMakeFiles/runPA7.dir/Stack.cpp.o.d -o CMakeFiles/runPA7.dir/Stack.cpp.o -c /Users/frolower/Desktop/Code/GU/pa7-Frolower/Stack.cpp

CMakeFiles/runPA7.dir/Stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPA7.dir/Stack.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frolower/Desktop/Code/GU/pa7-Frolower/Stack.cpp > CMakeFiles/runPA7.dir/Stack.cpp.i

CMakeFiles/runPA7.dir/Stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPA7.dir/Stack.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frolower/Desktop/Code/GU/pa7-Frolower/Stack.cpp -o CMakeFiles/runPA7.dir/Stack.cpp.s

CMakeFiles/runPA7.dir/Calculator.cpp.o: CMakeFiles/runPA7.dir/flags.make
CMakeFiles/runPA7.dir/Calculator.cpp.o: /Users/frolower/Desktop/Code/GU/pa7-Frolower/Calculator.cpp
CMakeFiles/runPA7.dir/Calculator.cpp.o: CMakeFiles/runPA7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frolower/Desktop/Code/GU/pa7-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/runPA7.dir/Calculator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runPA7.dir/Calculator.cpp.o -MF CMakeFiles/runPA7.dir/Calculator.cpp.o.d -o CMakeFiles/runPA7.dir/Calculator.cpp.o -c /Users/frolower/Desktop/Code/GU/pa7-Frolower/Calculator.cpp

CMakeFiles/runPA7.dir/Calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPA7.dir/Calculator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frolower/Desktop/Code/GU/pa7-Frolower/Calculator.cpp > CMakeFiles/runPA7.dir/Calculator.cpp.i

CMakeFiles/runPA7.dir/Calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPA7.dir/Calculator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frolower/Desktop/Code/GU/pa7-Frolower/Calculator.cpp -o CMakeFiles/runPA7.dir/Calculator.cpp.s

# Object files for target runPA7
runPA7_OBJECTS = \
"CMakeFiles/runPA7.dir/Main.cpp.o" \
"CMakeFiles/runPA7.dir/PA7.cpp.o" \
"CMakeFiles/runPA7.dir/LinkedList.cpp.o" \
"CMakeFiles/runPA7.dir/Stack.cpp.o" \
"CMakeFiles/runPA7.dir/Calculator.cpp.o"

# External object files for target runPA7
runPA7_EXTERNAL_OBJECTS =

runPA7: CMakeFiles/runPA7.dir/Main.cpp.o
runPA7: CMakeFiles/runPA7.dir/PA7.cpp.o
runPA7: CMakeFiles/runPA7.dir/LinkedList.cpp.o
runPA7: CMakeFiles/runPA7.dir/Stack.cpp.o
runPA7: CMakeFiles/runPA7.dir/Calculator.cpp.o
runPA7: CMakeFiles/runPA7.dir/build.make
runPA7: CMakeFiles/runPA7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/frolower/Desktop/Code/GU/pa7-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable runPA7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runPA7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runPA7.dir/build: runPA7
.PHONY : CMakeFiles/runPA7.dir/build

CMakeFiles/runPA7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runPA7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runPA7.dir/clean

CMakeFiles/runPA7.dir/depend:
	cd /Users/frolower/Desktop/Code/GU/pa7-Frolower/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/frolower/Desktop/Code/GU/pa7-Frolower /Users/frolower/Desktop/Code/GU/pa7-Frolower /Users/frolower/Desktop/Code/GU/pa7-Frolower/build /Users/frolower/Desktop/Code/GU/pa7-Frolower/build /Users/frolower/Desktop/Code/GU/pa7-Frolower/build/CMakeFiles/runPA7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runPA7.dir/depend

