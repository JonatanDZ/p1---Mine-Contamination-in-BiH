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
        printf("\n");
        for (int j = 0; j < MAPSIZECOL; j++) {
            switch (map[i][j]) {
                case mine:
                    color(0x44);
                    break;
                case water:
                    color(0x99);
                    break;
                case asphalt:
                    color(0x77);
                    break;
                case city:
                    color(0x88);
                    break;
                case field:
                    color(0xee);
                    break;
                case forest:
                    color(0xAA);
                    break;
                case mountain1:
                    color(0x22);
                    break;
                case mountain2:
                    color(0x66);
                    break;
                case startPosition:
                    color(0x0c);
                    break;
                case endPosition:
                    color(0xcc);
                    break;
                default:
                    color(0xFF);
            }
        }
    }
}

void color(int colorValue) {
    HANDLE H= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,colorValue);
    printf("   ");
}
