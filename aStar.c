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

  //Calculate f,g,h
  cellMap[start.row][start.col].h = hCalc(start.row, start.col, dest.row, dest.col);
  cellMap[start.row][start.col].g = 0;
  cellMap[start.row][start.col].f = cellMap[start.row][start.col].g + cellMap[start.row][start.col].h;

  //Parents unknown, initialized to zero as of now / or to indicate start having no parents. OBS: Check later
  cellMap[start.row][start.col].parentCoor.row = 0;
  cellMap[start.row][start.col].parentCoor.col = 0;

  //'Add' to open list
  cellMap[start.row][start.col].openList = true;
  cellMap[start.row][start.col].closedList = false;

  printf("--Starting Cell--\n");
  printCell(cellMap[start.row][start.col], start.row, start.col);



/* 2) Repeat, while open 'list' is not empty*/

  //Coordinates determining current cell.
  int row, col;

  //TODO: come back here, and comment. Check destinationCheck
  bool destinationCheck = false;
  bool openListIsEmpty = false;

  while(openListIsEmpty == false && destinationCheck == false) {


    //From the 'open' list, find the note with the smallest f value.      (Pop it off open, by setting its open bool to false and keeping its coordinates)
    openListIsEmpty = fLinSearch(cellMap, &row, &col);
          /*
          printf("\n--Cell from linear search - this should be in open list--");
          printCell(cellMap[row][col], row, col);
          printf("______________________________\n\n");
          */


    //Remove it from the 'open' list, then add to 'closed' list
    cellMap[row][col].openList = false;
    cellMap[row][col].closedList = true;
          /*
    printf("\n--This cell is moved to closedList--");
    printCell(cellMap[row][col], row, col);
    printf("_________________________\n\n");
    */

    destinationCheck = generateSuccessors(cellMap, map, row, col, dest);
          /*printf("\nSuccessors generated\n");
     */
  }

  if (openListIsEmpty == true) {
    printf("No Path is found");
    return;
  }
  if (destinationCheck == true){
        /*
    printf("Closed list\n");
    for (int i = 0; i < MAPSIZEROW; i++) {
      for (int j = 0; j < MAPSIZECOL; j++) {
        if (cellMap[i][j].closedList == true ) {
          printCell(cellMap[i][j], i , j);
        }
      }
    }
*/

    printf("Here is the path that we found\n");
    tracePath(cellMap, map, dest.row, dest.col, start);
  }
}

bool generateSuccessors(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t dest) {
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
         /*TODO: if it is in the closed list */
        if (isWithinArray(successorRow, successorCol)) {

          //Also ignore blocked cells
          if (isUnblocked(map, successorRow, successorCol)) {

            if (isDestination(successorRow, successorCol, dest)) {  //TODO: måske vi skal rykke denne, fordi den ikke nødvendigvis peger på den hurtigste rute
              printf("Wu!Hu!\nDesitination found!!\n");

              //Setting parent coordinates of the destination.
              cellMap[successorRow][successorCol].parentCoor.row = row;
              cellMap[successorRow][successorCol].parentCoor.col = col;

              //Record the destinations f,g,h costs
              cellMap[successorRow][successorCol].g = cellMap[row][col].g + map[successorRow][successorCol];
              cellMap[successorRow][successorCol].h = hCalc(successorRow,successorCol, dest.row, dest.col);
              cellMap[successorRow][successorCol].f = cellMap[successorRow][successorCol].g + cellMap[successorRow][successorCol].h;

              //Adding the destination to the closed list
              cellMap[successorRow][successorCol].closedList = true;

              //Early return if destination is met
              return true;
            }
            //Initialize the cell if it is
            if (cellMap[successorRow][successorCol].closedList == false) {
              //If the cell is walkable we give it values so we can compare them with each other


                // a) If it is NOT already in 'open' list, set values & add it to 'open' list.
                if (cellMap[successorRow][successorCol].openList == false) {

                  //Setting parentValues for the successor.                       Will be the same for all 8 successors to the same parent, whose coordinates were passed as 'row' & 'col' arguments in function call.
                  cellMap[successorRow][successorCol].parentCoor.row = row;
                  cellMap[successorRow][successorCol].parentCoor.col = col;

                  //Record successor's f,g,h costs
                  cellMap[successorRow][successorCol].g = successorGCost;
                  cellMap[successorRow][successorCol].h = hCalc(successorRow,successorCol, dest.row, dest.col);
                  cellMap[successorRow][successorCol].f = cellMap[successorRow][successorCol].g + cellMap[successorRow][successorCol].h;

                  //Add it to the 'open' list
                  cellMap[successorRow][successorCol].openList = true;
                        /*
                  printf("\nNew in openList");
                  printCell(cellMap[successorRow][successorCol], successorRow, successorCol);
                  */
                }

                // b) If successor IS already in 'open' list, check whether this path is better than previously stored one. Measure by G.cost
                if (successorGCost < cellMap[successorRow][successorCol].g) {

                  //If new path is better, update parentValues.
                  cellMap[successorRow][successorCol].parentCoor.row = row;
                  cellMap[successorRow][successorCol].parentCoor.col = col;

                  //Recalculate & update g and f values. h (estimated distance to dest) will remain the same, so no recalculations needed
                  cellMap[successorRow][successorCol].g = successorGCost;
                  cellMap[successorRow][successorCol].h = hCalc(successorRow,successorCol, dest.row, dest.col);
                  cellMap[successorRow][successorCol].f = cellMap[successorRow][successorCol].g + cellMap[successorRow][successorCol].h;
                        /*
                  printf("\nAlready in open. Updated g,f value and parents");
                  printCell(cellMap[successorRow][successorCol], successorRow, successorCol);
                  */
              }
            }
          }
        }
      }
    }
  }
  //If the early return has not happened, destination has not been found.
  return false;
}

double hCalc(int row, int col, int destRow, int destCol) {
  //return sqrt(pow((i - destRow),2)+pow((j - destCol),2));         //En formel for hvordan den eucleadian distance beregnes ud fra nuværende og dest cellerne
  int diffRow = abs(row - destRow);
  int diffCol = abs(col - destCol);
  int D = 10;
  int D2 = 10 * 1.4;
  return D * (diffRow + diffCol) + (D2 - 2 * D) * fmin(diffRow, diffCol);
}

bool isWithinArray(int row, int col) {
  if (row >= 0 && row < MAPSIZEROW && col >= 0 && col < MAPSIZECOL) {
    return true;
  }
  return false;
}

bool isDestination(int row, int col, coor_t dest) {
  return row == dest.row && col == dest.col;
}

void printCell(cell_t cell, int row, int col) {
  printf("\nCell coor: (%d, %d):\nParentCoor: (%d, %d)\nh: %lf g: %lf f: %lf\n", row, col, cell.parentCoor.row, cell.parentCoor.col, cell.h, cell.g, cell.f);
  printf("Open %d - Closed %d\n", cell.openList, cell.closedList);
}

int tracePath(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t start) {
  if (row == start.row && col == start.col) {
    //printCell(cellMap[row][col], row, col);
    map[row][col] = 9;
    return 1;
  }
  //printCell(cellMap[row][col], row, col);
  map[row][col] = 9;
  return tracePath(cellMap, map, cellMap[row][col].parentCoor.row, cellMap[row][col].parentCoor.col, start);
}

void tracePathIte(const cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t start) {
  while (row!= start.row || col != start.col) {
    printf("--Checked--\n");
    printf("Row: %d, col: %d", row, col);
    printCell(cellMap[row][col], row, col);
    printf("\n\n");

    //Draw
    map[row][col] = 9;

    //Update
    row = cellMap[row][col].parentCoor.row;
    col = cellMap[row][col].parentCoor.col;
  }
  //Draw on start
  map[row][col] = 9;
}

/*
void insertH(double hMap[MAPSIZEROW][MAPSIZECOL], coor_t dest){
  for(int i = 0; i < MAPSIZEROW; i++){                            // laves to for-løkker, for at indsætte værdierne i et 2D-array
    for(int j = 0; j < MAPSIZECOL; j++){
      hMap[i][j] = hCalc(i, j, dest.row, dest.col); //hCalc funktionen bruges, da det er her den har beregnet værdierne og indsætter dem
    }
  }
}
/*
cell_t popCell(cell_t list[], int n) {
  cell_t returnCell = list[n];
  for (int i = n; i < MAXSIZE; i++) {
    list[i] = list[i+1];
  }
  return returnCell;
}
*/

/*
bool isInOpenList(cell_t cell){
  if (cell.openList)
  return true;
}
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

