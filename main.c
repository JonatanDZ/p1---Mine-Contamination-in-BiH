#include "header.h"

int main(){
    const int mapSize = 32;
    int destRow;
    int destCol;
    int* map = malloc((mapSize * mapSize) * sizeof(int));
    //Vi laver et h map, hvor h-værdien af hvert felt er givet
    double* hMap = malloc((mapSize * mapSize) * sizeof(double));

    ifObstacle(map, 2, 2);
    createMap(map, mapSize);

    input(map, mapSize, &destRow, &destCol);

    //Denne funktion sætter h-værdi på et hvert felt tilsvarende til map
    insertH(hMap, destRow, destCol);





    printMap(hMap, mapSize);


    return 0;
}
