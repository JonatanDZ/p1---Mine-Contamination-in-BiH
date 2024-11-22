#include "header.h"


int fLinSearch(cell_t cellList[]) {
    int result = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        if ((cellList[i].f < cellList[result].f && cellList[i].f > 0.01)) { //0.0001 is our buffer we have to do this working with floats
            result = i;
        }
    }
    printf("\nresult from linSearch: %d\n", result);
    return result;
}

int gLinSearch(cell_t cellList[], cell_t successorCell) {
    int result = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        if (cellList[i].currentCoor.row == successorCell.currentCoor.row && cellList[i].currentCoor.col == successorCell.currentCoor.col) {
            if (successorCell.g < cellList[i].g) {
                result = i;
            }
        }

    }
    return result;
}