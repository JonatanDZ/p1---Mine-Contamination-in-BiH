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

void test_initCell() {
    cell_t emptyCellMap[MAPSIZEROW][MAPSIZECOL];
    initEmptyCellMap(emptyCellMap);

    //Arrange
    int test_row = 10;
    int test_col = 10;
    int test_gCost = 15;
    int test_parRow = 9;
    int test_parCol = 9;

    coor_t test_dest = {31, 31};
    double expected_hCost = 819;
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