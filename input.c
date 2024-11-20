//
// Created by Jonatan Muhle-Zimino on 13/11/2024.
//

#include <stdio.h>
#include <stdlib.h>

int input(int* map, const int mapSize, int* destRow, int* destCol) {
    // Starter fra 0, så minus en for koordinat.

    int startPosistion = 57;
    int startRow;
    int startCol;

    printf("Input x og y koordinat for start koordinator");
    scanf(" %d %d", &startRow, &startCol);

    map[startRow * mapSize + startCol] = startPosistion;

    int endPosistion = 57;



    printf("Input x og y koordinat for end koordinator");
    scanf(" %d %d", destRow, destCol);


    map[*destRow * mapSize + *destCol] = endPosistion;

    if (startRow == *destRow && startCol == *destCol) {
        return EXIT_FAILURE;
    }

    return 1;
}
