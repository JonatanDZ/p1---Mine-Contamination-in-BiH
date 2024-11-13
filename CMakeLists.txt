cmake_minimum_required(VERSION 3.29)
project(tester C)

set(CMAKE_C_STANDARD 11)

add_executable(tester main.c
        createMap.c
        header.h
        printMap.c
)
