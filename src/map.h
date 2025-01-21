#ifndef MAP_H
#define MAP_H
#define MAPSIZEROW 100
#define MAPSIZECOL 100
#define MAPSIZE 100
#include <stdbool.h>
//The following are used in the .c file. Do not delete.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Enum setting each cell's value to time it takes to walk in seconds.
 * Time value found by irl testing. (Asphalt - Mountain2)
 * Mine, water, startPosition & endPosition are irrelevant for total time.
 */
typedef enum {
    mine = 00,
    water = 1,
    asphalt = 15,
    city = 16,
    field = 19,
    forest = 29,
    mountain1 = 63,
    mountain2 = 78,
    startPosition = 2,
    endPosition = 3
} moveValue;

void createMapWFile(int map[MAPSIZEROW][MAPSIZECOL]);
void readMapFileIntoArray(int map[MAPSIZEROW][MAPSIZECOL]);
void fromNumberToEnum(int map[MAPSIZEROW][MAPSIZECOL]);

void randomMineGen(int map[MAPSIZEROW][MAPSIZECOL], int amountOfMines);
void mapMineReplace(int map[MAPSIZEROW][MAPSIZECOL]);
bool isMineable(int map[MAPSIZEROW][MAPSIZECOL], int row, int col);

void shortestRoute(int map[MAPSIZEROW][MAPSIZECOL]);

bool isWithinArray(int row, int col);
bool isUnblocked(int map[MAPSIZEROW][MAPSIZECOL], int row, int col);

void terminalOutPut(int map[MAPSIZEROW][MAPSIZECOL]);

#endif //MAP_H