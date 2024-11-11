#include <stdio.h>
#include <stdlib.h>





typedef enum {
    mine = 00,
    water = 00,
    asphalt = 10,
    city = 12,
    field = 15,
    forest = 20,
    mountain1 = 22,
    mountain2 = 27
} moveValue;

void createMap(){
const int mapSize = 32;


int* map = malloc(32 * sizeof(int));

int map[] = {
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain1,mountain1,mountain1,forest,forest, field, asphalt, city, water, water, city, city, asphalt, field,field,field,mine, forest, forest, mine, forest, forest, mine, mountain1, mountain2, mountain2, mountain2},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1,mountain1,forest,forest,asphalt,asphalt, city, water, water, city, asphalt, field, field, field, field,mine,forest,forest,forest,forest,forest,mountain1, mountain1, mountain2, mountain2,},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain1, mountain1, forest, field, asphalt, asphalt, city, water, water, asphalt, asphalt, field, field, field, field, field, field, forest, mine, forest, forest,},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1, forest, forest, field, asphalt, city, water, water, water, asphalt,field,field,field, field, field, mine, field, forest, forest, forest, forest, mountain1, mountain2},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1, mountain1, forest, forest, asphalt, asphalt, water, water, water, asphalt, asphalt, city, field,field,field,field,field,forest, forest, mine, forest, mountain1, mountain1},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {asphalt, asphalt, water, water, city, water, city, mine, field, field, forest, forest, forest, forest, forest, forest, mountain1, mountain1, mountain1, mine, mountain1,  }
            {asphalt, water, water, city, city, water, city, field, mine, forest, mine, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mine, mountain2}, //
            {asphalt, water, water, city, city, water, mine, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mountain2}, //
            };
}

