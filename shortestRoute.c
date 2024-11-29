//
// Created by Jonatan Muhle-Zimino on 25/11/2024.
//
#include "header.h"

//Changes the enum to 10 so we are able to see the shortest route without terrain.
void shortestRoute(int map[MAPSIZEROW][MAPSIZECOL]) {
    int choice;
    printf("Normal(0)- or shortroute(1)> ");
    scanf(" %d", &choice);

    if (choice == 1) {
        for (int i = 0; i < MAPSIZEROW; i++) {
            for (int j = 0; j < MAPSIZECOL; j++) {
                switch (map[i][j]) {
                    case mine:
                        map[i][j] = mine;
                    break;
                    case water:
                        map[i][j] = water;
                    break;
                    case asphalt:
                        map[i][j] = 10;
                    break;
                    case city:
                        map[i][j] = 10;
                    break;
                    case field:
                        map[i][j] = 10;
                    break;
                    case forest:
                        map[i][j] = 10;
                    break;
                    case mountain1:
                        map[i][j] = 10;
                    break;
                    case mountain2:
                        map[i][j] = 10;
                    break;
                    case startPosition:
                        map[i][j] = 10;
                    break;
                    case endPosition:
                        map[i][j] = 10;
                }
            }
        }
    }

}

