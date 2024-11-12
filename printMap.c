#include "head.h"

printfmap(int* map, const int mapSize){

    for (int i = 0; i < mapSize; i++){
        for (int j = 0; j < mapSize; j++){
            printf(" %c", map[i * mapSize + j]);
        }
        printf("\n");
    }


}