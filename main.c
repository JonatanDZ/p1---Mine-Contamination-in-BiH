#include "header.h"

int main(){
    const int mapSize = 32;
    coor_t start, dest;
    int map [MAPSIZEROW][MAPSIZECOL];

    //createMapWFile(map);

    //fromNumberToEnum(map);

    createMap(map);


    randomMineGen(map);
    shortestRoute(map);

    input(map, mapSize, &start, &dest);

    aStarSearch(map, start, dest);

    printMap(map);


    terminalOutPut(map);
    printMapChar(map);

    return 0;
}
