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
                
            }
        }
    }
}

    city = 202,
    field = 173,
    forest = 216,
    mountain1 = 133,
    mountain2 = 142