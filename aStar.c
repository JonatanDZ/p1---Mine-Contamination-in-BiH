//
// Created by Jonatan Muhle-Zimino on 19/11/2024.
//
#include "header.h"


void aStarSearch(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest) {
  cell_t open[99];
  cell_t closed[99];
  int count = 0;


  //initializing starting cell
  cell_t startCell;
  startCell.parentCoor.row = 0;
  startCell.parentCoor.col = 0;
  startCell.currentCoor.row = start.row;
  startCell.currentCoor.col = start.col;
  startCell.h = hCalc(start.row, start.col, dest.row, dest.col);
  startCell.g = 0; //denne er 0 det er givet i input.c
  startCell.f = startCell.g + startCell.h;

  //We are putting the starting cell in open list
  open[0] = startCell;

  //While open is not empty
  while(1) {

    //find the note with the smallest f value in the open list and pop it off open
    cell_t currentCell = popCell(open, linSearch(open));
    //Insert currentCell to closed list
    closed[count] = currentCell;


    generateSuccessors(map, currentCell, open, dest);


    count++;
  }




}


cell_t popCell(cell_t list[], int n) {
  int length = sizeof(list)/sizeof(list[0]);
  cell_t returnCell = list[n];
  for (int i = n; i < length; i++) {
    list[i] = list[i+1];
  }
  return returnCell;
}

void generateSuccessors(int map[MAPSIZEROW][MAPSIZECOL], cell_t currentCell, cell_t open[], coor_t dest) {

  for (int row = -1; row <= 1; row++) {
    for (int col = -1; col <= 1; col++) {
      cell_t successorCell;

        if (row != 0 && col != 0) {
          //We are declaring parentValues for the successor
          successorCell.parentCoor.row = currentCell.currentCoor.row;
          successorCell.parentCoor.col = currentCell.currentCoor.col;

          //Initializing successor cells coordinates
          successorCell.currentCoor.row = successorCell.parentCoor.row + row;
          successorCell.currentCoor.col = successorCell.parentCoor.col + col;

          //Checking if the successor cell is not out of bounds
          if (isWithinArray(successorCell.currentCoor.row, successorCell.currentCoor.col)) {
            if (isDestination(successorCell.currentCoor.row, successorCell.currentCoor.col, dest)) {
              printf("Wu!Hu!\nDesitination found!!");
            }

            //If the cell is walkable we give it values so we can compare them with each other
            if (isUnblocked(map, successorCell.currentCoor.row, successorCell.currentCoor.col)) {
              successorCell.g = currentCell.g + map[successorCell.currentCoor.row][successorCell.currentCoor.row];
              successorCell.h = hCalc(successorCell.currentCoor.row, successorCell.currentCoor.col, dest.row, dest.col);
              successorCell.f = successorCell.g + successorCell.h;
            }
          }
        }




    }
  }
}


void insertH(double hMap[MAPSIZEROW][MAPSIZECOL], coor_t dest){
  for(int i = 0; i < MAPSIZEROW; i++){                            // laves to for-løkker, for at indsætte værdierne i et 2D-array
    for(int j = 0; j < MAPSIZECOL; j++){
      hMap[i][j] = hCalc(i, j, dest.row, dest.col); //hCalc funktionen bruges, da det er her den har beregnet værdierne og indsætter dem
    }
  }
}

double hCalc(int i, int j, int destRow, int destCol) {
  return sqrt(pow((i - destRow),2)+pow((j - destCol),2));         //En formel for hvordan den eucleadian distance beregnes ud fra nuværende og dest cellerne
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