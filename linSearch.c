#include "header.h"


int fLinSearch(cell_t cellList[]) {
    int result = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        if (cellList[i].f <= cellList[result].f && cellList[i].f > 0.000001 ) {
            result = i;
        }
    }
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