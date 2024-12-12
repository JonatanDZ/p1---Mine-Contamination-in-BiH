#include "dataStructures.h"

/** Initializes an empty cell map.
 * @param cellMap the array of cells structs to update values within.
 * f,g,h set to max double value allowed.
 * Parents are set NO PARENT YET defined value.
 * Both 'open' and 'closed' booleans are set to false. No cell should be in any of the lists at start.
 */
void initEmptyCellMap(cell_t cellMap[MAPSIZEROW][MAPSIZECOL]) {
    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {
            //To indicate all cells as unexplored:

            //All cells' f, g, h, values set to maximum double allowed
            cellMap[i][j].f = DBL_MAX;
            cellMap[i][j].g = DBL_MAX;
            cellMap[i][j].h = DBL_MAX;

            //Parents set to -1
            cellMap[i][j].parentCoor.row = NOPARENTYET;
            cellMap[i][j].parentCoor.col = NOPARENTYET;

            //Both lists should be empty at start
            cellMap[i][j].openList = false;
            cellMap[i][j].closedList = false;
        }
    }
}

/**
 * This function is initializing the different cell values after they are generated.
 */
void initCell(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int successorRow, int successorCol, int gCost, int parentRow, int parentCol, coor_t dest) {
    cellMap[successorRow][successorCol].parentCoor.row = parentRow;
    cellMap[successorRow][successorCol].parentCoor.col = parentCol;

    //Recalculate & update g and f values. h (estimated distance to dest) will remain the same, so no recalculations needed
    cellMap[successorRow][successorCol].g = gCost;
    cellMap[successorRow][successorCol].h = hCalc(successorRow, successorCol, dest.row, dest.col);
    cellMap[successorRow][successorCol].f = cellMap[successorRow][successorCol].g + cellMap[successorRow][successorCol].h;
}

/**
 * This function is initializing the different cell values after they are generated.
 */
void initCellDijkstra(cell_t cellMap[MAPSIZEROW][MAPSIZECOL], int successorRow, int successorCol, int gCost, int parentRow, int parentCol) {
    cellMap[successorRow][successorCol].parentCoor.row = parentRow;
    cellMap[successorRow][successorCol].parentCoor.col = parentCol;

    //Recalculate & update g and f values. h (estimated distance to dest) will remain the same, so no recalculations needed
    cellMap[successorRow][successorCol].g = gCost;
    cellMap[successorRow][successorCol].h = 0;
    cellMap[successorRow][successorCol].f = cellMap[successorRow][successorCol].g + cellMap[successorRow][successorCol].h;
}

/**
 * This function is calculating h-value.
 * @param row the current row
 * @param col the current col
 * @param destRow the destination row
 * @param destCol the destination col
 * @var D is lowest g-cost you can experience on the map
 * @var D2 is the lowest g-cost you can experience on the map if you move diagonally
 * @return The function returns the cost of moving to the destination without moving diagonally
 * then added with (-) what is saved by making the same move diagonally
 */
double hCalc(int row, int col, int destRow, int destCol) {
    int diffRow = abs(row - destRow);
    int diffCol = abs(col - destCol);
    int D = asphalt;
    double D2 = D * 1.4;
    return D * (diffRow + diffCol) + (D2 - 2 * D) * fmin(diffRow, diffCol);
}