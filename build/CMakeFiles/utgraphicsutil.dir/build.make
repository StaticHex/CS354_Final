# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final/build"

# Include any dependencies generated for this target.
include CMakeFiles/utgraphicsutil.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/utgraphicsutil.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/utgraphicsutil.dir/flags.make

CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o: CMakeFiles/utgraphicsutil.dir/flags.make
CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o: ../lib/debuggl.cc
	$(CMAKE_COMMAND) -E cmake_progress_report "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o"
	/lusr/opt/gcc-5.2.0/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o -c "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final/lib/debuggl.cc"

CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.i"
	/lusr/opt/gcc-5.2.0/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final/lib/debuggl.cc" > CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.i

CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.s"
	/lusr/opt/gcc-5.2.0/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final/lib/debuggl.cc" -o CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.s

CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o.requires:
.PHONY : CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o.requires

CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o.provides: CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o.requires
	$(MAKE) -f CMakeFiles/utgraphicsutil.dir/build.make CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o.provides.build
.PHONY : CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o.provides

CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o.provides.build: CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o

# Object files for target utgraphicsutil
utgraphicsutil_OBJECTS = \
"CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o"

# External object files for target utgraphicsutil
utgraphicsutil_EXTERNAL_OBJECTS =

libutgraphicsutil.so: CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o
libutgraphicsutil.so: CMakeFiles/utgraphicsutil.dir/build.make
libutgraphicsutil.so: /usr/lib/x86_64-linux-gnu/libGLEW.so
libutgraphicsutil.so: CMakeFiles/utgraphicsutil.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libutgraphicsutil.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utgraphicsutil.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/utgraphicsutil.dir/build: libutgraphicsutil.so
.PHONY : CMakeFiles/utgraphicsutil.dir/build

CMakeFiles/utgraphicsutil.dir/requires: CMakeFiles/utgraphicsutil.dir/lib/debuggl.cc.o.requires
.PHONY : CMakeFiles/utgraphicsutil.dir/requires

CMakeFiles/utgraphicsutil.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/utgraphicsutil.dir/cmake_clean.cmake
.PHONY : CMakeFiles/utgraphicsutil.dir/clean

CMakeFiles/utgraphicsutil.dir/depend:
	cd "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final" "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final" "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final/build" "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final/build" "/v/filer4b/v38q001/joeldavi/CS354/Final Graphics Project/CS354_Final/build/CMakeFiles/utgraphicsutil.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/utgraphicsutil.dir/depend

