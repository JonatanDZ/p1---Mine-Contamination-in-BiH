//
// Created by Jonatan Muhle-Zimino on 19/11/2024.
//
#include <float.h>

#include "header.h"
#define NOPARENTYET -1


void aStarSearch(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest) {
/* 0) Set up */

  //2d array to manage cells and 'lists', initialization
  cell_t cellMap[MAPSIZEROW][MAPSIZECOL];
  initEmptyCellMap(cellMap);

/* 1) Starting the search with start cell */

  initCell(cellMap, start.row, start.col, 0, 0, 0, dest);


  //'Add' to open list
  cellMap[start.row][start.col].openList = true;
  cellMap[start.row][start.col].closedList = false;

  printf("--Starting Cell--\n");
  printCell(cellMap[start.row][start.col], start.row, start.col);

/* 2) Repeat, while open 'list' is not empty*/

  //Coordinates determining current cell.
  int row, col;


  //bool destinationFound = false;
  bool openListIsEmpty = false;

  while(openListIsEmpty == false) {


    //From the 'open' list, find the note with the smallest f value.      (Pop it off open, by setting its open bool to false and keeping its coordinates)
    openListIsEmpty = fLinSearch(cellMap, &row, &col);

    //Remove it from the 'open' list, then add to 'closed' list
    cellMap[row][col].openList = false;
    cellMap[row][col].closedList = true;

    printf("\n\n---this cell is new in closed list---\n");
    printCell(cellMap[row][col], row, col);


    if (cellMap[dest.row][dest.col].closedList == true) {
      break;
    }

    generateSuccessors(cellMap, map, row, col, dest);

  }
  if (openListIsEmpty == true) {
    printf("No Path is found");
    return;
  }

  printf("Here is the path that we found\n");
  tracePath(cellMap, map, dest.row, dest.col, start);

}

void generateSuccessors(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t dest) {
/* For each of the 8 cells surrounding current cell*/
  for (int r = -1; r <= 1; r++) {
    for (int c = -1; c <= 1; c++) {

      //Ensuring center cell is ignored
      if (r != 0 || c != 0) {

        //The successors' coordinates for readability
        int successorRow = row + r;
        int successorCol = col + c;

        //This ensures that walking diagonally has an extra cost which is the increased walking distance
        int successorGCost;
        if (r == 0 || c == 0) {
          successorGCost = cellMap[row][col].g + map[successorRow][successorCol];
        } else {
          successorGCost = cellMap[row][col].g + map[successorRow][successorCol] * 1.4;
        }

        //If cell is outside map bounds or already in the closed list, successors do should not be generated. Instead cell is ignored.
        if (isWithinArray(successorRow, successorCol) && cellMap[successorRow][successorCol].closedList == false) {

          //Also ignore blocked cells
          if (isUnblocked(map, successorRow, successorCol)) {
          /**/

              // a) If it is NOT already in 'open' list, set values & add it to 'open' list.
              if (cellMap[successorRow][successorCol].openList == false) {
                initCell(cellMap, successorRow, successorCol, successorGCost, row, col , dest);

                //Add it to the 'open' list
                cellMap[successorRow][successorCol].openList = true;
              }

              // b) If successor IS already in 'open' list, check whether this path is better than previously stored one. Measure by G.cost
              if (successorGCost < cellMap[successorRow][successorCol].g) {
                initCell(cellMap, successorRow, successorCol, successorGCost, row, col , dest);

            }
            printCell(cellMap[successorRow][successorCol], successorRow, successorCol);
          }
        }
      }
    }
  }
  //If the early return has not happened, destination has not been found.
}

double hCalc(int row, int col, int destRow, int destCol) {
  int diffRow = abs(row - destRow);
  int diffCol = abs(col - destCol);
  int D = 10;
  int D2 = 10 * 1.4;
  return D * (diffRow + diffCol) + (D2 - 2 * D) * fmin(diffRow, diffCol);
}

/**
 * Utility function determining whether a not a given input is within the 2d array.
 * @param row Input, row to check.
 * @param col Input, col to check.
 * @return true if within, else returns false.
 */
bool isWithinArray(int row, int col) {
  if (row >= 0 && row < MAPSIZEROW && col >= 0 && col < MAPSIZECOL) {
    return true;
  }
  return false;
}

/**
 * Utility function determining whether a not a given input is the destination.
 * @param row Input, row to check.
 * @param col Input, col to check.
 * @return true if within, else returns false.
 */
bool isDestination(int row, int col, coor_t dest) {
  return row == dest.row && col == dest.col;
}

/**
 * Utility function printing a cell for debugging purposes.
 * @param cell, cell to print
 * @param row of the cell, because cell struct does not contain its own coordinates.
 * @param col of the cell, because cell struct does not contain its own coordinates.
 */
void printCell(cell_t cell, int row, int col) {
  printf("\nCell coor: (%d, %d):\nParentCoor: (%d, %d)\nh: %lf g: %lf f: %lf\n", row, col, cell.parentCoor.row, cell.parentCoor.col, cell.h, cell.g, cell.f);
  printf("Open %d - Closed %d\n", cell.openList, cell.closedList);
}

/**
 * Recursive function tracing back from destination to start, and drawing on the map provided.
 * @param cellMap input only: Used to provide row and col input, by parents
 * @param map Array to change
 * @param row to compare against start row
 * @param col to compare against start col
 * @param start struct providing coordinates for start
 * @return true when start is reached, otherwise false
 */
int tracePath(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t start) {
  if (row == start.row && col == start.col) {
    map[row][col] = 9;
    return 1;
  }
  map[row][col] = 9;
  return tracePath(cellMap, map, cellMap[row][col].parentCoor.row, cellMap[row][col].parentCoor.col, start);
}

/** Initializes an empty cell map.
 * @param cellMap the array of cells structs to update values within.
 * f,g,h set to max double value allowed.
 * Parents are set NO PARENT YET defined value.
 * Both 'open' and 'closed' booleans are set to false. No cell should be in any of the lists at start.
 */
void initEmptyCellMap(cell_t cellMap[MAPSIZEROW][MAPSIZECOL]) {
  for (int i = 0; i < MAPSIZEROW; i++) {
    for (int j = 0; j < MAPSIZECOL; j++) {
      //To indicate all cells as unexplored:

      //All cells' f, g, h, values set to maximum double allowed
      cellMap[i][j].f = DBL_MAX;
      cellMap[i][j].g = DBL_MAX;
      cellMap[i][j].h = DBL_MAX;

      //Parents set to -1
      cellMap[i][j].parentCoor.row = NOPARENTYET;
      cellMap[i][j].parentCoor.row = NOPARENTYET;

      //Both lists should be empty at start
      cellMap[i][j].openList = false;
      cellMap[i][j].closedList = false;
    }
  }
}

void initCell(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int successorRow, int successorCol, int gCost, int parentRow, int parentCol, coor_t dest) {

  cellMap[successorRow][successorCol].parentCoor.row = parentRow;
  cellMap[successorRow][successorCol].parentCoor.col = parentCol;

  //Recalculate & update g and f values. h (estimated distance to dest) will remain the same, so no recalculations needed
  cellMap[successorRow][successorCol].g = gCost;
  cellMap[successorRow][successorCol].h = hCalc(successorRow,successorCol, dest.row, dest.col);
  cellMap[successorRow][successorCol].f = cellMap[successorRow][successorCol].g + cellMap[successorRow][successorCol].h;
  printCell(cellMap [successorRow][successorCol], successorRow, successorCol);


}