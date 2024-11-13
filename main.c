#include "header.h"



int main(){
    printf("Hello, from p1---Mine-Contamination-in-BiH!\n\n");

    const int mapSize = 32;
    int* map = malloc((mapSize * mapSize) * sizeof(int));

    createMap(map, mapSize);

    printMap(map, mapSize);

    return 0;
}
