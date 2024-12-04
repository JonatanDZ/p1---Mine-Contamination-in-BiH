#include "input.h"

//Makes the start and end posistions.
int input(int map[MAPSIZEROW][MAPSIZECOL], coor_t* start, coor_t* dest) {
    // Starter fra 0, så minus en for koordinat.

    int startRow = -1, startCol = -1;

    printf("\nInput x y coordinates for the start location, within the coordinate interval from 0 0 to %d %d.\n>", MAPSIZE-1, MAPSIZE-1);
    scanf(" %d %d", &start->row, &start->col);

    map[start->row][start->col] = startPosition;

    if (isUnblocked(map, start->row, start->col) == false) {
        printf("Error: Start cannot be on a mine or river, please reenter the first coordinates \n");
        return input(map, start, dest);
    }


    printf("\nInput x y coordinates for the destination, within the coordinate interval 0 0 to %d %d.\n>", MAPSIZE-1, MAPSIZE-1);

    scanf(" %d %d", &dest->row, &dest->col);



    if (isUnblocked(map, dest->row, dest->col) == false) {
        printf("Error: Destination cannot be on a mine or river, please enter both coordinates again.\n");
        return input(map, start, dest);
    }

    map[dest->row][dest->col] = endPosition;

    if (start->row == dest->row && start->col == dest->row) {
        return input(map, start, dest);
    }

}

void inputForShortestRouteAndMineGen(int map[MAPSIZEROW][MAPSIZECOL]) {
    int mineAnswer;
    int amountOfMines;
    do {
    printf("Do you want additional random mines? No (0) or Yes (1).\n>");
    scanf("%d", &mineAnswer);
    } while(mineAnswer < 0 || mineAnswer > 1);

    //If loop that runs if the user wants random mines.
    if (mineAnswer == 1) {
        do {
        printf("How many additional mines do you want?\n>");
        scanf("%d", &amountOfMines);
        } while(amountOfMines < 0);
        randomMineGen(map, amountOfMines);
    }

    int choice;
    do {
    printf("\nDo you want normal terrain (0) or flat terrain (1)?\n>");
    scanf(" %d", &choice);
    } while(choice < 0 || choice > 1);

    if (choice == 1) {
        shortestRoute(map);
    }
}






