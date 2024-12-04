cmake_minimum_required(VERSION 3.29)
project(p1___Mine_Contamination_in_BiH C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src)

enable_testing()

add_subdirectory(test)