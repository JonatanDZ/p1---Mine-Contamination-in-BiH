cmake_minimum_required(VERSION 3.29)
project(p1___Mine_Contamination_in_BiH C)

set(CMAKE_C_STANDARD 11)

add_executable(testExe
        testFile.c ../src/map.c
        test.h
        ../src/dataStructures.c
        ../src/aStar.c
        ../src/dijkstra.c
)

target_compile_options(testExe PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_test(NAME arrayTester1 COMMAND testExe)