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
                    printf ("   ");
                    break;
                case water:
                    color(0x99);
                    printf("   ");
                    break;
                case asphalt:
                    color(0x77);
                    printf("   ");
                    break;
                case city:
                    color(0x88);
                    printf("   ");
                    break;
                case field:
                    color(0xee);
                    printf("   ");
                    break;
                case forest:
                    color(0xAA);
                    printf("   ");
                    break;
                case mountain1:
                    color(0x22);
                    printf("   ");
                    break;
                case mountain2:
                    color(0x66);
                    printf("   ");
                    break;
                case startPosition:
                    map[i][j] = 223;
                    color(0x0c);
                    printf("   ");
                    break;
                case endPosition:
                    map[i][j] = 223;
                    color(0xcc);
                    printf("   ");
                    break;
                default:
                    map[i][j] = 223; //er for path værdien
                    color(0xFF);
                    printf("   ");
            }
        }
    }
}

void color(int colorValue) {
    HANDLE H= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,colorValue);
}
