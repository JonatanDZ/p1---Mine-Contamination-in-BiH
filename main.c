#include "header.h"

int main(){
    const int mapSize = 32;
    int* map = malloc((mapSize * mapSize) * sizeof(int));

    createMap(map, mapSize);


    // Starter fra 0, så minus en for koordinat.
    int startPosistion = 10000;
    int startInputX;
    int startInputY;

    printf("Input x og y koordinat for start koordinator");
    scanf(" %c %c", &startInputX, &startInputY);

    map[startInputX * mapSize + startInputY] = startPosistion;

    int endPosistion = 10000;
    int endInputX;
    int endInputY;

    printf("Input x og y koordinat for end koordinator");
    scanf(" %c%c", &endInputX, &endInputY);

    map[endInputX * mapSize + endInputY] = endPosistion;
    
    printMap(map, mapSize);


    return 0;
}
