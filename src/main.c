#include "dataStructures.h"
#include "map.h"
#include "input.h"
#include "aStar.h"

int main(){
    coor_t start, dest;
    int map [MAPSIZEROW][MAPSIZECOL];

    createMapWFile(map);

    input(map, &start, &dest);
    
    for (int r = 0; r < MAPSIZEROW; r++){
        for (int c = 0; c < MAPSIZECOL; c++){
            printf(" %3.0lf", hCalc(r, c, dest.row, dest.col));
        }
        printf("\n");
    }
    
    return 0;
}
