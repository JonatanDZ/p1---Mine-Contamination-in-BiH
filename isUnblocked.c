//
// Created by Jonatan Muhle-Zimino on 20/11/2024.
//
#include "header.h"
//Checker to see if the cell is blocked.
bool isUnblocked(int map[MAPSIZEROW][MAPSIZECOL], int row, int col) {
    if (map[row][col] == water || map[row][col] == mine) {
        return false;
    }
    return true;
}
