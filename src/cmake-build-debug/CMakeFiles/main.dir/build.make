# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:\Users\a-bti\AppData\Local\JetBrains\CLion 2024.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\a-bti\AppData\Local\JetBrains\CLion 2024.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/aStar.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/aStar.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/src/aStar.c
CMakeFiles/main.dir/aStar.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/aStar.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/aStar.c.obj -MF CMakeFiles\main.dir\aStar.c.obj.d -o CMakeFiles\main.dir\aStar.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\aStar.c

CMakeFiles/main.dir/aStar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/aStar.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\aStar.c > CMakeFiles\main.dir\aStar.c.i

CMakeFiles/main.dir/aStar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/aStar.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\aStar.c -o CMakeFiles\main.dir\aStar.c.s

CMakeFiles/main.dir/main.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/src/main.c
CMakeFiles/main.dir/main.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/main.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/main.c.obj -MF CMakeFiles\main.dir\main.c.obj.d -o CMakeFiles\main.dir\main.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\main.c

CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\main.c > CMakeFiles\main.dir\main.c.i

CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\main.c -o CMakeFiles\main.dir\main.c.s

CMakeFiles/main.dir/isUnblocked.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/isUnblocked.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/src/isUnblocked.c
CMakeFiles/main.dir/isUnblocked.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main.dir/isUnblocked.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/isUnblocked.c.obj -MF CMakeFiles\main.dir\isUnblocked.c.obj.d -o CMakeFiles\main.dir\isUnblocked.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\isUnblocked.c

CMakeFiles/main.dir/isUnblocked.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/isUnblocked.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\isUnblocked.c > CMakeFiles\main.dir\isUnblocked.c.i

CMakeFiles/main.dir/isUnblocked.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/isUnblocked.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\isUnblocked.c -o CMakeFiles\main.dir\isUnblocked.c.s

CMakeFiles/main.dir/input.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/input.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/src/input.c
CMakeFiles/main.dir/input.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main.dir/input.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/input.c.obj -MF CMakeFiles\main.dir\input.c.obj.d -o CMakeFiles\main.dir\input.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\input.c

CMakeFiles/main.dir/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/input.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\input.c > CMakeFiles\main.dir\input.c.i

CMakeFiles/main.dir/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/input.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\input.c -o CMakeFiles\main.dir\input.c.s

CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c
CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.obj -MF CMakeFiles\main.dir\C_\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\aStarTest.c.obj.d -o CMakeFiles\main.dir\C_\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\aStarTest.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\aStarTest.c

CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\aStarTest.c > CMakeFiles\main.dir\C_\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\aStarTest.c.i

CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\aStarTest.c -o CMakeFiles\main.dir\C_\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\aStarTest.c.s

CMakeFiles/main.dir/terminalOutput.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/terminalOutput.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/src/terminalOutput.c
CMakeFiles/main.dir/terminalOutput.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/main.dir/terminalOutput.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/terminalOutput.c.obj -MF CMakeFiles\main.dir\terminalOutput.c.obj.d -o CMakeFiles\main.dir\terminalOutput.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\terminalOutput.c

CMakeFiles/main.dir/terminalOutput.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/terminalOutput.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\terminalOutput.c > CMakeFiles\main.dir\terminalOutput.c.i

CMakeFiles/main.dir/terminalOutput.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/terminalOutput.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\terminalOutput.c -o CMakeFiles\main.dir\terminalOutput.c.s

CMakeFiles/main.dir/printMapChar.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/printMapChar.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/src/printMapChar.c
CMakeFiles/main.dir/printMapChar.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/main.dir/printMapChar.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/printMapChar.c.obj -MF CMakeFiles\main.dir\printMapChar.c.obj.d -o CMakeFiles\main.dir\printMapChar.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\printMapChar.c

CMakeFiles/main.dir/printMapChar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/printMapChar.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\printMapChar.c > CMakeFiles\main.dir\printMapChar.c.i

CMakeFiles/main.dir/printMapChar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/printMapChar.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\printMapChar.c -o CMakeFiles\main.dir\printMapChar.c.s

CMakeFiles/main.dir/mineGen.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/mineGen.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/src/mineGen.c
CMakeFiles/main.dir/mineGen.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/main.dir/mineGen.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/mineGen.c.obj -MF CMakeFiles\main.dir\mineGen.c.obj.d -o CMakeFiles\main.dir\mineGen.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\mineGen.c

CMakeFiles/main.dir/mineGen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/mineGen.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\mineGen.c > CMakeFiles\main.dir\mineGen.c.i

CMakeFiles/main.dir/mineGen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/mineGen.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\mineGen.c -o CMakeFiles\main.dir\mineGen.c.s

CMakeFiles/main.dir/fromNumberToEnum.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/fromNumberToEnum.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/src/fromNumberToEnum.c
CMakeFiles/main.dir/fromNumberToEnum.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/main.dir/fromNumberToEnum.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/fromNumberToEnum.c.obj -MF CMakeFiles\main.dir\fromNumberToEnum.c.obj.d -o CMakeFiles\main.dir\fromNumberToEnum.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\fromNumberToEnum.c

CMakeFiles/main.dir/fromNumberToEnum.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/fromNumberToEnum.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\fromNumberToEnum.c > CMakeFiles\main.dir\fromNumberToEnum.c.i

CMakeFiles/main.dir/fromNumberToEnum.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/fromNumberToEnum.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\fromNumberToEnum.c -o CMakeFiles\main.dir\fromNumberToEnum.c.s

CMakeFiles/main.dir/map.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/map.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/src/map.c
CMakeFiles/main.dir/map.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/main.dir/map.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/map.c.obj -MF CMakeFiles\main.dir\map.c.obj.d -o CMakeFiles\main.dir\map.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\map.c

CMakeFiles/main.dir/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/map.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\map.c > CMakeFiles\main.dir\map.c.i

CMakeFiles/main.dir/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/map.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\map.c -o CMakeFiles\main.dir\map.c.s

CMakeFiles/main.dir/dataStructures.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/dataStructures.c.obj: C:/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/src/dataStructures.c
CMakeFiles/main.dir/dataStructures.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/main.dir/dataStructures.c.obj"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/dataStructures.c.obj -MF CMakeFiles\main.dir\dataStructures.c.obj.d -o CMakeFiles\main.dir\dataStructures.c.obj -c C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\dataStructures.c

CMakeFiles/main.dir/dataStructures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main.dir/dataStructures.c.i"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\dataStructures.c > CMakeFiles\main.dir\dataStructures.c.i

CMakeFiles/main.dir/dataStructures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main.dir/dataStructures.c.s"
	C:\Users\a-bti\AppData\Local\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\dataStructures.c -o CMakeFiles\main.dir\dataStructures.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/aStar.c.obj" \
"CMakeFiles/main.dir/main.c.obj" \
"CMakeFiles/main.dir/isUnblocked.c.obj" \
"CMakeFiles/main.dir/input.c.obj" \
"CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.obj" \
"CMakeFiles/main.dir/terminalOutput.c.obj" \
"CMakeFiles/main.dir/printMapChar.c.obj" \
"CMakeFiles/main.dir/mineGen.c.obj" \
"CMakeFiles/main.dir/fromNumberToEnum.c.obj" \
"CMakeFiles/main.dir/map.c.obj" \
"CMakeFiles/main.dir/dataStructures.c.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.exe: CMakeFiles/main.dir/aStar.c.obj
main.exe: CMakeFiles/main.dir/main.c.obj
main.exe: CMakeFiles/main.dir/isUnblocked.c.obj
main.exe: CMakeFiles/main.dir/input.c.obj
main.exe: CMakeFiles/main.dir/C_/Users/a-bti/OneDrive/Documents/GitHub/p1---Mine-Contamination-in-BiH/aStarTest.c.obj
main.exe: CMakeFiles/main.dir/terminalOutput.c.obj
main.exe: CMakeFiles/main.dir/printMapChar.c.obj
main.exe: CMakeFiles/main.dir/mineGen.c.obj
main.exe: CMakeFiles/main.dir/fromNumberToEnum.c.obj
main.exe: CMakeFiles/main.dir/map.c.obj
main.exe: CMakeFiles/main.dir/dataStructures.c.obj
main.exe: CMakeFiles/main.dir/build.make
main.exe: CMakeFiles/main.dir/linkLibs.rsp
main.exe: CMakeFiles/main.dir/objects1.rsp
main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main.exe
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug C:\Users\a-bti\OneDrive\Documents\GitHub\p1---Mine-Contamination-in-BiH\src\cmake-build-debug\CMakeFiles\main.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend

