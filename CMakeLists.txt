cmake_minimum_required(VERSION 3.5.0)
project(p1---Mine-Contamination-in-BiH VERSION 0.1.0 LANGUAGES C)

include_directories(include)

add_executable(p1---Mine-Contamination-in-BiH main.c createMap.c printMap.c) 

include(CTest)
enable_testing()

