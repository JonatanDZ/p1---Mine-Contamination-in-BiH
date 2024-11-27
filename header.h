//
// Created by marku on 13/11/2024.
//

#ifndef HEADER_H
#define HEADER_H

#define MAPSIZEROW 32
#define MAPSIZECOL 32

#define MAPSIZE 32

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
    mountain2 = 142,
    startPosition = 00,
    endPosition = 01
} moveValue;

void createMap(int map[MAPSIZEROW][MAPSIZECOL]);
void createMapWFile(int map[MAPSIZEROW][MAPSIZECOL]);
void printMap(int map[MAPSIZEROW][MAPSIZECOL]);

int input(int map[MAPSIZEROW][MAPSIZECOL]);

void insertH(double* hMap, int destRow, int destCol);

double hCalc(int i, int j, int destRow, int destCol);

bool ifObstacle(int map[MAPSIZEROW][MAPSIZECOL], int row, int col);

bool isWithinArray(int row, int col);

void terminalOutPut(int map[MAPSIZEROW][MAPSIZECOL]);
void printMapChar(int map[MAPSIZEROW][MAPSIZECOL]);

void randomMineGen(int map[MAPSIZEROW][MAPSIZECOL]);

void shortestRoute(int map[MAPSIZEROW][MAPSIZECOL]);
void fromNumberToEnum(int map[MAPSIZEROW][MAPSIZECOL]);


#endif //HEADER_H
