#include "header.h"


int main(){
    const int mapSize = 32;
    int* map = malloc((mapSize * mapSize) * sizeof(int));

    ifObstacle(map, 2, 2);
    createMap(map, mapSize);

    input(map, mapSize);

    printMap(map, mapSize);


    return 0;
}
