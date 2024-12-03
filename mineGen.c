//
// Created by Jonatan Muhle-Zimino on 22/11/2024.
//
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Genereates mines that are placed random on the map, and overwrites the value already there
void randomMineGen(int map[MAPSIZEROW][MAPSIZECOL]) {
    srand(time(NULL));
    int mineAnswer = 0;         //Answar from which the function determines of it should run
    int amountOfMines = 0;      //The amout of mines wanted by the user
    int upperBound = MAPSIZE;
    // Set the lower bound for random numbers depending on where the mine can be placed
    int lowerBound = 0;

    printf("Do you want additional random mines? No (0) or Yes (1)\n>");
    scanf("%d", &mineAnswer);
    //If loop that runs if the user wants
    if (mineAnswer == 1) {
        printf("How many additional mines do you want?\n>");
        scanf("%d", &amountOfMines);

        //For loop that runs, until all mines are placed
        for (int i = 0; i < amountOfMines; i++) {
            map[rand() % (upperBound - lowerBound + 1)+ lowerBound][rand() % (upperBound - lowerBound + 1)+ lowerBound] = mine;
        }
    }
}

