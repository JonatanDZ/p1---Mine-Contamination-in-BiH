//
// Created by a-bti on 12/3/2024.
//

#ifndef MAP_H
#define MAP_H
#define MAPSIZEROW 32
#define MAPSIZECOL 32
#define MAPSIZE 32
#include <stdbool.h>
#include <windows.h>

typedef enum {
    mine = 00,
    water = 1,
    asphalt = 10,
    city = 14,
    field = 16,
    forest = 24,
    mountain1 = 27,
    mountain2 = 35,
    startPosition = 2,
    endPosition = 3
} moveValue;

void createMap(int map[MAPSIZEROW][MAPSIZECOL]);
void createMapWFile(int map[MAPSIZEROW][MAPSIZECOL]);
void fromNumberToEnum(int map[MAPSIZEROW][MAPSIZECOL]);

void randomMineGen(int map[MAPSIZEROW][MAPSIZECOL], int amountOfMines);
void shortestRoute(int map[MAPSIZEROW][MAPSIZECOL]);

bool isUnblocked(int map[MAPSIZEROW][MAPSIZECOL], int row, int col);
bool isWithinArray(int row, int col);


void terminalOutPut(int map[MAPSIZEROW][MAPSIZECOL]);
void color(int colorValue);

void printMap(int map[MAPSIZEROW][MAPSIZECOL]);
void printMapChar(int map[MAPSIZEROW][MAPSIZECOL]);

#endif //MAP_H
