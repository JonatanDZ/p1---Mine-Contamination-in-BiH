#include "header.h"

int main(){
    coor_t start, dest;
    int map [MAPSIZEROW][MAPSIZECOL];

    //Map with a file
    //createMapWFile(map);
    //fromNumberToEnum(map);

    //map from hardcode.
    createMap(map);

    //input for the shortest route and random mine gen functions.
    inputForShortestRouteAndMineGen(map);
    input(map, &start, &dest);

    //aStarSearch(map, start, dest);

    //print map without special char
    printMap(map);

    //converts the normal map to specefic chars.
    terminalOutPut(map);
    //prints the new map with special chars.
    printMapChar(map);

    return 0;
}
