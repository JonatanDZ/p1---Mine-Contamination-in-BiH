#include "head.h"

int main(){
    printf("Hello, from p1---Mine-Contamination-in-BiH!\n\n");

    const int mapSize = 32;
    int* map = malloc((mapSize * mapSize) * sizeof(int));

    createMap(map, mapSize);

    //printMap(map, mapSize);

    for (int i = 0; i < mapSize; i++){
        for (int j = 0; j < mapSize; j++){
            printf(" %c", map[i * mapSize + j]);
        }
        printf("\n");
    }

    return 0;
}
