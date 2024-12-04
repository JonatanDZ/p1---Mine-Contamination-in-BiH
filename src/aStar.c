#include "aStar.h"


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

  /* Print til debugging
  printf("--Starting Cell--\n");
  printCell(cellMap[start.row][start.col], start.row, start.col);
  */

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

    /* Print til debugging
    printf("\n\n---this cell is new in closed list---\n");
    printCell(cellMap[row][col], row, col);
    */


    //Breaks the while loop if the destination has been moved to the closed list.
    if (cellMap[dest.row][dest.col].closedList == true) {
      printf("Here is the path that we found\n");
      tracePath(cellMap, map, dest.row, dest.col, start);
      return;
    }

    generateSuccessors(cellMap, map, row, col, dest);
  }

  if (openListIsEmpty == true) {
    printf("No Path is found");
  }

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
            // Print til debugging
            /*printCell(cellMap[successorRow][successorCol], successorRow, successorCol);*/
          }
        }
      }
    }
  }
}

/**
 *
 * @param cellMap Provides cell list to search through
 * @param resultR The row-value currently with the lowest f-value
 * @param resultC The column-value currently with the lowest f-value
 * @return true if no cells were found in open, false if at least one cell was in 'open'
 */
bool fLinSearch(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int* resultR, int* resultC) {
  bool first = true;

  //r & c determine which cell is currently checked through its coordinates, starting from the beginning of the 2d cell array.
  for (int r = 0; r < MAPSIZEROW; r++) {
    for (int c = 0; c < MAPSIZECOL; c++) {

      //Only searching cells within 'open' list. Ignore all others.
      if (cellMap[r][c].openList == true) {

        /* To ensure that cells in 'open' are only compared to other cells in open,
         * the first cell found in 'open' should lay basis for f cost comparison.*/
        if (first == true) {
          *resultR = r;
          *resultC = c;
          first = false;
        }
        /* In all other comparisons after finding the first 'open' cell,
         * compare the current cell's f cost to the previously found lowest f cost. */
        else if (cellMap[r][c].f < cellMap[*resultR][*resultC].f && cellMap[r][c].f > 0.01) { //0.0001 is our buffer we have to do this working with floats

          /* If the current cell's f cost is lower than the previously found,
           *     update result coordinates to the current cell's coordinates */
          *resultR = r;
          *resultC = c;
        }
      }
    }
  }
  //If first is returned as true, no cells were found in open. If returned as false, at least one cell was in 'open'
  return first;
}

double hCalc(int row, int col, int destRow, int destCol) {
  int diffRow = abs(row - destRow);
  int diffCol = abs(col - destCol);
  int D = 10;
  int D2 = 10 * 1.4;
  return D * (diffRow + diffCol) + (D2 - 2 * D) * fmin(diffRow, diffCol);
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

/**
 * Utility function determining whether a not a given input is the destination.
 * @param row Input, row to check.
 * @param col Input, col to check.
 * @return true if within, else returns false.
 */
bool isDestination(int row, int col, coor_t dest) {
  return row == dest.row && col == dest.col;
}

