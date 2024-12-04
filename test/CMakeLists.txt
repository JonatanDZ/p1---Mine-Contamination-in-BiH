cmake_minimum_required(VERSION 3.29)
project(p1___Mine_Contamination_in_BiH C)

set(CMAKE_C_STANDARD 11)
target_link_libraries()
add_test(NAME inputtest COMMAND inputTest.c)
add_executable(test
        aStarTest.c
        inputTest.c
        ../src/input.c
)
