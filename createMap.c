#include "header.h"

void createMap(int map[MAPSIZEROW][MAPSIZECOL]) {
    FILE *mapfile; // File we need to open
    int i; // int to increment during for-loop
    int j; // int to increment during for-loop

    // Checks if the file opens.
    mapfile = fopen("map.txt", "r");
    if (mapfile == NULL) {
        printf("Bruh it ain't readin... we're cooked chat :(\n");
        exit(EXIT_FAILURE);
    }

    // For loop assigning the file data to the 2D array
    for (i = 0; i < MAPSIZEROW; i++) {
        for (j = 0; j < MAPSIZECOL; j++) {
            // %3 = only loading 3 digets for each location in the array
            fscanf(mapfile, "%3d", &map[i][j]);
        }
    }


    // For loop printing the map, add space behind %d for human reading
    for (i = 0; i < MAPSIZEROW; i++) {
        for (j = 0; j < MAPSIZECOL; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }


    // Closes the file
    fclose(mapfile);
}





/*
void createMap(int map[MAPSIZEROW][MAPSIZECOL]){
    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {
            map[i][j] = templateMap[i][j]; //here we are copying it to our pseudo 2d array, so it can be used in other functions
        }
    }
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
}
*/