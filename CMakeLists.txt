cmake_minimum_required(VERSION 3.29)
project(p1___Mine_Contamination_in_BiH C)

set(CMAKE_C_STANDARD 11)


add_executable(main
        aStar.c
        createMap.c
        main.c
        header.h
        linSearch.c
        aStar.c
        ifObstacle.c
        input.c
        printMap.c
        aStarTest.c
        terminalOutput.c
)

