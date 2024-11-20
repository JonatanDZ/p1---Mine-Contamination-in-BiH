#include <stdbool.h>
#include "aStar.h"
#include <math.h>
#include <stdio.h>
#include "stack.h"


#define ROW 32
#define COL 32

/**
 *User-defined type for cell coordinate pair.
 **/
typedef struct {
    int row;
    int column;
} coordinates_t;

//TODO: gør senere
typedef struct { // TODO: Hold øje med hvad denne skal bruges til
    double d;
    coordinates_t;
} cCoordinates_t;

// TODO: find ud af parent, neighbour etc. fis
// Struct der har de nødvendige parametre
typedef struct {
    // Row and column index of its parent
    // Note that 0 <= parentRow <= ROW-1 & 0 <= parentColumn <= COL-1
    int parentRow, parentColumn;
    // Parameters to calculate f = g + h
    double f, g, h;
} cell_t;

/**
 *Utility function checking if a cell is valid or not. by returning 0 or 1.
 **/
int isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

/**
 *Utility function checking if a cell is blocked by a landmine or water.
 **/
int isUnblocked(int* map, int mapSize, int row, int col) {
    // [row * mapSize + col] finds the column and row in the 'array'.
    return map[row * mapSize + col] > 00; // TODO: kan også være den skal være == 1?
}
/**
 *Utility function checking if the cell is the destination
**/
int isDestination(int row, int col, coordinates_t dest) {
    return row == dest.row && col == dest.column;
}

/**
 *Calculate H-value with the diagonal distance. Manhatten Distance, total of the absolute volues of the descrepencies
 * between the x and y coordinates of the current and the goal cells
**/
double calcHValueDia(int row, int col, coordinates_t dest) {
    int diffRow = abs(row - dest.row);
    int diffCol = abs(col - dest.column);
    int D, D2; //TODO: find ud af hvad D skal være. (1 for længden af cellen eller vægten af cellen)
    return D * (diffRow + diffCol) + (D2 - 2 * D) * fmin(diffRow, diffCol);
}
/**
 *Calculate H-value with the Euclidean distance. The distance between goal cell and the current cell
 **/
double calcHValueEuc(int row, int col, coordinates_t dest) {
    return sqrt(pow(row - dest.row, 2) + pow(col - dest.column, 2));
}

void tracePath(cell_t cellDetails[][COL], coordinates_t dest) {
    printf("\nThe path is ");
    int row = dest.row;
    int col = dest.column;

    while(!(cellDetails[row][col].parentRow == row && cellDetails[row][col].parentColumn == col)) {
        printf("(%d, %d"), row, col);
        int tempRow = cellDetails[row][col].parentRow
        int tempCol =
    }
}



void aStarSearch(int* map, spawn, dest){

}