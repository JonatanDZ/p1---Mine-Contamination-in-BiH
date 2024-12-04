cmake_minimum_required(VERSION 3.29)
project(p1___Mine_Contamination_in_BiH C)

set(CMAKE_C_STANDARD 11)

add_executable(testExe testFile.c ../src/map.c
        testFile.c)

add_test(NAME aStarTest COMMAND aStarTest)

