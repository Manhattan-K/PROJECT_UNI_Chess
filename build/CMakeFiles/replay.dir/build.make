# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build"

# Include any dependencies generated for this target.
include CMakeFiles/replay.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/replay.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/replay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/replay.dir/flags.make

CMakeFiles/replay.dir/src/Replay.cpp.obj: CMakeFiles/replay.dir/flags.make
CMakeFiles/replay.dir/src/Replay.cpp.obj: CMakeFiles/replay.dir/includes_CXX.rsp
CMakeFiles/replay.dir/src/Replay.cpp.obj: D:/Utente/PROGETTO\ FINALE/PROJECT_UNI_Chess/Project_Files/src/Replay.cpp
CMakeFiles/replay.dir/src/Replay.cpp.obj: CMakeFiles/replay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/replay.dir/src/Replay.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/replay.dir/src/Replay.cpp.obj -MF CMakeFiles\replay.dir\src\Replay.cpp.obj.d -o CMakeFiles\replay.dir\src\Replay.cpp.obj -c "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files\src\Replay.cpp"

CMakeFiles/replay.dir/src/Replay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/replay.dir/src/Replay.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files\src\Replay.cpp" > CMakeFiles\replay.dir\src\Replay.cpp.i

CMakeFiles/replay.dir/src/Replay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/replay.dir/src/Replay.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files\src\Replay.cpp" -o CMakeFiles\replay.dir\src\Replay.cpp.s

# Object files for target replay
replay_OBJECTS = \
"CMakeFiles/replay.dir/src/Replay.cpp.obj"

# External object files for target replay
replay_EXTERNAL_OBJECTS =

replay.exe: CMakeFiles/replay.dir/src/Replay.cpp.obj
replay.exe: CMakeFiles/replay.dir/build.make
replay.exe: libChessLib.a
replay.exe: CMakeFiles/replay.dir/linklibs.rsp
replay.exe: CMakeFiles/replay.dir/objects1.rsp
replay.exe: CMakeFiles/replay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable replay.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\replay.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/replay.dir/build: replay.exe
.PHONY : CMakeFiles/replay.dir/build

CMakeFiles/replay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\replay.dir\cmake_clean.cmake
.PHONY : CMakeFiles/replay.dir/clean

CMakeFiles/replay.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files" "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files" "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build" "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build" "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build\CMakeFiles\replay.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/replay.dir/depend

