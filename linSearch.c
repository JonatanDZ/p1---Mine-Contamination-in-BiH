#include "header.h"


int fLinSearch(cell_t cellList[]) {
    int result = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        if ((cellList[i].f < cellList[result].f && cellList[i].f > 0.01)) { //0.0001 is our buffer we have to do this working with floats
            result = i;
        }
    }
    //printf("\nresult from linSearch: %d\n", result);
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

int findParentLinSearch(cell_t parentCellList[], cell_t cell) {
    int result = 0;
    int first = 1;
    for (int i = 0; i < MAXSIZE; i++) {
        if (parentCellList[i].currentCoor.row == cell.parentCoor.row && parentCellList[i].currentCoor.col == cell.parentCoor.col) {
            if (first == 1) {
                first = 0;
                result = i;
            }else if (parentCellList[i].f + 0.00001 < parentCellList[result].f) {
                result = i;

            }
        }
    }
    return result;
}
