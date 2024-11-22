//
// Created by Jonatan Muhle-Zimino on 13/11/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int input(int map[MAPSIZEROW][MAPSIZECOL], const int mapSize, coor_t* start, coor_t* dest) {
    // Starter fra 0, så minus en for koordinat.



    printf("Input x og y koordinat for start koordinator");
    scanf(" %d %d", &start->row, &start->col);

    //map[start->row][start->col] = startPosistion;




    printf("Input x og y koordinat for end koordinator");
    scanf(" %d %d", &dest->row, &dest->col);


    //map[dest->row][dest->col] = endPosistion;

    if (start->row == dest->row && start->col == dest->col) {
        return EXIT_FAILURE;
    }

    return 1;
}
