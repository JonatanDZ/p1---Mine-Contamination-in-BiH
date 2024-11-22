//
// Created by Jonatan Muhle-Zimino on 22/11/2024.
//
#include "header.h";

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
                default:
                    map[i][j] = 150; //er for path værdien
            }
        }
    }
}