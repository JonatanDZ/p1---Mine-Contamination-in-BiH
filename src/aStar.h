#ifndef ASTAR_H
#define ASTAR_H
#include "dataStructures.h"


void aStarSearch(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest);
void generateSuccessors(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t dest);

bool fLinSearch(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int* resultR, int* resultC);

double hCalc(int row, int col, int destRow, int destCol);

bool isDestination(int row, int col, coor_t dest);

int tracePath(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t start);

#endif //ASTAR_H