#include "header.h"

/**
 *
 * @param cellMap Provides cell list to search through
 * @param resultR The row
 * @param resultC
 * @return true if no cells were found in open, false if at least one cell was in 'open'
 */
bool fLinSearch(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int* resultR, int* resultC) {
    bool first = true;

    //r & c determine which cell is currently checked through its coordinates, starting from the beginning of the 2d cell array.
    for (int r = 0; r < MAPSIZEROW; r++) {
        for (int c = 0; c < MAPSIZECOL; c++) {

            //Only searching cells within 'open' list. Ignore all others. TODO: What happens with *resultCoor if the following block is never entered?
            if (cellMap[r][c].openList == true) {

                /* To ensure that cells in 'open' are only compared to other cells in open,
                 * the first cell found in 'open' should lay basis for f cost comparison.*/
                if (first == true) {
                    *resultR = r;
                    *resultC = c;
                    first = false;
                }
                /* In all other comparisons after finding the first 'open' cell,
                 * compare the current cell's f cost to the previously found lowest f cost. */
                else if (cellMap[r][c].f < cellMap[*resultR][*resultC].f && cellMap[r][c].f > 0.01) { //0.0001 is our buffer we have to do this working with floats

                    /* If the current cell's f cost is lower than the previously found,
                     *     update result coordinates to the current cell's coordinates */
                    *resultR = r;
                    *resultC = c;
                }
            }
        }
    }
    //If first is returned as true, no cells were found in open. If returned as false, at least one cell was in 'open'
    return first;
}
/*
int gLinSearch(cell_t cellMap[MAPSIZEROW][MAPSIZEROW], int* resultR, int* resultC) {
    int resultR;
    int resultC;
    for (int r = 0; r < MAXSIZE; r++) {
        for (int c = 0; c < MAPSIZECOL; c++) {
            if (cellMap[r][c].openList == true){
                if (cellMap[r][c].currentCoor.row == successorCell.currentCoor.row && cellList[i].currentCoor.col == successorCell.currentCoor.col) {
                    if (successorCell.g < cellList[i].g) {
                        result = i;
                    }
                }
            }


        }
    }
}
*/

/* TODO: find ud af om den er undværlig
int findParentLinSearch(cell_t parentCellList[], cell_t cell) {
    int result = 0;
    bool first = true;
    for (int i = 0; i < MAXSIZE; i++) {
        if (parentCellList[i].currentCoor.row == cell.parentCoor.row && parentCellList[i].currentCoor.col == cell.parentCoor.col) {
            if (first) {
                first = false;
                result = i;

                printf("\n %d Parent Cell", i);
                printCell(parentCellList[result]);
            }else if (parentCellList[i].f + 0.1 < parentCellList[result].f) {
                printf("%d Cell",i);
                printCell(parentCellList[i]);
                result = i;
            }
        }
    }
    return result;
}
*/