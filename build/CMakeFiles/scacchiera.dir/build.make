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
include CMakeFiles/scacchiera.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/scacchiera.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/scacchiera.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scacchiera.dir/flags.make

CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.obj: CMakeFiles/scacchiera.dir/flags.make
CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.obj: CMakeFiles/scacchiera.dir/includes_CXX.rsp
CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.obj: D:/Utente/PROGETTO\ FINALE/PROJECT_UNI_Chess/Project_Files/src/Scacchiera.cpp
CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.obj: CMakeFiles/scacchiera.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.obj -MF CMakeFiles\scacchiera.dir\src\Scacchiera.cpp.obj.d -o CMakeFiles\scacchiera.dir\src\Scacchiera.cpp.obj -c "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files\src\Scacchiera.cpp"

CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files\src\Scacchiera.cpp" > CMakeFiles\scacchiera.dir\src\Scacchiera.cpp.i

CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files\src\Scacchiera.cpp" -o CMakeFiles\scacchiera.dir\src\Scacchiera.cpp.s

# Object files for target scacchiera
scacchiera_OBJECTS = \
"CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.obj"

# External object files for target scacchiera
scacchiera_EXTERNAL_OBJECTS =

scacchiera.exe: CMakeFiles/scacchiera.dir/src/Scacchiera.cpp.obj
scacchiera.exe: CMakeFiles/scacchiera.dir/build.make
scacchiera.exe: libChessLib.a
scacchiera.exe: CMakeFiles/scacchiera.dir/linklibs.rsp
scacchiera.exe: CMakeFiles/scacchiera.dir/objects1.rsp
scacchiera.exe: CMakeFiles/scacchiera.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable scacchiera.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\scacchiera.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scacchiera.dir/build: scacchiera.exe
.PHONY : CMakeFiles/scacchiera.dir/build

CMakeFiles/scacchiera.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\scacchiera.dir\cmake_clean.cmake
.PHONY : CMakeFiles/scacchiera.dir/clean

CMakeFiles/scacchiera.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files" "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\Project_Files" "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build" "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build" "D:\Utente\PROGETTO FINALE\PROJECT_UNI_Chess\build\CMakeFiles\scacchiera.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/scacchiera.dir/depend
