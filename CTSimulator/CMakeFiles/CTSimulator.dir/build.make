# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/verobuckina/Downloads/clion-2020.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/verobuckina/Downloads/clion-2020.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator

# Include any dependencies generated for this target.
include CMakeFiles/CTSimulator.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CTSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CTSimulator.dir/flags.make

CMakeFiles/CTSimulator.dir/main.cpp.o: CMakeFiles/CTSimulator.dir/flags.make
CMakeFiles/CTSimulator.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CTSimulator.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CTSimulator.dir/main.cpp.o -c /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/main.cpp

CMakeFiles/CTSimulator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CTSimulator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/main.cpp > CMakeFiles/CTSimulator.dir/main.cpp.i

CMakeFiles/CTSimulator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CTSimulator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/main.cpp -o CMakeFiles/CTSimulator.dir/main.cpp.s

CMakeFiles/CTSimulator.dir/Kernels.cpp.o: CMakeFiles/CTSimulator.dir/flags.make
CMakeFiles/CTSimulator.dir/Kernels.cpp.o: Kernels.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CTSimulator.dir/Kernels.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CTSimulator.dir/Kernels.cpp.o -c /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/Kernels.cpp

CMakeFiles/CTSimulator.dir/Kernels.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CTSimulator.dir/Kernels.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/Kernels.cpp > CMakeFiles/CTSimulator.dir/Kernels.cpp.i

CMakeFiles/CTSimulator.dir/Kernels.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CTSimulator.dir/Kernels.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/Kernels.cpp -o CMakeFiles/CTSimulator.dir/Kernels.cpp.s

CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.o: CMakeFiles/CTSimulator.dir/flags.make
CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.o: ForwardProjection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.o -c /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/ForwardProjection.cpp

CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/ForwardProjection.cpp > CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.i

CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/ForwardProjection.cpp -o CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.s

# Object files for target CTSimulator
CTSimulator_OBJECTS = \
"CMakeFiles/CTSimulator.dir/main.cpp.o" \
"CMakeFiles/CTSimulator.dir/Kernels.cpp.o" \
"CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.o"

# External object files for target CTSimulator
CTSimulator_EXTERNAL_OBJECTS =

CTSimulator: CMakeFiles/CTSimulator.dir/main.cpp.o
CTSimulator: CMakeFiles/CTSimulator.dir/Kernels.cpp.o
CTSimulator: CMakeFiles/CTSimulator.dir/ForwardProjection.cpp.o
CTSimulator: CMakeFiles/CTSimulator.dir/build.make
CTSimulator: /usr/local/lib/libopencv_gapi.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_highgui.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_ml.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_objdetect.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_photo.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_stitching.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_video.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_videoio.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_dnn.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_imgcodecs.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_calib3d.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_features2d.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_flann.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_imgproc.so.4.5.3
CTSimulator: /usr/local/lib/libopencv_core.so.4.5.3
CTSimulator: CMakeFiles/CTSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CTSimulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CTSimulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CTSimulator.dir/build: CTSimulator
.PHONY : CMakeFiles/CTSimulator.dir/build

CMakeFiles/CTSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CTSimulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CTSimulator.dir/clean

CMakeFiles/CTSimulator.dir/depend:
	cd /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator /media/verobuckina/Shared-Volume/Projects/CTSimulator/CTSimulator/CMakeFiles/CTSimulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CTSimulator.dir/depend

