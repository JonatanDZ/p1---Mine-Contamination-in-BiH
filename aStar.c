#include <stdbool.h>
#include "aStar.h"

#define ROW 32
#define COL 32

typedef struct pair {
    int row;
    int column;
}Pair;

typedef struct ppair {
    double d;
    Pair;
}pPair;

//Struct der har de nødvendige parametre
struct cell {
    //Row and column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    //Parametre til udregning af f = g + h
    double f, g, h;
};

//Utlility function checking if a cell is valid or not.
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

//Utility function checking if a cell is blocked.
bool isUnblocked(int* map, int mapSize, int row, int col) {
    if(map[row * mapSize + col] == 1) {
        return true;
    } else {
        return false;
    }
}

bool isDestination(int row, int col, Pair dest) {
    if (row == dest.row && col == dest.column) {
        return (true);
    } else {
        return (false);
    }
}
double 


void aStarSearch(int map, spawn, dest){

}