#include "aStar.h"
#include "input.h"
#include "dataStructures.h"
#include "map.h"

int main(){
    coor_t start, dest;
    int map [MAPSIZEROW][MAPSIZECOL];
    int mapWithoutMine [MAPSIZEROW][MAPSIZECOL];

    //createMapWFile(map);

    //fromNumberToEnum(map);

    createMap(map);
    createMap(mapWithoutMine);

    inputForShortestRouteAndMineGen(map);

    input(map, &start, &dest);

    aStarSearch(map, start, dest);

    terminalOutPut(map);


    return 0;
}
