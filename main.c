#include "header.h"

#define MAPSIZEROW 32
#define MAPSIZECOL 32

typedef struct {
    

}, cell;


int main(){
    const int mapSize = 32;
    int* map = malloc((mapSize * mapSize) * sizeof(int));

    createMap(map, mapSize);

    input(map, mapSize);

    printMap(map, mapSize);


    return 0;
}
