cmake_minimum_required(VERSION 3.29)
project(p1___Mine_Contamination_in_BiH C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)


enable_testing()

add_subdirectory(src)
add_subdirectory(test)