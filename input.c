//
// Created by Jonatan Muhle-Zimino on 13/11/2024.
//

#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int input(int map[MAPSIZEROW][MAPSIZECOL]) {
    // Starter fra 0, så minus en for koordinat.



    int startRow = -1, startCol = -1;

    printf("Input x og y koordinat for start koordinator, det går fra 0 0 til %d>", MAPSIZE-1);
    scanf(" %d %d", &startRow, &startCol);

    map[startRow][startCol] = startPosition;

    if (ifObstacle(map, startRow, startCol) == 1) {
        printf("Error: start cant be on a mine or river, pleas reenter the first coordinates \n");
        return input(map);
    }

    int destRow, destCol;

    printf("Input x og y koordinat for end koordinator, det går fra 0 0 til %d>", MAPSIZE-1);
    scanf(" %d %d", &destRow, &destCol);

    if (ifObstacle(map, destRow, destCol) == 1) {
        printf("Error: distination cant be on a mine or river, pleas reenter both coordinates \n");
        return input(map);
    }

    map[destRow][destCol] = endPosition;

    if (startRow == destRow && startCol == destCol) {
        return input(map);
    }

    return 1;
}
