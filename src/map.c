//
// Created by a-bti on 12/3/2024.
//

#include "map.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Our hardcoded map.
void createMap(int map[MAPSIZEROW][MAPSIZECOL]){
    int templateMap[32][32] = { //This is our hardcoded map
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain1,mountain1,mountain1,forest,forest, field, asphalt, city, water, water, city, city, asphalt, field,field,field,mine, forest, forest, mine, forest, forest, mine, mountain1, mountain2, mountain2, mountain2},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1,mountain1,forest,forest,asphalt,asphalt, city, water, water, city, asphalt, field, field, field, field,mine,forest,forest,forest,forest,forest,mountain1, mountain1, mountain2, mountain2,},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain1, mountain1, forest, field, asphalt, asphalt, city, water, water, asphalt, asphalt, field, field, field, field, field, field, forest, mine, forest, forest, mountain1, mountain1, mountain2},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1, forest, forest, field, asphalt, city, water, water, water, asphalt,field,field,field, field, field, mine, field, forest, forest, forest, forest, mountain1, mountain2},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1, mountain1, forest, forest, asphalt, asphalt, water, water, water, asphalt, asphalt, city, field,field,field,field,field,forest, forest, mine, forest, mountain1, mountain1},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1, mountain1, mountain1, forest, field, asphalt, asphalt, water, water, water, asphalt, city, city, city, field, field, field, mine, forest, forest, forest, mountain1, mountain1},
            {mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, forest, forest, field, asphalt, water, water, water, asphalt , city, city, city, field, field, field, forest, forest, forest, mountain1, mountain1, mountain2},
            {mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, forest, forest, forest, field, asphalt, water, water, water, asphalt, city, city, city, field, field, field, forest,forest,forest, mountain1, mountain1, mountain2 },
            {mountain2, mountain2, mountain2,mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, mountain1, forest, forest, forest, field, asphalt, asphalt, city, water, water, asphalt, city, city, city, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain2 },
            {mountain2,mountain2,mountain2,mountain2,mountain2, mountain1,mountain1,mountain1,mountain1, forest, forest, field, field, field, asphalt, city, city, water, water, asphalt, city, city, city, field, field, forest, mine, forest, mountain1, mountain1, mountain2, mountain2},
            {mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, forest, forest, forest, field, field, field, asphalt, asphalt, asphalt, city, city, water, water, asphalt, city, city, city, field, field, forest, forest, forest, forest, mountain1, mountain1,mountain2},
            {mountain2, mountain2, mountain2, mountain1, mountain1, forest, forest, field, field, field, asphalt, asphalt, asphalt, city, city, city, water, water, water, asphalt, city, city, field, field, mine, forest, forest, forest, mountain1, mountain2, mountain2, mountain2 },
            {mountain2, mountain2, mountain2, mountain1, forest, forest, field, field, city, city, asphalt, city,city,city,city,city, water, water, asphalt, asphalt, city, city, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain2, mountain2},
            {mountain2, mountain2, mountain1, mountain1, forest, city, city, city, city, city, asphalt, city, city, city, city, water, water, water, asphalt, city, city, city, field, field, forest, forest, mine, forest, mountain1, mountain1, mountain1, mountain2},
            {mountain2, mountain2, mountain1, forest, forest, city, city, city, city, city, asphalt, asphalt, city, city, city, water, water, asphalt, city, city, city, field, field, field, mine, forest, forest, forest, forest, mountain1, mountain1, mountain1},
            {mountain2, mountain2, mountain1, forest, city, city, city, city, city, city, city, asphalt, city, city, water, water, water, asphalt, city, city, city, field, field, field, mine, forest, forest, forest, forest, mountain1, mountain1, mountain1},
            {mountain2, mountain1, mountain1, forest, city, city, city, city, city, city, city, city, asphalt, water, water, asphalt, asphalt, city, city, city, field, field, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain2},
            {mountain2, mountain1, mountain1, forest, city, city, city, city, city, city, city, asphalt, asphalt, water, water, asphalt, city, city, city, city, field, field, field, field, forest, forest, forest, mountain1, mountain1, mountain1, mountain2, mountain2},
            {mountain2, mountain1, mountain1, forest, city, city, city, city, city, city, city, asphalt, asphalt, water, water, asphalt, city, city, city, city, field, field, field, field, forest, forest, forest, mountain1, mountain1, mountain1, mountain2, mountain2},
            {mountain2, mountain1, mountain1, forest, city, city, city, city, city, city, asphalt, asphalt, water, water, water, asphalt, city, city, city, field, field, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain2, mountain2}, //
            {mountain1, mountain1, forest, forest, city, city, city, city, city, asphalt, asphalt, asphalt, asphalt, water, asphalt, asphalt, city, city, field, field, field, field, field, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2}, //
            {mountain1, mountain1, forest, field, field, asphalt, asphalt, asphalt, asphalt, asphalt, water, water, asphalt, asphalt, asphalt, city, city, field, field, field, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2}, //
            {mountain1, forest, forest, field, asphalt, asphalt, water, water, water, water, water, city, city, city, city, city, city, city, city, field, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2}, //
            {mountain1, forest, forest, asphalt, asphalt, water, water, water, water, water, city, city, city, city, city, city, city, city, city, mine, field, field, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2}, //
            {mountain1, forest, field, asphalt, water, water, water, water, city, city, city, city, city , city, city, city, city, city, field, field, field, mine, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2}, //
            {forest, forest, asphalt, asphalt, water, city, water, city, city, field, mine, city, city, city, city, city, city, field, mine, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2}, //
            {forest, field, asphalt, water, water, city, water, city, field, field, field, field, field, field, field, field, field, field, field, forest, mine, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2}, //
            {field, asphalt, asphalt, water, city, water, water, city, mine, field, field, mine, field, forest, forest, forest, forest, mine, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mine, mountain2, mountain2, mountain2, mountain2}, //
            {field, asphalt, water, water, city, water, city, field, field, field, mine, forest, forest, forest, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2}, //
            {asphalt, asphalt, water, water, city, water, city, mine, field, field, forest, forest, forest, forest, forest, forest, mountain1, mountain1, mountain1, mine, mountain1, mountain1, mountain1, mountain2, mine, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2}, //
            {asphalt, water, water, city, city, water, city, field, mine, forest, mine, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mine, mountain2}, //
            {asphalt, water, water, city, city, water, mine, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mountain2}, //
            };
        for (int i = 0; i < MAPSIZEROW; i++) {
            for (int j = 0; j < MAPSIZECOL; j++) {
                map[i][j] = templateMap[i][j]; //here we are copying it to our pseudo 2d array, so it can be used in other functions
        }
    }
}

/**
 * Function that assigns data from txt file to an array.
 * @param map int array from main.
 */
void createMapWFile(int map[MAPSIZEROW][MAPSIZECOL]) {
    FILE *mapfile; // File we need to open
    int i; // int to increment during for-loop
    int j; // int to increment during for-loop

    // Checks if the file opens.
    mapfile = fopen("map.txt", "r");
    if (mapfile == NULL) {
        printf("Bruh it ain't readin... we're cooked chat :(\n");
        exit(EXIT_FAILURE);
    }

    // For-loop assigning the file data to the 2D array
    for (i = 0; i < MAPSIZEROW; i++) {
        for (j = 0; j < MAPSIZECOL; j++) {
            // %3 = only loading 3 digets for each location in the array
            fscanf(mapfile, "%3d", &map[i][j]);

        }
    }

    // Closes the file
    fclose(mapfile);
}

//Changes the enum to 10 so we are able to see the shortest route without terrain.
/**
 *
 * @param map all terrain values in map are changed to the same so it will show the shortest rather than the fastest
 */
void shortestRoute(int map[MAPSIZEROW][MAPSIZECOL]) {
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

//Genereates mines that are placed random on the map, and overwrites the value already there
void randomMineGen(int map[MAPSIZEROW][MAPSIZECOL], int amountOfMines) {
    srand(time(NULL));
    int upperBound = MAPSIZE;
    // Set the lower bound for random numbers depending on where the mine can be placed
    int lowerBound = 0;

    //For loop that runs, until all mines are placed
    for (int i = 0; i < amountOfMines; i++) {
        map[rand() % (upperBound - lowerBound + 1)+ lowerBound][rand() % (upperBound - lowerBound + 1)+ lowerBound] = mine;
    }
}

/**
 * Function that prints the map.
 * @param map int array from main.
 */
void printMap(int map[MAPSIZEROW][MAPSIZECOL]) {
    printf("\n");
    // For-loop which prints each value in the array.
    for (int i = 0; i < MAPSIZEROW; i++){
        for (int j = 0; j < MAPSIZEROW; j++){
            printf("%2d ", map[i][j]);
        }
        printf("\n");
    }

}