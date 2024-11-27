//
// Created by Jonatan Muhle-Zimino on 22/11/2024.
//
#include "header.h"

void fromNumberToEnum(int map[MAPSIZEROW][MAPSIZECOL]) {
    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {
            switch (map[i][j]) {
                case 167:
                    map[i][j] = mine;
                break;
                case 247:
                    map[i][j] = water;
                break;
                case 223:
                    map[i][j] = asphalt;
                break;
                case 202:
                    map[i][j] = city;
                break;
                case 173:
                    map[i][j] = field;
                break;
                case 216:
                    map[i][j] = forest;
                break;
                case 133:
                    map[i][j] = mountain1;
                break;
                case 142:
                    map[i][j] = mountain2;
                break;
                case 00:
                    map[i][j] = startPosition;
                break;
                case 01:
                    map[i][j] = endPosition;
                break;
                default:
                    map[i][j] = 150; //er for path værdien
            }
        }
    }
}
