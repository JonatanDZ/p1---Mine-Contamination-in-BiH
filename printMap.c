//
// Created by marku on 13/11/2024.
//

#include "header.h"

void printMap(int* map, const int mapSize) { //We are printing the map
    for (int i = 0; i < mapSize; i++){
        for (int j = 0; j < mapSize; j++){
            printf(" %d ", map[i * mapSize + j]);
        }
        printf("\n");
    }

}