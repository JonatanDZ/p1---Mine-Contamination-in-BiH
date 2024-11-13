#include "header.h"

int main(){
    const int mapSize = 32;
    int* map = malloc((mapSize * mapSize) * sizeof(int));

    createMap(map, mapSize);

    input(map, mapSize);

    printMap(map, mapSize);


    return 0;
}
