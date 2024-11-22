//
// Created by Jonatan Muhle-Zimino on 22/11/2024.
//
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomMineGen(int map[MAPSIZEROW][MAPSIZECOL]) {
    srand(time(NULL));
    int mineAnswer = 0;
    int amountOfMines = 0;
    int upperBound = MAPSIZE;
    // Set the lower bound for random numbers
    int lowerBound = 0;

    printf("\nRandom mines, yes(1) no(0) ");
    scanf("%d", &mineAnswer);
    if (mineAnswer == 1) {
        printf("How many mines do you want? ");
        scanf("%d", &amountOfMines);

        for (int i = 0; i < amountOfMines; i++) {
            map[rand() % (upperBound - lowerBound + 1)+ lowerBound][rand() % (upperBound - lowerBound + 1)+ lowerBound] = mine;
        }
    }
}

