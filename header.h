//
// Created by marku on 13/11/2024.
//

#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ROW 32
#define COL 32

typedef enum {
    mine = 167,
    water = 247,
    asphalt = 223,
    city = 202,
    field = 173,
    forest = 216,
    mountain1 = 133,
    mountain2 = 142
} moveValue;

void createMap(int* map, const int mapSize);

void printMap(int* map, const int mapSize);

int input(int* map, const int mapSize);
bool ifArray(int row, int col);


#endif //HEADER_H
