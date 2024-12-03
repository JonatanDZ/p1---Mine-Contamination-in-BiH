//
// Created by Jonatan Muhle-Zimino on 22/11/2024.
//

#include "header.h"

/**
 * Function printing the map in chars.
 * @param map int array from main.
 */
void printMapChar(int map[MAPSIZEROW][MAPSIZECOL]) {
    printf("\n");
    for (int i = 0; i < MAPSIZEROW; i++){
        for (int j = 0; j < MAPSIZEROW; j++){
            printf(" %c ", map[i][j]);
        }
        printf("\n");
    }

}