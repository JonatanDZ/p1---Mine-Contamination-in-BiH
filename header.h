//
// Created by marku on 12/11/2024.
//

#ifndef HEADER_H
#define HEADER_H

#endif //HEADER_H


#include <stdlib.h>
#include <stdio.h>

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