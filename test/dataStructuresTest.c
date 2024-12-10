#include <assert.h>
#include "../src/dataStructures.h"
#include <float.h>

//initEmptyCellMap
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

//initCell
void test_initCell_rc00_d2525() {
    cell_t emptyCellMap[MAPSIZEROW][MAPSIZECOL];

    //Arrange
    int test_row = 0;
    int test_col = 0;
    int test_gCost = 45;
    int test_parRow = 1;
    int test_parCol = 1;
    coor_t test_dest = {25, 25};

    double expected_hCost = 525;
    double tolerance = 0.1;

    //Act
    initCell(emptyCellMap, test_row, test_col, test_gCost, test_parRow, test_parCol, test_dest);

    //Assert
    assert(emptyCellMap[test_row][test_col].parentCoor.row == test_parRow);
    assert(emptyCellMap[test_row][test_col].parentCoor.col == test_parCol);

    assert(emptyCellMap[test_row][test_col].g == test_gCost);
    assert(fabs(emptyCellMap[test_row][test_col].h - expected_hCost) < tolerance );
    assert(fabs(emptyCellMap[test_row][test_col].f - (test_gCost + expected_hCost) < tolerance));
}