//
// Created by Jonat on 03/12/2024.
//

#include "header.h"

void inputForShortestRouteAndMineGen(int map[MAPSIZEROW][MAPSIZECOL]) {
    int mineAnswer;
    int amountOfMines;
    printf("\nRandom mines, yes(1) no(0) ");
    scanf("%d", &mineAnswer);
    //If loop that runs if the user wants
    if (mineAnswer == 1) {
        printf("How many mines do you want? ");
        scanf("%d", &amountOfMines);
        randomMineGen(map, amountOfMines);
    }

    int choice;
    printf("Normal(0)- or shortroute(1)> ");
    scanf(" %d", &choice);
    if (choice == 1) {
        shortestRoute(map);
    }
}