# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_SOURCE_DIR = /home/fahreevr/Projects/MyReddis/hseos_sample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fahreevr/Projects/MyReddis/hseos_sample/build

# Include any dependencies generated for this target.
include CMakeFiles/redis-server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/redis-server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/redis-server.dir/flags.make

CMakeFiles/redis-server.dir/main.cpp.o: CMakeFiles/redis-server.dir/flags.make
CMakeFiles/redis-server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fahreevr/Projects/MyReddis/hseos_sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/redis-server.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/redis-server.dir/main.cpp.o -c /home/fahreevr/Projects/MyReddis/hseos_sample/main.cpp

CMakeFiles/redis-server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redis-server.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/fahreevr/Projects/MyReddis/hseos_sample/main.cpp > CMakeFiles/redis-server.dir/main.cpp.i

CMakeFiles/redis-server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redis-server.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/fahreevr/Projects/MyReddis/hseos_sample/main.cpp -o CMakeFiles/redis-server.dir/main.cpp.s

CMakeFiles/redis-server.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/redis-server.dir/main.cpp.o.requires

CMakeFiles/redis-server.dir/main.cpp.o.provides: CMakeFiles/redis-server.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/redis-server.dir/build.make CMakeFiles/redis-server.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/redis-server.dir/main.cpp.o.provides

CMakeFiles/redis-server.dir/main.cpp.o.provides.build: CMakeFiles/redis-server.dir/main.cpp.o


CMakeFiles/redis-server.dir/redis.cpp.o: CMakeFiles/redis-server.dir/flags.make
CMakeFiles/redis-server.dir/redis.cpp.o: ../redis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fahreevr/Projects/MyReddis/hseos_sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/redis-server.dir/redis.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/redis-server.dir/redis.cpp.o -c /home/fahreevr/Projects/MyReddis/hseos_sample/redis.cpp

CMakeFiles/redis-server.dir/redis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redis-server.dir/redis.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/fahreevr/Projects/MyReddis/hseos_sample/redis.cpp > CMakeFiles/redis-server.dir/redis.cpp.i

CMakeFiles/redis-server.dir/redis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redis-server.dir/redis.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/fahreevr/Projects/MyReddis/hseos_sample/redis.cpp -o CMakeFiles/redis-server.dir/redis.cpp.s

CMakeFiles/redis-server.dir/redis.cpp.o.requires:

.PHONY : CMakeFiles/redis-server.dir/redis.cpp.o.requires

CMakeFiles/redis-server.dir/redis.cpp.o.provides: CMakeFiles/redis-server.dir/redis.cpp.o.requires
	$(MAKE) -f CMakeFiles/redis-server.dir/build.make CMakeFiles/redis-server.dir/redis.cpp.o.provides.build
.PHONY : CMakeFiles/redis-server.dir/redis.cpp.o.provides

CMakeFiles/redis-server.dir/redis.cpp.o.provides.build: CMakeFiles/redis-server.dir/redis.cpp.o


# Object files for target redis-server
redis__server_OBJECTS = \
"CMakeFiles/redis-server.dir/main.cpp.o" \
"CMakeFiles/redis-server.dir/redis.cpp.o"

# External object files for target redis-server
redis__server_EXTERNAL_OBJECTS =

redis-server: CMakeFiles/redis-server.dir/main.cpp.o
redis-server: CMakeFiles/redis-server.dir/redis.cpp.o
redis-server: CMakeFiles/redis-server.dir/build.make
redis-server: CMakeFiles/redis-server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fahreevr/Projects/MyReddis/hseos_sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable redis-server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/redis-server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/redis-server.dir/build: redis-server

.PHONY : CMakeFiles/redis-server.dir/build

CMakeFiles/redis-server.dir/requires: CMakeFiles/redis-server.dir/main.cpp.o.requires
CMakeFiles/redis-server.dir/requires: CMakeFiles/redis-server.dir/redis.cpp.o.requires

.PHONY : CMakeFiles/redis-server.dir/requires

CMakeFiles/redis-server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/redis-server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/redis-server.dir/clean

CMakeFiles/redis-server.dir/depend:
	cd /home/fahreevr/Projects/MyReddis/hseos_sample/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fahreevr/Projects/MyReddis/hseos_sample /home/fahreevr/Projects/MyReddis/hseos_sample /home/fahreevr/Projects/MyReddis/hseos_sample/build /home/fahreevr/Projects/MyReddis/hseos_sample/build /home/fahreevr/Projects/MyReddis/hseos_sample/build/CMakeFiles/redis-server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/redis-server.dir/depend

