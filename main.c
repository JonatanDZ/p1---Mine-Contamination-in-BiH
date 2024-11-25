#include "header.h"

int main(){
    /*const int mapSize = 32;
    int destRow;
    int destCol;

    //Vi laver et h map, hvor h-værdien af hvert felt er givet
    double* hMap = malloc((mapSize * mapSize) * sizeof(double));

    ifObstacle(map, 0, 12);
    createMap(map);
*/
    int map [MAPSIZEROW][MAPSIZECOL];
    createMap(map);
   // input(map, mapSize, &destRow, &destCol);

    //Denne funktion sætter h-værdi på et hvert felt tilsvarende til map
    //insertH(hMap, destRow, destCol);



    return 0;
}
