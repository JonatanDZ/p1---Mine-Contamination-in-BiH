#include <stdio.h>
#include <stdlib.h>

void createMap(){



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


const int mapSize = 32;


int* map = malloc(32 * sizeof(int));

int map[] = {
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain1,mountain1,mountain1,forest,forest, field, asphalt, city, water, water, city, city, asphalt, field,field,field,mine, forest, forest, mine, forest, forest, mine, mountain1, mountain2, mountain2, mountain2},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1,mountain1,forest,forest,asphalt,asphalt, city, water, water, city, asphalt, field, field, field, field,mine,forest,forest,forest,forest,forest,mountain1, mountain1, mountain2, mountain2,},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            };

}


controlListLength(){


    
}

int index = 0;

for () {

    index++;
}
printf("L = %d", intdex);