//
// Created by Jonatan Muhle-Zimino on 22/11/2024.
//
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Genereates mines that are placed random on the map, and overwrites the value already there
void randomMineGen(int map[MAPSIZEROW][MAPSIZECOL], int amountOfMines) {
    srand(time(NULL));
    int upperBound = MAPSIZE;
    // Set the lower bound for random numbers depending on where the mine can be placed
    int lowerBound = 0;

    //For loop that runs, until all mines are placed
    for (int i = 0; i < amountOfMines; i++) {
        map[rand() % (upperBound - lowerBound + 1)+ lowerBound][rand() % (upperBound - lowerBound + 1)+ lowerBound] = mine;
    }
}

