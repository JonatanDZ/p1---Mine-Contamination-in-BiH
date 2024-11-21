//
// Created by marku on 13/11/2024.
//

#ifndef HEADER_H
#define HEADER_H

#define MAPSIZEROW 32
#define MAPSIZECOL 32
#define DIRECTIONS 4

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <math.h>

#include <assert.h>

typedef struct {
    int row;
    int col;
} coor_t;

typedef struct {
    coor_t currentCoor;
    coor_t parentCoor;
    double g;
    double h;
    double f;
    bool openList;
    bool closedList;
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

void createMap(int map[MAPSIZEROW][MAPSIZECOL]);
void printMap(int map[MAPSIZEROW][MAPSIZECOL]);

int input(int map[MAPSIZEROW][MAPSIZECOL], const int mapSize, coor_t* start, coor_t* dest);

void insertH(double hMap[MAPSIZEROW][MAPSIZECOL], coor_t dest);

double hCalc(int i, int j, int destRow, int destCol);

bool isUnblocked(int map[MAPSIZEROW][MAPSIZECOL], int row, int col);

bool isWithinArray(int row, int col);

int linSearch(cell_t cellList[]);

void generateSuccessors(map[MAPSIZEROW][MAPSIZECOL], cell_t currentCell, cell_t open[], coor_t dest);
cell_t popCell(cell_t list[], int i);
bool isDestination(int row, int col, coor_t dest);


#endif //HEADER_H
