//
// Created by marku on 13/11/2024.
//

#include "header.h"

void printMap(double* map, const int mapSize) { //We are printing the map
    printf("\n");
    for (int i = 0; i < mapSize - 2; i++){
        for (int j = 0; j < mapSize - 2; j++){
            printf("%3.0lf ", map[i * mapSize + j]);
        }
        printf("\n");
    }

}