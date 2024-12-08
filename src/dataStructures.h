#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
#define NOPARENTYET -1
#include <stdbool.h>
#include "map.h"
//The following are used in the .c file. Do not delete.
#include <float.h>
#include <tgmath.h>

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
double hCalc(int row, int col, int destRow, int destCol);



/* TODO: --- DEBUGGING FUNCTIONS --- */
void printCell(cell_t cell, int row, int col);

#endif //DATASTRUCTURES_H