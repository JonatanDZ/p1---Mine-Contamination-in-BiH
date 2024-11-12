#include <stdlib.h>
#include <stdio.h>

typedef enum {
    mine = 167,
    water = 247,
    asphalt = 223,
    city = 202,
    field = 173,
    forest = 216,
    mountain1 = 133,
    mountain2 = 142
} moveValue;


void createMap(int* map, const int mapSize){


    int templateMap[32][32] = {
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
        for (int i = 0; i < mapSize; i++) {
            for (int j = 0; j < mapSize; j++) {
                map[i * mapSize + j] = templateMap[i][j];
        }
    }
}

int main(){
    printf("Hello, from p1---Mine-Contamination-in-BiH!\n\n");

    const int mapSize = 32;
    int* map = malloc((mapSize * mapSize) * sizeof(int));

    createMap(map, mapSize);

    //printMap(map, mapSize);

    for (int i = 0; i < mapSize; i++){
        for (int j = 0; j < mapSize; j++){
            printf(" %d", map[i * mapSize + j]);
        }
        printf("\n");
    }

    
    return 0;
}
