//
// Created by Jonatan Muhle-Zimino on 19/11/2024.
//
#include "header.h"


void insertH(double* hMap, int destRow, int destCol){
  for(int i = 0; i < MAPSIZEROW; i++){                            // laves to for-løkker, for at indsætte værdierne i et 2D-array
    for(int j = 0; j < MAPSIZECOL; j++){
      hMap[(i * MAPSIZEROW) + j] = hCalc(i, j, destRow, destCol); //hCalc funktionen bruges, da det er her den har beregnet værdierne og indsætter dem
    }
  }
}

double hCalc(int i, int j, int destRow, int destCol) {
  return sqrt(pow((i - destRow),2)+pow((j - destCol),2));         //En formel for hvordan den eucleadian distance beregnes ud fra nuværende og dest cellerne
}
