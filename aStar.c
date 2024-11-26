//
// Created by Jonatan Muhle-Zimino on 19/11/2024.
//
#include <float.h>

#include "header.h"
#define NOPARENTYET -1


void aStarSearch(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest) {
/* 0) Set up */
  cell_t open[MAXSIZE];
  cell_t closed[MAXSIZE];
  bool pathFound = false;
  int count = 0;
  int endOfClosed;

  //2d array to manage cells and 'lists', initialization
  cell_t cellMap[MAPSIZEROW][MAPSIZECOL];
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



/* 2) Repeat, while open 'list' is not empty*/

  //Coordinates determining current cell.
  int row, column;

  while(!pathFound) {
    //From the 'open' list, find the note with the smallest f value.      (Pop it off open, by setting its open bool to false and keeping its coordinates)
    fLinSearch(cellMap, &row, &column);

    //Remove it from the 'open' list, then add to 'closed' list
    cellMap[row][column].openList = false;
    cellMap[row][column].closedList = true;

    endOfClosed = generateSuccessors(map, currentCell, open, closed, dest, count, &pathFound);

    count++;

  }
  if (!(closed[count].currentCoor.row == dest.row && closed[count].currentCoor.col == dest.col)) {
    printf("No Path is found");
    printf("\n%d\n", endOfClosed);

    for (int i = 0; i <= endOfClosed; i++) {
      printf("\n %d = %d,%d - f-value: %lf",i, closed[i].parentCoor.row, closed[i].parentCoor.col, closed[i].f);
    }
    tracePath(map, closed, closed[endOfClosed], start);
  } else {
    printf("Path is found");
    printf("\n%d\n", endOfClosed);
    tracePath(map, closed, closed[endOfClosed], start);
  }
}


cell_t popCell(cell_t list[], int n) {
  cell_t returnCell = list[n];
  for (int i = n; i < MAXSIZE; i++) {
    list[i] = list[i+1];
  }
  return returnCell;
}

int generateSuccessors(int cellMap[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t dest, int count, bool* pathFound) {
/* For each of the 8 cells surrounding current cell*/
  for (int r = -1; r <= 1; r++) {
    for (int c = -1; c <= 1; c++) {
      cell_t successorCell;

      //Making sure center cell is ignored
      if (r != 0 || c != 0) {
        //Setting parentValues for all successors
        cellMap[row + r][col + c].parentCoor.row = currentCell.currentCoor.row;
        successorCell.parentCoor.col = currentCell.currentCoor.col;

        //Initializing successor cells coordinates
        successorCell.currentCoor.row = successorCell.parentCoor.row + r;
        successorCell.currentCoor.col = successorCell.parentCoor.col + c;

        //Checking if the successor cell is not out of bounds
        if (isWithinArray(successorCell.currentCoor.row, successorCell.currentCoor.col)) {

          if (isDestination(successorCell.currentCoor.row, successorCell.currentCoor.col, dest)) {
            count++;
            printf("Wu!Hu!\nDesitination found!!\nIn closed: %d", count);
            closed[count] = successorCell;
            printCell(closed[count]);
            *pathFound = true;
            return count;
          }
          if (cell[]) {
            //If the cell is walkable we give it values so we can compare them with each other
            if (isUnblocked(map, successorCell.currentCoor.row, successorCell.currentCoor.col)) {
              successorCell.g = currentCell.g + map[successorCell.currentCoor.row][successorCell.currentCoor.row];
              successorCell.h = hCalc(successorCell.currentCoor.row, successorCell.currentCoor.col, dest.row, dest.col);
              successorCell.f = successorCell.g + successorCell.h;


              // If it isn't already in open list put it there
              if (cellMap[row][col].openList == false){

                cellMap[row][col].openList == true;

              } else {
                //if it is in the open list already. We are updating the shortest cost together with the parent coordinates
                int shortestPathIndex = gLinSearch(open, successorCell);
                open[shortestPathIndex].parentCoor.row = successorCell.currentCoor.row;
                open[shortestPathIndex].parentCoor.col = successorCell.currentCoor.col;
                open[shortestPathIndex].g = successorCell.g;
                open[shortestPathIndex].f = open[shortestPathIndex].g + open[shortestPathIndex].h;


              }
              //printf("\nsuccessorCell relation %d %d", row, col);
              //printCell(successorCell);
            }
          }
        }
      }
    }
  }
}

bool isInOpenList(cell_t cell){
  if (cell.openList)
  return true;
}



void insertH(double hMap[MAPSIZEROW][MAPSIZECOL], coor_t dest){
  for(int i = 0; i < MAPSIZEROW; i++){                            // laves to for-løkker, for at indsætte værdierne i et 2D-array
    for(int j = 0; j < MAPSIZECOL; j++){
      hMap[i][j] = hCalc(i, j, dest.row, dest.col); //hCalc funktionen bruges, da det er her den har beregnet værdierne og indsætter dem
    }
  }
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
}

int tracePath(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int row, int col, coor_t start) {
  if (row == start.row && col == start.col) {
    cellMap[row][col].g = 9; //TODO: revurder om vi skal printe til g eller om vi skal lave et nyt map
    return 1;
  }
  //int index = findParentLinSearch(closed, cell);
  cellMap[row][col].g = 9;
  return tracePath(cellMap, row, col, start);
}

bool isEmpty(cell_t cellMap){

}
