//
// Created by marku on 13/11/2024.
//

#include "header.h"

/**
 * Function that prints the map.
 * @param map int array from main.
 */
void printMap(int map[MAPSIZEROW][MAPSIZECOL]) {
    printf("\n");
    // For-loop which prints each value in the array.
    for (int i = 0; i < MAPSIZEROW; i++){
        for (int j = 0; j < MAPSIZEROW; j++){
            printf("%2d ", map[i][j]);
        }
        printf("\n");
    }

}