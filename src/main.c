#include "header.h"
#include "aStar.h"
#include "input.h"

int main(){
    coor_t start, dest;
    int map [MAPSIZEROW][MAPSIZECOL];

    //createMapWFile(map);

    //fromNumberToEnum(map);

    createMap(map);


    //randomMineGen(map);
    //shortestRoute(map);
    inputForShortestRouteAndMineGen(map);
    input(map, &start, &dest);

    aStarSearch(map, start, dest);

    //printMap(map);


    terminalOutPut(map);
    //printMapChar(map);


    return 0;
}
