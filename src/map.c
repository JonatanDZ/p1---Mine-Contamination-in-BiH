#include "map.h"
#include "dataStructures.h"

/**
 * Function encapsulating map creation from file, reading and converting to enum.
 * @param map int array from main.
 */
void createMapWFile(int map[MAPSIZEROW][MAPSIZECOL]) {
    readMapFileIntoArray(map);
    fromNumberToEnum(map);
}

/**
 * Function that assigns data from txt file to an array.
 * @param map int array from main.
 */
void readMapFileIntoArray(int map[MAPSIZEROW][MAPSIZECOL]) {
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

/**
 * A function converting the array from the txt file data to our defined enums.
 * @param map int array from main.
 */
void fromNumberToEnum(int map[MAPSIZEROW][MAPSIZECOL]) {
    // For-loop with a switch that converts ints to enums.
    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {
            switch (map[i][j]) {
            case 167:
                map[i][j] = mine;
                break;
            case 247:
                map[i][j] = water;
                break;
            case 223:
                map[i][j] = asphalt;
                break;
            case 202:
                map[i][j] = city;
                break;
            case 173:
                map[i][j] = field;
                break;
            case 216:
                map[i][j] = forest;
                break;
            case 133:
                map[i][j] = mountain1;
                break;
            case 142:
                map[i][j] = mountain2;
                break;
            case 00:
                map[i][j] = startPosition;
                break;
            case 01:
                map[i][j] = endPosition;
                break;
            default:
                map[i][j] = 150; //er for path værdien
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

    mapMineReplace(map);

    //while loop that runs, until all mines are placed
    int i = 0;
    while (i < amountOfMines) {
        int row = rand() % (upperBound - lowerBound + 1)+ lowerBound;
        int col = rand() % (upperBound - lowerBound + 1)+ lowerBound;
        //If statement that decides if the mine can be placed
        if (isMineable(map, row, col) == true) {
            map[row][col] = mine;
            i++;
        }
    }
}

void mapMineReplace(int map[MAPSIZEROW][MAPSIZECOL]) {
    map[0][21] = forest;
    map[0][24] = forest;
    map[0][27] = mountain1;
    map[1][22] = forest;
    map[2][26] = forest;
    map[3][24] = field;
    map[4][28] = forest;
    map[5][26] = forest;
    map[9][26] = forest;
    map[11][24] = forest;
    map[13][26] = forest;
    map[14][24] = field; //Virker kun med den under
    map[15][24] = field; //Virker kun med den over
    map[16][22] = field;
    map[16][26] = forest;
    map[23][19] = city;
    map[24][21] = field;
    map[25][10] = city;
    map[25][18] = field;
    map[26][20] = forest;
    map[27][8] = field;
    map[27][11] = field;
    map[27][17] = forest;
    map[27][27] = mountain1;
    map[28][10] = field;
    map[28][29] = mountain2;
    map[29][7] = field;
    map[29][19] = mountain1;
    map[29][24] = mountain2;
    map[30][8] = field;
    map[30][10] = forest;
    map[30][26] = mountain2;
    map[30][30] = mountain2;
    map[31][6] = city;
    map[31][23] = mountain2;
    map[31][27] = mountain2;
}

/**
 *
 * @param map int array from main
 * @param row Int indicating which row in the array that should be looked up
 * @param col Ind indicating which column in the array that should be looked up
 * @return True or false whether amine can be place in the array
 */
bool isMineable(int map[MAPSIZEROW][MAPSIZECOL], int row, int col) {
    if (map[row][col] == water || map[row][col] == mine || map[row][col] == asphalt || map[row][col] == city) {
        return false;
    }
    return true;
}

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
                map[i][j] = asphalt;
                break;
            case city:
                map[i][j] = asphalt;
                break;
            case field:
                map[i][j] = asphalt;
                break;
            case forest:
                map[i][j] = asphalt;
                break;
            case mountain1:
                map[i][j] = asphalt;
                break;
            case mountain2:
                map[i][j] = asphalt;
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

/**
 * Utility function determining whether a not a given input is within the 2d array.
 * @param row Input, row to check.
 * @param col Input, col to check.
 * @return true if within, else returns false.
 */
bool isWithinArray(int row, int col) {
    if (row >= 0 && row < MAPSIZEROW && col >= 0 && col < MAPSIZECOL) {
        return true;
    }
    return false;
}

/**
 * Function that checks if a cell in the array is blocked i.e. untraversable.
 * @param map Int array from main.
 * @param row Int indicating which row in the array should be looked up.
 * @param col Int indication which column in the arary should be looked up.
 * @return True or false whether the location in the array is traversable.
 */
bool isUnblocked(int map[MAPSIZEROW][MAPSIZECOL], int row, int col) {
    if (map[row][col] == water || map[row][col] == mine) {
        return false;
    }
    return true;
}

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
                    printf("\033[38;5;196mXX \033[0m");
                break;
                case water:
                    printf("\033[38;5;32m~~ \033[0m");
                break;
                case asphalt:
                    printf("\033[38;5;214mMM \033[0m");
                break;
                case city:
                    printf("\033[38;5;231mMM \033[0m");
                break;
                case field:
                    printf("\033[38;5;46mWW \033[0m");
                break;
                case forest:
                    printf("\033[38;5;22mTT \033[0m");
                break;
                case mountain1:
                    printf("\033[28;5;8mMM \033[0m");
                break;
                case mountain2:
                    printf("\033[38;5;7mMM \033[0m");
                break;
                case startPosition:
                    printf("\033[38;5;213mMM \033[0m");
                break;
                case endPosition:
                    printf("\033[38;5;213mMM \033[0m");
                break;
                default:
                    printf("\033[38;5;213mMM \033[0m");
            }
        }
    }
    printf("\n");
}



/* TODO: --- ONLY USED FOR TESTING --- */
/** Copies hardcoded array into provided array argument.
 *
 */
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

/* TODO: --- UNUSED FUNCTIONS --- */
/**
 * Utility function determining whether a not a given input is the destination.
 * @param row Input, row to check.
 * @param col Input, col to check.
 * @return true if within, else returns false.
 */
bool isDestination(int row, int col, int destRow, int destCol) {
    return row == destRow && col == destCol;
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
