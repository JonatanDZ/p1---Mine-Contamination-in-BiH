#ifndef MAP_H
#define MAP_H
#define MAPSIZEROW 32
#define MAPSIZECOL 32
#define MAPSIZE 32
#include <stdbool.h>
#include <windows.h>

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
