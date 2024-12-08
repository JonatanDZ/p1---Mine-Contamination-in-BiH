#ifndef INPUT_H
#define INPUT_H
#include "map.h"
#include "dataStructures.h"
//The following are used in the .c file. Do not delete.
#include <stdio.h>

void input(int map[MAPSIZEROW][MAPSIZECOL], coor_t* start, coor_t* dest);
void inputMineGen(int map[MAPSIZEROW][MAPSIZECOL]);
void inputTerrain(int map[MAPSIZEROW][MAPSIZECOL]);
int inputCoordinates(int map[MAPSIZEROW][MAPSIZECOL], coor_t* start, coor_t* dest);

#endif //INPUT_H
