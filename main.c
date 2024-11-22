#include "header.h"

int main(){
    const int mapSize = 32;
    int destRow;
    int destCol;
    int map [MAPSIZEROW][MAPSIZECOL];
    //Vi laver et h map, hvor h-værdien af hvert felt er givet
    double* hMap = malloc((mapSize * mapSize) * sizeof(double));

    createMap(map);
    ifObstacle(map, 0, 13);
   // input(map, mapSize, &destRow, &destCol);

    //Denne funktion sætter h-værdi på et hvert felt tilsvarende til map
    //insertH(hMap, destRow, destCol);





    printMap(map);
    terminalOutPut(map);
    printMapChar(map);
    return 0;
}
