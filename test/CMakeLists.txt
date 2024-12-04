cmake_minimum_required(VERSION 3.29)
project(p1___Mine_Contamination_in_BiH C)

set(CMAKE_C_STANDARD 11)

add_executable(testProgram
        aStarTest.c
        inputTest.c
        ../src/map.c
)

add_test(NAME aStarTest.c COMMAND testProgram)

