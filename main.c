#include "header.h"






int main(){
    const int mapSize = 32;
    int destRow;
    int destCol;
    int* map = malloc((mapSize * mapSize) * sizeof(int));
    double* hMap = malloc((mapSize * mapSize) * sizeof(double));

    createMap(map, mapSize);

    input(map, mapSize, &destRow, &destCol);

    insertH(hMap, destRow, destCol);





    printMap(hMap, mapSize);


    return 0;
}
