#ifndef ASTAR_H
#define ASTAR_H
#include "dataStructures.h"
#include "map.h"
//The following are used in the .c file. Do not delete.
#include <math.h>
#include <float.h>
#include <stdio.h>


void aStarSearch(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest);
void generateSuccessors(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t dest);

bool fLinSearch(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int* resultR, int* resultC);

double hCalc(int row, int col, int destRow, int destCol);

bool isDestination(int row, int col, coor_t dest);


int tracePath(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t start);
void printTime(int gTotal);

#endif //ASTAR_H