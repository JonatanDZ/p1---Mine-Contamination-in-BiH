//
// Created by Jonatan Muhle-Zimino on 13/11/2024.
//

#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int input(int map[MAPSIZEROW][MAPSIZECOL]) {
    // Starter fra 0, så minus en for koordinat.

    int startRow, startCol;

    printf("Input x og y koordinat for start koordinator, det går fra 0 0 til %d>", MAPSIZE-1);
    scanf(" %d %d", &startRow, &startCol);

    map[startRow][startCol] = startPosition;

    int destRow, destCol;

    printf("Input x og y koordinat for end koordinator, det går fra 0 0 til %d>", MAPSIZE-1);
    scanf(" %d %d", &destRow, &destCol);

    map[destRow][destCol] = endPosition;

    if (startRow == destRow && startCol == destCol) {
        return EXIT_FAILURE;
    }

    return 1;
}
