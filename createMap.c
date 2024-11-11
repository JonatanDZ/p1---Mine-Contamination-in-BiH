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
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1, mountain1, mountain1, forest, field, asphalt, asphalt, water, water, water, asphalt, city, city, city, field, field, field, mine, forest, forest, forest, mountain1, mountain1},
            {mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, forest, forest, field, asphalt, water, water, water, asphalt , city, city, city, field, field, field, forest, forest, forest, mountain1, mountain1, mountain2},
            {mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, forest, forest, forest, field, asphalt, water, water, water, asphalt, city, city, city, field, field, field, forest,forest,forest, mountain1, mountain1, mountain2 },
            {mountain2, mountain2, mountain2,mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, mountain1, forest, forest, forest, field, asphalt, asphalt, city, water, water, asphalt, city, city, city, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain2 },
            {mountain2,mountain2,mountain2,mountain2,mountain2, mountain1,mountain1,mountain1,mountain1, forest, forest, field, field, field, asphalt, city, city, water, water, asphalt, city, city, city, field, field, forest, mine, forest, mountain1, mountain1, mountain2, mountain2},
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
            {forest, forest, asphalt, asphalt, water, city, water, city, city, field, mine, city, city, city, city, city, city, field, mine, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2}, //
            {forest, field, asphalt, water, water, city, water, city, field, field, field, field, field, field, field, field, field, field, field, forest, mine, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2}, //
            {field, asphalt, asphalt, water, city, water, water, city, mine, field, field, mine, field, forest, forest, forest, forest, mine, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mine, mountain2, mountain2, mountain2, mountain2}, //
            {field, asphalt, water, water, city, water, city, field, field, field, mine, forest, forest, forest, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2}, //
            {asphalt, asphalt, water, water, city, water, city, mine, field, field, forest, forest, forest, forest, forest, forest, mountain1, mountain1, mountain1, mine, mountain1, mountain1, mountain1, mountain2, mine, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2}, //
            {asphalt, water, water, city, city, water, city, field, mine, forest, mine, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mine, mountain2}, //
            {asphalt, water, water, city, city, water, mine, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mountain2}, //
            };
}

