# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/albin/Documents/client-cpp/example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/albin/Documents/client-cpp/example

# Include any dependencies generated for this target.
include CMakeFiles/example_callback_consumer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example_callback_consumer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example_callback_consumer.dir/flags.make

CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.o: CMakeFiles/example_callback_consumer.dir/flags.make
CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.o: src/example_callback_consumer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/albin/Documents/client-cpp/example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.o -c /home/albin/Documents/client-cpp/example/src/example_callback_consumer.cpp

CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/albin/Documents/client-cpp/example/src/example_callback_consumer.cpp > CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.i

CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/albin/Documents/client-cpp/example/src/example_callback_consumer.cpp -o CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.s

# Object files for target example_callback_consumer
example_callback_consumer_OBJECTS = \
"CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.o"

# External object files for target example_callback_consumer
example_callback_consumer_EXTERNAL_OBJECTS =

bin/example_callback_consumer: CMakeFiles/example_callback_consumer.dir/src/example_callback_consumer.cpp.o
bin/example_callback_consumer: CMakeFiles/example_callback_consumer.dir/build.make
bin/example_callback_consumer: CMakeFiles/example_callback_consumer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/albin/Documents/client-cpp/example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/example_callback_consumer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_callback_consumer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example_callback_consumer.dir/build: bin/example_callback_consumer

.PHONY : CMakeFiles/example_callback_consumer.dir/build

CMakeFiles/example_callback_consumer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example_callback_consumer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example_callback_consumer.dir/clean

CMakeFiles/example_callback_consumer.dir/depend:
	cd /home/albin/Documents/client-cpp/example && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/albin/Documents/client-cpp/example /home/albin/Documents/client-cpp/example /home/albin/Documents/client-cpp/example /home/albin/Documents/client-cpp/example /home/albin/Documents/client-cpp/example/CMakeFiles/example_callback_consumer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example_callback_consumer.dir/depend
