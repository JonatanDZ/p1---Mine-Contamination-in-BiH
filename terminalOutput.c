//
// Created by Jonatan Muhle-Zimino on 22/11/2024.
//
#include "header.h";

void terminalOutPut(int map[MAPSIZEROW][MAPSIZECOL]) {
    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {
            switch (map[i][j]) {
                case mine:
                    map[i][j] = 22;
                    break;
                case water:
                    map[i][j] = 45;
                    break;
                case asphalt:
                    map[i][j] = 27;
                    break;
                case city:
                    map[i][j] = 10;
                    break;
                case field:
                    map[i][j] = 11;
                    break;
                case forest:
                    map[i][j] = 1;
                    break;
                case mountain1:
                    map[i][j] = 2;
                    break;
                case mountain2:
                    map[i][j] = 3;
                    break;
                default:
                    printf("Error in output");
            }
        }
    }
}
