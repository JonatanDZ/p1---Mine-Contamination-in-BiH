#include "input.h"

/**
 * Function that calls all input functions.
 * @param map map from main.
 * @param start start coordinates defined in main.
 * @param dest destination coordinates defined in main.
 */
void input(int map[MAPSIZEROW][MAPSIZECOL], coor_t* start, coor_t* dest) {
    inputMineGen(map);
    inputTerrain(map);
    inputCoordinates(map, start, dest);
}

/**
 * Function that prompts the user for input for mine generation setting.
 * @param map map from main.
 */
void inputMineGen(int map[MAPSIZEROW][MAPSIZECOL]) {
    int mineAnswer;
    int amountOfMines;
    int validInput; // Variable to store the result of scanf

    // Landmine generation
    do {
        printf("Do you want additional random mines? No (0) or Yes (1).\n>");
        validInput = scanf("%d", &mineAnswer);

        // Clear the input buffer to remove invalid characters
        fflush(stdin);

        // Check if the input is valid and within the expected range
        if (validInput != 1 || mineAnswer != 0 && mineAnswer != 1) {
            printf("Invalid input. Please enter 0 or 1.\n");
        }

    } while (validInput != 1 || mineAnswer != 0 && mineAnswer != 1);
    printf("You selected: %d\n", mineAnswer);


    //If loop that runs if the user wants random mines.
    if (mineAnswer == 1) {
        do {
            printf("\nHow many additional landmines do you want? (MAX = 500).\n>");
            validInput = scanf("%d", &amountOfMines);

            // Clear the input buffer to remove invalid characters
            fflush(stdin);

            // Check if the input is valid and within the expected range
            if (validInput != 1 || amountOfMines < 0 || amountOfMines > 500) {
                printf("Invalid input. Please enter 0 or 1.\n");
            }

        } while (validInput != 1 || amountOfMines < 0 || amountOfMines > 500);
        printf("You selected: %d\n", amountOfMines);

        randomMineGen(map, amountOfMines);
    }
}

/**
 * Function that prompts the user for input for terrain setting.
 * @param map map from main.
 */
void inputTerrain(int map[MAPSIZEROW][MAPSIZECOL]) {
    int choice;
    int validInput; // Variable to store the result of scanf

    // Terrain type
    do {
        printf("\nDo you want normal terrain (0) or flat terrain (1)?\n>");
        validInput = scanf("%d", &choice);

        // Clear the input buffer to remove invalid characters
        fflush(stdin);

        if (validInput != 1 || choice != 0 && choice != 1) {
            printf("Invalid input. Please enter 0 or 1.\n");
        }

    } while (validInput != 1 || choice != 0 && choice != 1);
    printf("You selected: %d\n", choice);

    // If loop that runs shortestRoute function, if user chose said option.
    if (choice == 1) {
        shortestRoute(map);
    }
}

//Makes the start and end posistions.
int inputCoordinates(int map[MAPSIZEROW][MAPSIZECOL], coor_t* start, coor_t* dest) {
    int validInput; // Variable to store the result of scanf

    // Start coordinates
    do {
        printf("\nInput x y coordinates for the start location, within the coordinate interval from 0 0 to %d %d.\n>", MAPSIZE-1, MAPSIZE-1);
        validInput = scanf("%d %d", &start->row, &start->col);

        // Clear the input buffer to remove invalid characters
        fflush(stdin);

        // Check if the input is valid and within the expected range
        if (validInput != 2 || !isWithinArray(start->row, start->col)) {
            printf("Invalid input. Please enter a valid coordinate.\n");
        }

    } while (validInput != 2 || !isWithinArray(start->row, start->col));
    printf("You selected: %d %d\n", start->row, start->col);

    // Checks the chosen coordinate is not intraversable
    if (isUnblocked(map, start->row, start->col) == false) {
        printf("Error: Start cannot be on a mine or river, please reenter the first coordinates \n");
        return inputCoordinates(map, start, dest);
    }

    // Destination coordinates
    do {
        printf("\nInput x y coordinates for the destination, within the coordinate interval 0 0 to %d %d.\n>", MAPSIZE-1, MAPSIZE-1);
        validInput = scanf("%d %d", &dest->row, &dest->col);

        // Clear the input buffer to remove invalid characters
        fflush(stdin);

        // Check if the input is valid and within the expected range
        if (validInput != 2 || !isWithinArray(dest->row, dest->col)) {
            printf("Invalid input. Please enter a valid coordinate.\n");
        }

    } while (validInput != 2 || !isWithinArray(dest->row, dest->col));
    printf("You selected: %d %d\n\n", dest->row, dest->col);

    // Checks the chosen coordinate is not intraversable
    if (isUnblocked(map, dest->row, dest->col) == false) {
        printf("Error: Destination cannot be on a mine or river, please enter both coordinates again.\n");
        return inputCoordinates(map, start, dest);
    }

    // Checks the start and end coordinates are not the same cell.
    if (start->row == dest->row && start->col == dest->col) {
        printf("Error: Start and destination cannot be the same!\n");
        return inputCoordinates(map, start, dest);
    }

    printf("\nProcessing route from (%d , %d) --> (%d , %d).\n", start->row, start->col, dest->row, dest->col);
}