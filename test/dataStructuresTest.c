#include <assert.h>
#include "../src/dataStructures.h"
#include <float.h>

void test_initEmptyCellMap() {
    //Arrange
    cell_t emptyCellMap[MAPSIZEROW][MAPSIZECOL];
    double tolerance = 0.01;

    //Act
    initEmptyCellMap(emptyCellMap);

    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {

            assert(emptyCellMap[i][j].f - DBL_MAX < tolerance);
            assert(emptyCellMap[i][j].g - DBL_MAX < tolerance);
            assert(emptyCellMap[i][j].h - DBL_MAX < tolerance);

            assert(emptyCellMap[i][j].parentCoor.row == NOPARENTYET);
            assert(emptyCellMap[i][j].parentCoor.col == NOPARENTYET);

            assert(emptyCellMap[i][j].openList == false);
            assert(emptyCellMap[i][j].closedList == false);

        }
    }

}