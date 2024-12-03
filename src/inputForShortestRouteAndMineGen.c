//
// Created by Jonat on 03/12/2024.
//

#include "header.h"

void inputForShortestRouteAndMineGen(int map[MAPSIZEROW][MAPSIZECOL]) {
    int mineAnswer;
    int amountOfMines;
    printf("Do you want additional random mines? No (0) or Yes (1)\n>");
    scanf("%d", &mineAnswer);
    //If loop that runs if the user wants
    if (mineAnswer == 1) {
        printf("How many additional mines do you want?\n>");
        scanf("%d", &amountOfMines);
        randomMineGen(map, amountOfMines);
    }

    int choice;
    printf("\nDo you want normal terrain (0) or flat terrain (1)?\n>");
    scanf(" %d", &choice);
    if (choice == 1) {
        shortestRoute(map);
    }
}