#ifndef ASTAR_H
#define ASTAR_H
#include "dataStructures.h"
#include "map.h"
//The following are used in the .c file. Do not delete.
#include <math.h>
#include <float.h>
#include <stdio.h>

int aStarSearch(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest);
bool fSearch(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int* resultR, int* resultC);
void generateSuccessors(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t dest);
int tracePath(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t start);
void printTime(int gTotal);


//All these are dijkstra related
int dijkstra(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest);
void generateSuccessorsDijkstra(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col);

#endif //ASTAR_H