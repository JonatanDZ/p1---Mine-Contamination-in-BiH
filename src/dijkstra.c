#include "aStar.h"

/**
 * @param map is the containing the different costs of each cell.
 * @param start is the start coordinates chosen in input.
 * @param dest is the destination coordinates chosen in input.
 * @return
 */
int dijkstra(int map[MAPSIZEROW][MAPSIZECOL], coor_t start, coor_t dest) {
    /* 0) Set up */
    //2d array to manage cells and 'lists', initialization
    cell_t cellMap[MAPSIZEROW][MAPSIZECOL];
    initEmptyCellMap(cellMap);

    /* 1) Starting the search with start cell */
    initCellDijkstra(cellMap, start.row, start.col, 0, 0, 0);

    //'Add' to open list
    cellMap[start.row][start.col].openList = true;
    cellMap[start.row][start.col].closedList = false;

    //Coordinates determining current cell.
    int row, col;

    //bool destinationFound = false;
    bool openListIsEmpty = false;

    /* 2) Repeat, while open 'list' is not empty*/
    while (openListIsEmpty == false) {
        //From the 'open' list, find the note with the smallest f value.
        openListIsEmpty = fSearch(cellMap, & row, & col);

        //Remove it from the 'open' list, then add to 'closed' list
        cellMap[row][col].openList = false;
        cellMap[row][col].closedList = true;

        //Breaks the while loop if the destination has been moved to the closed list.
        if (cellMap[dest.row][dest.col].closedList == true) {
            printf("Here is the path that we found.\n");
            tracePath(cellMap, map, dest.row, dest.col, start);
            int gTotal = cellMap[dest.row][dest.col].g;
            printTime(gTotal);
            return gTotal;
        }
        generateSuccessors(cellMap, map, row, col, dest);
    }
    printf("No Path is found.\n");
    return 0;
}

/**
 *This function creates successors from the current cell
 * @param cellMap containing
 * @param map containing the g-cost of every specific cell
 * @param row current row
 * @param col current column
 */
void generateSuccessorsDijkstra(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int map[MAPSIZEROW][MAPSIZECOL], int row, int col) {
    /* For each of the 8 cells surrounding current cell*/
    for (int r = -1; r <= 1; r++) {
        for (int c = -1; c <= 1; c++) {
            //Ensuring center cell is ignored
            if (r != 0 || c != 0) {
                //The successors' coordinates for readability
                int successorRow = row + r;
                int successorCol = col + c;

                //This ensures that walking diagonally has an extra cost which is the increased walking distance
                int successorGCost;
                if (r == 0 || c == 0) {
                    successorGCost = cellMap[row][col].g + map[successorRow][successorCol];
                } else {
                    successorGCost = cellMap[row][col].g + map[successorRow][successorCol] * 1.4;
                }

                //If cell is outside map bounds or already in the closed list, successors do should not be generated.
                //Instead cell is ignored.
                if (isWithinArray(successorRow, successorCol) && cellMap[successorRow][successorCol].closedList == false) {
                    //Also ignore blocked cells
                    if (isUnblocked(map, successorRow, successorCol)) {
                        // a) If it is NOT already in 'open' list, set values & add it to 'open' list.
                        if (cellMap[successorRow][successorCol].openList == false) {
                            initCellDijkstra(cellMap, successorRow, successorCol, successorGCost, row, col);

                            //Add it to the 'open' list
                            cellMap[successorRow][successorCol].openList = true;
                        }

                        // b) If successor IS already in 'open' list, check whether this path is better than previously stored one. Measure by G.cost
                        if (successorGCost < cellMap[successorRow][successorCol].g) {
                            initCellDijkstra(cellMap, successorRow, successorCol, successorGCost, row, col);
                        }
                    }
                }
            }
        }
    }
}