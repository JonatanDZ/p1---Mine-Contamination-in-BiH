//
// Created by marku on 13/11/2024.
//

#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include <stdbool.h>
#define MAPSIZEROW 32
#define MAPSIZECOL 32


typedef struct {
    int parentRow;
    int parentCol;
    double g;
    double h;
    double f;
    bool OpenList;
    bool ClosedList;
} cell_t;


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

bool ifObstacle(int map[MAPSIZEROW][MAPSIZECOL], int row, int col);

#endif //HEADER_H
