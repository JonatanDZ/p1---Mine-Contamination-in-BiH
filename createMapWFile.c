#include "header.h"

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