//
// Created by a-bti on 12/3/2024.
//

#ifndef ASTAR_H
#define ASTAR_H

#endif //ASTAR_H
#define NOPARENTYET -1

void aStarSearch(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest);
void generateSuccessors(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t dest);




bool fLinSearch(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int* resultR, int* resultC);


void initCell(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int successorRow, int successorCol, int gCost, int parentRow, int parentCol, coor_t dest);
double hCalc(int row, int col, int destRow, int destCol);

bool isDestination(int row, int col, coor_t dest);