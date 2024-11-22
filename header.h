//
// Created by marku on 13/11/2024.
//

#ifndef HEADER_H
#define HEADER_H

#define MAPSIZEROW 32
#define MAPSIZECOL 32

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

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

void readMap();
void createMap(int map[MAPSIZEROW][MAPSIZECOL]);
void printMap(int map[MAPSIZEROW][MAPSIZECOL]);

int input(int map[MAPSIZEROW][MAPSIZECOL], const int mapSize, int* destRow, int* destCol);

void insertH(double* hMap, int destRow, int destCol);

double hCalc(int i, int j, int destRow, int destCol);

bool ifObstacle(int map[MAPSIZEROW][MAPSIZECOL], int row, int col);

bool isWithinArray(int row, int col);


#endif //HEADER_H
