//
// Created by marku on 13/11/2024.
//

#include "header.h"

void printMap(int map[MAPSIZEROW][MAPSIZECOL]) { //We are printing the map
    printf("\n");
    for (int i = 0; i < MAPSIZEROW; i++){
        for (int j = 0; j < MAPSIZEROW; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

}