#include "header.h"


int linSearch(cell_t cellList[]) {
    int result = 0;
    for (int i = 0; i < sizeof(cellList); i++) {
        if (cellList[i].f < cellList[result].f) {
            result = i;
        }

    }
    return result;
}