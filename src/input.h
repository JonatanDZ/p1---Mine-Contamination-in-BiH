#ifndef INPUT_H
#define INPUT_H
#include "map.h"
#include "dataStructures.h"
#include <stdio.h>

int input(int map[MAPSIZEROW][MAPSIZECOL], coor_t* start, coor_t* dest);
void inputForShortestRouteAndMineGen(int map[MAPSIZEROW][MAPSIZECOL]);
#endif //INPUT_H
