//
// Created by Jonatan Muhle-Zimino on 19/11/2024.
//
#include "header.h"


void aStarSearch(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest) {
  cell_t open[99];
  cell_t closed[99];

  cell_t cellStart;
  cellStart.parentCoor.row = start.row;
  cellStart.parentCoor.col = start.col;
  cellStart.h = hCalc(start.row, start.col, dest.row, dest.col);
  cellStart.g = map[start.row][start.col]; //denne er 0 det er givet i input.c
  cellStart.f = cellStart.g + cellStart.h;

  open[0] = cellStart;

  while(sizeof(open) > 0) {
    linSearch(open);

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