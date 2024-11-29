//
// Created by Jonatan Muhle-Zimino on 20/11/2024.
//
#include "header.h"
/**
 * Function that checks if a cell in the array is blocked i.e. untraversable.
 * @param map Int array from main.
 * @param row Int indicating which row in the array should be looked up.
 * @param col Int indication which column in the arary should be looked up.
 * @return True or false whether the location in the array is traversable.
 */
bool isUnblocked(int map[MAPSIZEROW][MAPSIZECOL], int row, int col) {
    if (map[row][col] == water || map[row][col] == mine) {
        return false;
    }
    return true;
}
