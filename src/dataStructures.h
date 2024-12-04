//
// Created by a-bti on 12/3/2024.
//

#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
#include <stdbool.h>
#include "map.h"
#define NOPARENTYET -1

typedef struct {
    int row;
    int col;
} coor_t;

typedef struct {
    double f;
    double g;
    double h;
    coor_t parentCoor;
    bool openList;
    bool closedList;
} cell_t;


void initEmptyCellMap(cell_t cellMap[MAPSIZEROW][MAPSIZECOL]);
void initCell(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int successorRow, int successorCol, int gCost, int parentRow, int parentCol, coor_t dest);

void printCell(cell_t cell, int row, int col);

#endif //DATASTRUCTURES_H