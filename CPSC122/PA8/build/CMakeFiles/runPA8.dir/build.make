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
CMAKE_SOURCE_DIR = /Users/frolower/Desktop/Code/GU/pa8-Frolower

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/frolower/Desktop/Code/GU/pa8-Frolower/build

# Include any dependencies generated for this target.
include CMakeFiles/runPA8.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/runPA8.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/runPA8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runPA8.dir/flags.make

CMakeFiles/runPA8.dir/Main.cpp.o: CMakeFiles/runPA8.dir/flags.make
CMakeFiles/runPA8.dir/Main.cpp.o: /Users/frolower/Desktop/Code/GU/pa8-Frolower/Main.cpp
CMakeFiles/runPA8.dir/Main.cpp.o: CMakeFiles/runPA8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frolower/Desktop/Code/GU/pa8-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runPA8.dir/Main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runPA8.dir/Main.cpp.o -MF CMakeFiles/runPA8.dir/Main.cpp.o.d -o CMakeFiles/runPA8.dir/Main.cpp.o -c /Users/frolower/Desktop/Code/GU/pa8-Frolower/Main.cpp

CMakeFiles/runPA8.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPA8.dir/Main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frolower/Desktop/Code/GU/pa8-Frolower/Main.cpp > CMakeFiles/runPA8.dir/Main.cpp.i

CMakeFiles/runPA8.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPA8.dir/Main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frolower/Desktop/Code/GU/pa8-Frolower/Main.cpp -o CMakeFiles/runPA8.dir/Main.cpp.s

CMakeFiles/runPA8.dir/PA8.cpp.o: CMakeFiles/runPA8.dir/flags.make
CMakeFiles/runPA8.dir/PA8.cpp.o: /Users/frolower/Desktop/Code/GU/pa8-Frolower/PA8.cpp
CMakeFiles/runPA8.dir/PA8.cpp.o: CMakeFiles/runPA8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frolower/Desktop/Code/GU/pa8-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runPA8.dir/PA8.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runPA8.dir/PA8.cpp.o -MF CMakeFiles/runPA8.dir/PA8.cpp.o.d -o CMakeFiles/runPA8.dir/PA8.cpp.o -c /Users/frolower/Desktop/Code/GU/pa8-Frolower/PA8.cpp

CMakeFiles/runPA8.dir/PA8.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPA8.dir/PA8.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frolower/Desktop/Code/GU/pa8-Frolower/PA8.cpp > CMakeFiles/runPA8.dir/PA8.cpp.i

CMakeFiles/runPA8.dir/PA8.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPA8.dir/PA8.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frolower/Desktop/Code/GU/pa8-Frolower/PA8.cpp -o CMakeFiles/runPA8.dir/PA8.cpp.s

CMakeFiles/runPA8.dir/Sieve.cpp.o: CMakeFiles/runPA8.dir/flags.make
CMakeFiles/runPA8.dir/Sieve.cpp.o: /Users/frolower/Desktop/Code/GU/pa8-Frolower/Sieve.cpp
CMakeFiles/runPA8.dir/Sieve.cpp.o: CMakeFiles/runPA8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frolower/Desktop/Code/GU/pa8-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/runPA8.dir/Sieve.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runPA8.dir/Sieve.cpp.o -MF CMakeFiles/runPA8.dir/Sieve.cpp.o.d -o CMakeFiles/runPA8.dir/Sieve.cpp.o -c /Users/frolower/Desktop/Code/GU/pa8-Frolower/Sieve.cpp

CMakeFiles/runPA8.dir/Sieve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPA8.dir/Sieve.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frolower/Desktop/Code/GU/pa8-Frolower/Sieve.cpp > CMakeFiles/runPA8.dir/Sieve.cpp.i

CMakeFiles/runPA8.dir/Sieve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPA8.dir/Sieve.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frolower/Desktop/Code/GU/pa8-Frolower/Sieve.cpp -o CMakeFiles/runPA8.dir/Sieve.cpp.s

CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.o: CMakeFiles/runPA8.dir/flags.make
CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.o: /Users/frolower/Desktop/Code/GU/pa8-Frolower/DoublyLinkedList.cpp
CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.o: CMakeFiles/runPA8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frolower/Desktop/Code/GU/pa8-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.o -MF CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.o.d -o CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.o -c /Users/frolower/Desktop/Code/GU/pa8-Frolower/DoublyLinkedList.cpp

CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frolower/Desktop/Code/GU/pa8-Frolower/DoublyLinkedList.cpp > CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.i

CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frolower/Desktop/Code/GU/pa8-Frolower/DoublyLinkedList.cpp -o CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.s

CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.o: CMakeFiles/runPA8.dir/flags.make
CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.o: /Users/frolower/Desktop/Code/GU/pa8-Frolower/DoublyLinkedQueue.cpp
CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.o: CMakeFiles/runPA8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frolower/Desktop/Code/GU/pa8-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.o -MF CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.o.d -o CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.o -c /Users/frolower/Desktop/Code/GU/pa8-Frolower/DoublyLinkedQueue.cpp

CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frolower/Desktop/Code/GU/pa8-Frolower/DoublyLinkedQueue.cpp > CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.i

CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frolower/Desktop/Code/GU/pa8-Frolower/DoublyLinkedQueue.cpp -o CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.s

# Object files for target runPA8
runPA8_OBJECTS = \
"CMakeFiles/runPA8.dir/Main.cpp.o" \
"CMakeFiles/runPA8.dir/PA8.cpp.o" \
"CMakeFiles/runPA8.dir/Sieve.cpp.o" \
"CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.o" \
"CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.o"

# External object files for target runPA8
runPA8_EXTERNAL_OBJECTS =

runPA8: CMakeFiles/runPA8.dir/Main.cpp.o
runPA8: CMakeFiles/runPA8.dir/PA8.cpp.o
runPA8: CMakeFiles/runPA8.dir/Sieve.cpp.o
runPA8: CMakeFiles/runPA8.dir/DoublyLinkedList.cpp.o
runPA8: CMakeFiles/runPA8.dir/DoublyLinkedQueue.cpp.o
runPA8: CMakeFiles/runPA8.dir/build.make
runPA8: CMakeFiles/runPA8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/frolower/Desktop/Code/GU/pa8-Frolower/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable runPA8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runPA8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runPA8.dir/build: runPA8
.PHONY : CMakeFiles/runPA8.dir/build

CMakeFiles/runPA8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runPA8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runPA8.dir/clean

CMakeFiles/runPA8.dir/depend:
	cd /Users/frolower/Desktop/Code/GU/pa8-Frolower/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/frolower/Desktop/Code/GU/pa8-Frolower /Users/frolower/Desktop/Code/GU/pa8-Frolower /Users/frolower/Desktop/Code/GU/pa8-Frolower/build /Users/frolower/Desktop/Code/GU/pa8-Frolower/build /Users/frolower/Desktop/Code/GU/pa8-Frolower/build/CMakeFiles/runPA8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runPA8.dir/depend

