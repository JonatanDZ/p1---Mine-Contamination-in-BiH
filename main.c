#include "header.h"

int main(){
    const int mapSize = 32;
    coor_t start, dest;
    int map [MAPSIZEROW][MAPSIZECOL];
    //Vi laver et h map, hvor h-værdien af hvert felt er givet
    double hMap [MAPSIZEROW][MAPSIZECOL];


    createMap(map);



    input(map, mapSize, &start, &dest);

    //Denne funktion sætter h-værdi på et hvert felt tilsvarende til map
    //insertH(hMap, dest);

    aStarSearch(map, start, dest);





   printMap(map);



    return 0;
}
