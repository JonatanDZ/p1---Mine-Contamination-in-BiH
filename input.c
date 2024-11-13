//
// Created by Jonatan Muhle-Zimino on 13/11/2024.
//

#include <stdio.h>
#include <stdlib.h>

int input(int* map, const int mapSize) {
    // Starter fra 0, så minus en for koordinat.
    int startPosistion = 10000;
    int startInputX;
    int startInputY;

    printf("Input x og y koordinat for start koordinator");
    scanf(" %d%d", &startInputX, &startInputY);

    map[startInputX * mapSize + startInputY] = startPosistion;

    int endPosistion = 10000;
    int endInputX;
    int endInputY;

    printf("Input x og y koordinat for end koordinator");
    scanf(" %d%d", &endInputX, &endInputY);

    map[endInputX * mapSize + endInputY] = endPosistion;

    if (startInputX == endInputX && startInputY == endInputY) {
        return EXIT_FAILURE;
    }
}
