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
CMAKE_SOURCE_DIR = "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build"

# Include any dependencies generated for this target.
include CMakeFiles/ray.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ray.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ray.dir/flags.make

CMakeFiles/ray.dir/Code/image.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/image.cpp.o: ../Code/image.cpp
CMakeFiles/ray.dir/Code/image.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ray.dir/Code/image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/image.cpp.o -MF CMakeFiles/ray.dir/Code/image.cpp.o.d -o CMakeFiles/ray.dir/Code/image.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/image.cpp"

CMakeFiles/ray.dir/Code/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/image.cpp" > CMakeFiles/ray.dir/Code/image.cpp.i

CMakeFiles/ray.dir/Code/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/image.cpp" -o CMakeFiles/ray.dir/Code/image.cpp.s

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o: ../Code/lode/lodepng.cpp
CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o -MF CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.d -o CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/lode/lodepng.cpp"

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/lode/lodepng.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/lode/lodepng.cpp" > CMakeFiles/ray.dir/Code/lode/lodepng.cpp.i

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/lode/lodepng.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/lode/lodepng.cpp" -o CMakeFiles/ray.dir/Code/lode/lodepng.cpp.s

CMakeFiles/ray.dir/Code/main.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/main.cpp.o: ../Code/main.cpp
CMakeFiles/ray.dir/Code/main.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ray.dir/Code/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/main.cpp.o -MF CMakeFiles/ray.dir/Code/main.cpp.o.d -o CMakeFiles/ray.dir/Code/main.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/main.cpp"

CMakeFiles/ray.dir/Code/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/main.cpp" > CMakeFiles/ray.dir/Code/main.cpp.i

CMakeFiles/ray.dir/Code/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/main.cpp" -o CMakeFiles/ray.dir/Code/main.cpp.s

CMakeFiles/ray.dir/Code/objloader.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/objloader.cpp.o: ../Code/objloader.cpp
CMakeFiles/ray.dir/Code/objloader.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ray.dir/Code/objloader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/objloader.cpp.o -MF CMakeFiles/ray.dir/Code/objloader.cpp.o.d -o CMakeFiles/ray.dir/Code/objloader.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/objloader.cpp"

CMakeFiles/ray.dir/Code/objloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/objloader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/objloader.cpp" > CMakeFiles/ray.dir/Code/objloader.cpp.i

CMakeFiles/ray.dir/Code/objloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/objloader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/objloader.cpp" -o CMakeFiles/ray.dir/Code/objloader.cpp.s

CMakeFiles/ray.dir/Code/raytracer.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/raytracer.cpp.o: ../Code/raytracer.cpp
CMakeFiles/ray.dir/Code/raytracer.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ray.dir/Code/raytracer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/raytracer.cpp.o -MF CMakeFiles/ray.dir/Code/raytracer.cpp.o.d -o CMakeFiles/ray.dir/Code/raytracer.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/raytracer.cpp"

CMakeFiles/ray.dir/Code/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/raytracer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/raytracer.cpp" > CMakeFiles/ray.dir/Code/raytracer.cpp.i

CMakeFiles/ray.dir/Code/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/raytracer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/raytracer.cpp" -o CMakeFiles/ray.dir/Code/raytracer.cpp.s

CMakeFiles/ray.dir/Code/scene.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/scene.cpp.o: ../Code/scene.cpp
CMakeFiles/ray.dir/Code/scene.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ray.dir/Code/scene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/scene.cpp.o -MF CMakeFiles/ray.dir/Code/scene.cpp.o.d -o CMakeFiles/ray.dir/Code/scene.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/scene.cpp"

CMakeFiles/ray.dir/Code/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/scene.cpp" > CMakeFiles/ray.dir/Code/scene.cpp.i

CMakeFiles/ray.dir/Code/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/scene.cpp" -o CMakeFiles/ray.dir/Code/scene.cpp.s

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o: ../Code/shapes/cylinder.cpp
CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o -MF CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.d -o CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/cylinder.cpp"

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/cylinder.cpp" > CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.i

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/cylinder.cpp" -o CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.s

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o: ../Code/shapes/mesh.cpp
CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o -MF CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.d -o CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/mesh.cpp"

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/mesh.cpp" > CMakeFiles/ray.dir/Code/shapes/mesh.cpp.i

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/mesh.cpp" -o CMakeFiles/ray.dir/Code/shapes/mesh.cpp.s

CMakeFiles/ray.dir/Code/shapes/quad.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/quad.cpp.o: ../Code/shapes/quad.cpp
CMakeFiles/ray.dir/Code/shapes/quad.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ray.dir/Code/shapes/quad.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/shapes/quad.cpp.o -MF CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.d -o CMakeFiles/ray.dir/Code/shapes/quad.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/quad.cpp"

CMakeFiles/ray.dir/Code/shapes/quad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/quad.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/quad.cpp" > CMakeFiles/ray.dir/Code/shapes/quad.cpp.i

CMakeFiles/ray.dir/Code/shapes/quad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/quad.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/quad.cpp" -o CMakeFiles/ray.dir/Code/shapes/quad.cpp.s

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o: ../Code/shapes/sphere.cpp
CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o -MF CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.d -o CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/sphere.cpp"

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/sphere.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/sphere.cpp" > CMakeFiles/ray.dir/Code/shapes/sphere.cpp.i

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/sphere.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/sphere.cpp" -o CMakeFiles/ray.dir/Code/shapes/sphere.cpp.s

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o: ../Code/shapes/triangle.cpp
CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o -MF CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.d -o CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/triangle.cpp"

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/triangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/triangle.cpp" > CMakeFiles/ray.dir/Code/shapes/triangle.cpp.i

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/triangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/shapes/triangle.cpp" -o CMakeFiles/ray.dir/Code/shapes/triangle.cpp.s

CMakeFiles/ray.dir/Code/triple.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/triple.cpp.o: ../Code/triple.cpp
CMakeFiles/ray.dir/Code/triple.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ray.dir/Code/triple.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/Code/triple.cpp.o -MF CMakeFiles/ray.dir/Code/triple.cpp.o.d -o CMakeFiles/ray.dir/Code/triple.cpp.o -c "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/triple.cpp"

CMakeFiles/ray.dir/Code/triple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/triple.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/triple.cpp" > CMakeFiles/ray.dir/Code/triple.cpp.i

CMakeFiles/ray.dir/Code/triple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/triple.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/Code/triple.cpp" -o CMakeFiles/ray.dir/Code/triple.cpp.s

# Object files for target ray
ray_OBJECTS = \
"CMakeFiles/ray.dir/Code/image.cpp.o" \
"CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o" \
"CMakeFiles/ray.dir/Code/main.cpp.o" \
"CMakeFiles/ray.dir/Code/objloader.cpp.o" \
"CMakeFiles/ray.dir/Code/raytracer.cpp.o" \
"CMakeFiles/ray.dir/Code/scene.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/quad.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o" \
"CMakeFiles/ray.dir/Code/triple.cpp.o"

# External object files for target ray
ray_EXTERNAL_OBJECTS =

ray: CMakeFiles/ray.dir/Code/image.cpp.o
ray: CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o
ray: CMakeFiles/ray.dir/Code/main.cpp.o
ray: CMakeFiles/ray.dir/Code/objloader.cpp.o
ray: CMakeFiles/ray.dir/Code/raytracer.cpp.o
ray: CMakeFiles/ray.dir/Code/scene.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/quad.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o
ray: CMakeFiles/ray.dir/Code/triple.cpp.o
ray: CMakeFiles/ray.dir/build.make
ray: CMakeFiles/ray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable ray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ray.dir/build: ray
.PHONY : CMakeFiles/ray.dir/build

CMakeFiles/ray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ray.dir/clean

CMakeFiles/ray.dir/depend:
	cd "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)" "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)" "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build" "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build" "/mnt/c/Users/rady0/Documents/Computer Graphics/ComputerGraphics/Assignment2/RayTracer_1(3)/build/CMakeFiles/ray.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ray.dir/depend

