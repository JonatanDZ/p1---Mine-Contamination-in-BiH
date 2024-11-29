//
// Created by Jonatan Muhle-Zimino on 22/11/2024.
//
#include "header.h"
//Changes the value from enum to char, so it will be printed correcly.

/**
 * This function changes the values so it looks neat drawn with asciis symbols
 * @param map s values are updated so it looks neat drawn with asciis symbols
 */
void terminalOutPut(int map[MAPSIZEROW][MAPSIZECOL]) {
    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {
            switch (map[i][j]) {
                case mine:
                    map[i][j] = 167;
                    break;
                case water:
                    map[i][j] = 247;
                    break;
                case asphalt:
                    map[i][j] = 186;
                    break;
                case city:
                    map[i][j] = 223;
                    break;
                case field:
                    map[i][j] = 178;
                    break;
                case forest:
                    map[i][j] = 157;
                    break;
                case mountain1:
                    map[i][j] = 239;
                    break;
                case mountain2:
                    map[i][j] = 234;
                    break;
                case startPosition:
                    map[i][j] = 101;
                    break;
                case endPosition:
                    map[i][j] = 202;
                    break;
                default:
                    map[i][j] = 'R'; //er for path værdien
            }
        }
    }
}
