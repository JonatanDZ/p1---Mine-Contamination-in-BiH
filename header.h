//
// Created by marku on 13/11/2024.
//

#ifndef HEADER_H
#define HEADER_H

#define MAPSIZEROW 32
#define MAPSIZECOL 32
#define MAXSIZE 999

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <math.h>

#include <assert.h>

typedef struct {
    int row;
    int col;
} coor_t;

typedef struct {
    coor_t currentCoor;
    coor_t parentCoor;
    double g;
    double h;
    double f;
    //bool openList;
    //bool closedList;
} cell_t;

typedef enum {
    mine = 00,
    water = 1,
    asphalt = 10,
    city = 14,
    field = 16,
    forest = 24,
    mountain1 = 27,
    mountain2 = 35
} moveValue;

void aStarSearch(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest);

void createMap(int map[MAPSIZEROW][MAPSIZECOL]);
void printMap(int map[MAPSIZEROW][MAPSIZECOL]);

int input(int map[MAPSIZEROW][MAPSIZECOL], const int mapSize, coor_t* start, coor_t* dest);

void insertH(double hMap[MAPSIZEROW][MAPSIZECOL], coor_t dest);

double hCalc(int i, int j, int destRow, int destCol);

bool isUnblocked(int map[MAPSIZEROW][MAPSIZECOL], int row, int col);

bool isWithinArray(int row, int col);

int fLinSearch(cell_t cellList[]);
int gLinSearch(cell_t cellList[], cell_t successorCell);


void generateSuccessors(int map[MAPSIZEROW][MAPSIZECOL], cell_t currentCell, cell_t open[], cell_t closed[], coor_t dest, int count, bool* pathFound);
cell_t popCell(cell_t list[], int n);
bool isDestination(int row, int col, coor_t dest);

bool isInList(cell_t list[], cell_t cellElement);

void tracePath();

void printCell(cell_t cell);




#endif //HEADER_H
