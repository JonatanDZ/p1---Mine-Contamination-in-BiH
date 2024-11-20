//
// Created by Jonatan Muhle-Zimino on 19/11/2024.
//
#include "header.h"


void insertH(double* hMap, int destRow, int destCol){
  for(int i = 0; i < MAPSIZEROW; i++){
    for(int j = 0; j < MAPSIZECOL; j++){
      hMap[(i * MAPSIZEROW) + j] = hCalc(i, j, destRow, destCol);
    }
  }
}

double hCalc(int i, int j, int destRow, int destCol) {
  return sqrt(pow((i - destRow),2)+pow((j - destCol),2));
}
