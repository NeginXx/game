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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xia/work/game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xia/work/game/build

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/src/Engine.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Engine.cpp.o: ../src/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xia/work/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/src/Engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Engine.cpp.o -c /home/xia/work/game/src/Engine.cpp

CMakeFiles/game.dir/src/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xia/work/game/src/Engine.cpp > CMakeFiles/game.dir/src/Engine.cpp.i

CMakeFiles/game.dir/src/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xia/work/game/src/Engine.cpp -o CMakeFiles/game.dir/src/Engine.cpp.s

CMakeFiles/game.dir/src/Event.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Event.cpp.o: ../src/Event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xia/work/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/src/Event.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Event.cpp.o -c /home/xia/work/game/src/Event.cpp

CMakeFiles/game.dir/src/Event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Event.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xia/work/game/src/Event.cpp > CMakeFiles/game.dir/src/Event.cpp.i

CMakeFiles/game.dir/src/Event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Event.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xia/work/game/src/Event.cpp -o CMakeFiles/game.dir/src/Event.cpp.s

CMakeFiles/game.dir/src/Game.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xia/work/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/src/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Game.cpp.o -c /home/xia/work/game/src/Game.cpp

CMakeFiles/game.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xia/work/game/src/Game.cpp > CMakeFiles/game.dir/src/Game.cpp.i

CMakeFiles/game.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xia/work/game/src/Game.cpp -o CMakeFiles/game.dir/src/Game.cpp.s

CMakeFiles/game.dir/src/MainScene.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/MainScene.cpp.o: ../src/MainScene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xia/work/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/src/MainScene.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/MainScene.cpp.o -c /home/xia/work/game/src/MainScene.cpp

CMakeFiles/game.dir/src/MainScene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/MainScene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xia/work/game/src/MainScene.cpp > CMakeFiles/game.dir/src/MainScene.cpp.i

CMakeFiles/game.dir/src/MainScene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/MainScene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xia/work/game/src/MainScene.cpp -o CMakeFiles/game.dir/src/MainScene.cpp.s

CMakeFiles/game.dir/src/Physics.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Physics.cpp.o: ../src/Physics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xia/work/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/src/Physics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Physics.cpp.o -c /home/xia/work/game/src/Physics.cpp

CMakeFiles/game.dir/src/Physics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Physics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xia/work/game/src/Physics.cpp > CMakeFiles/game.dir/src/Physics.cpp.i

CMakeFiles/game.dir/src/Physics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Physics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xia/work/game/src/Physics.cpp -o CMakeFiles/game.dir/src/Physics.cpp.s

CMakeFiles/game.dir/src/Renderer.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Renderer.cpp.o: ../src/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xia/work/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/src/Renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Renderer.cpp.o -c /home/xia/work/game/src/Renderer.cpp

CMakeFiles/game.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xia/work/game/src/Renderer.cpp > CMakeFiles/game.dir/src/Renderer.cpp.i

CMakeFiles/game.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xia/work/game/src/Renderer.cpp -o CMakeFiles/game.dir/src/Renderer.cpp.s

CMakeFiles/game.dir/src/SceneRenderer.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/SceneRenderer.cpp.o: ../src/SceneRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xia/work/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/src/SceneRenderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/SceneRenderer.cpp.o -c /home/xia/work/game/src/SceneRenderer.cpp

CMakeFiles/game.dir/src/SceneRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/SceneRenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xia/work/game/src/SceneRenderer.cpp > CMakeFiles/game.dir/src/SceneRenderer.cpp.i

CMakeFiles/game.dir/src/SceneRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/SceneRenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xia/work/game/src/SceneRenderer.cpp -o CMakeFiles/game.dir/src/SceneRenderer.cpp.s

CMakeFiles/game.dir/src/Shape.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Shape.cpp.o: ../src/Shape.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xia/work/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/game.dir/src/Shape.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Shape.cpp.o -c /home/xia/work/game/src/Shape.cpp

CMakeFiles/game.dir/src/Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Shape.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xia/work/game/src/Shape.cpp > CMakeFiles/game.dir/src/Shape.cpp.i

CMakeFiles/game.dir/src/Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Shape.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xia/work/game/src/Shape.cpp -o CMakeFiles/game.dir/src/Shape.cpp.s

CMakeFiles/game.dir/src/Vec2.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Vec2.cpp.o: ../src/Vec2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xia/work/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/game.dir/src/Vec2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Vec2.cpp.o -c /home/xia/work/game/src/Vec2.cpp

CMakeFiles/game.dir/src/Vec2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Vec2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xia/work/game/src/Vec2.cpp > CMakeFiles/game.dir/src/Vec2.cpp.i

CMakeFiles/game.dir/src/Vec2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Vec2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xia/work/game/src/Vec2.cpp -o CMakeFiles/game.dir/src/Vec2.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/src/Engine.cpp.o" \
"CMakeFiles/game.dir/src/Event.cpp.o" \
"CMakeFiles/game.dir/src/Game.cpp.o" \
"CMakeFiles/game.dir/src/MainScene.cpp.o" \
"CMakeFiles/game.dir/src/Physics.cpp.o" \
"CMakeFiles/game.dir/src/Renderer.cpp.o" \
"CMakeFiles/game.dir/src/SceneRenderer.cpp.o" \
"CMakeFiles/game.dir/src/Shape.cpp.o" \
"CMakeFiles/game.dir/src/Vec2.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/src/Engine.cpp.o
game: CMakeFiles/game.dir/src/Event.cpp.o
game: CMakeFiles/game.dir/src/Game.cpp.o
game: CMakeFiles/game.dir/src/MainScene.cpp.o
game: CMakeFiles/game.dir/src/Physics.cpp.o
game: CMakeFiles/game.dir/src/Renderer.cpp.o
game: CMakeFiles/game.dir/src/SceneRenderer.cpp.o
game: CMakeFiles/game.dir/src/Shape.cpp.o
game: CMakeFiles/game.dir/src/Vec2.cpp.o
game: CMakeFiles/game.dir/build.make
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xia/work/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/xia/work/game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xia/work/game /home/xia/work/game /home/xia/work/game/build /home/xia/work/game/build /home/xia/work/game/build/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

