#ifndef INPUT_H
#define INPUT_H
#include "map.h"
#include "dataStructures.h"
#include <stdio.h>

void input(int map[MAPSIZEROW][MAPSIZECOL], coor_t* start, coor_t* dest);
int inputCoordinates(int map[MAPSIZEROW][MAPSIZECOL], coor_t* start, coor_t* dest);
void inputMineGen(int map[MAPSIZEROW][MAPSIZECOL]);
void inputTerrain(int map[MAPSIZEROW][MAPSIZECOL]);

#endif //INPUT_H
