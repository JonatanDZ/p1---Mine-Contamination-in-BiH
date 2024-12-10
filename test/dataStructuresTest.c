#include <assert.h>
#include "../src/dataStructures.h"

void test_initEmptyCellMap() {
    //Arrange
    cell_t emptyCellMap[MAPSIZEROW][MAPSIZECOL];

    //Act
    initEmptyCellMap(emptyCellMap);

    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {

            assert(emptyCellMap[i][j].parentCoor.row == NOPARENTYET);
            assert(emptyCellMap[i][j].parentCoor.col == NOPARENTYET);

            assert(emptyCellMap[i][j].parentCoor.row == NOPARENTYET);
            assert(emptyCellMap[i][j].parentCoor.col == NOPARENTYET);

            assert(emptyCellMap[i][j].openList == false);
            assert(emptyCellMap[i][j].closedList == false);
        }
    }

}