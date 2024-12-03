//
// Created by marku on 13/11/2024.
//

#ifndef HEADER_H
#define HEADER_H

#define MAPSIZEROW 32
#define MAPSIZECOL 32
#define MAXSIZE 999

#define MAPSIZE 32

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#include <math.h>

#include <assert.h>

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
void printMap(int map[MAPSIZEROW][MAPSIZECOL]);




bool isUnblocked(int map[MAPSIZEROW][MAPSIZECOL], int row, int col);

bool isWithinArray(int row, int col);

void terminalOutPut(int map[MAPSIZEROW][MAPSIZECOL]);
void printMapChar(int map[MAPSIZEROW][MAPSIZECOL]);

void randomMineGen(int map[MAPSIZEROW][MAPSIZECOL], int amountOfMines);
void shortestRoute(int map[MAPSIZEROW][MAPSIZECOL]);

void fromNumberToEnum(int map[MAPSIZEROW][MAPSIZECOL]);

// Updated
//int gLinSearch(cell_t cellList[], cell_t successorCell);
//int findParentLinSearch(cell_t parentCellList[], cell_t cell);


int tracePath(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t start);

void printCell(cell_t cell, int row, int col);


void color(int colorValue);


void initEmptyCellMap(cell_t cellMap[MAPSIZEROW][MAPSIZECOL]);



#endif //HEADER_H
