#include "aStar.h"
#include "input.h"
#include "dataStructures.h"
#include "map.h"

int main(){
    coor_t start, dest;
    int map [MAPSIZEROW][MAPSIZECOL];

    //createMapWFile(map);

    //fromNumberToEnum(map);

    createMap(map);

    inputForShortestRouteAndMineGen(map);

    input(map, &start, &dest);

    aStarSearch(map, start, dest);

    terminalOutPut(map);


    return 0;
}
