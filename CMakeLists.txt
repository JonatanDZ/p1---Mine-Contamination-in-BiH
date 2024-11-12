cmake_minimum_required(VERSION 3.5.0)
project(p1---Mine-Contamination-in-BiH VERSION 0.1.0 LANGUAGES C)

add_executable(p1---Mine-Contamination-in-BiH main.c
        aStar.c)

add_library(aStar aStar.c)
target_include_directories(aStar PUBLIC .)

include(CTest)
enable_testing()

