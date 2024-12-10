cmake_minimum_required(VERSION 3.29)
project(p1___Mine_Contamination_in_BiH C)

set(CMAKE_C_STANDARD 11)

add_executable(testExe
        testFile.c
        test.h
        ../src/map.c
        ../src/dataStructures.c
        ../src/aStar.c
)

target_compile_options(testExe PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_test(NAME arrayTester1 COMMAND testExe)