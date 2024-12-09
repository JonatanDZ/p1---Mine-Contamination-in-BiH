#include "dataStructures.h"
#include "map.h"
#include "input.h"
#include "aStar.h"

int main(){
    coor_t start, dest;
    int map [MAPSIZEROW][MAPSIZECOL];

    createMapWFile(map);

    input(map, &start, &dest);

    aStarSearch(map, start, dest);

    terminalOutPut(map);

    return 0;
}
