#include "header.h"

int main(){
    coor_t start, dest;
    int map [MAPSIZEROW][MAPSIZECOL];

    //createMapWFile(map);

    //fromNumberToEnum(map);

    createMap(map);


    randomMineGen(map);
    shortestRoute(map);

    input(map, &start, &dest);

    aStarSearch(map, start, dest);

    printMap(map);



    return 0;
}
