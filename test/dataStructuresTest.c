#include <assert.h>
#include "../src/dataStructures.h"
#include <float.h>
#include "../src/aStar.h"

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

//Move to aStarTest
void test_fLinSearch_3open_2not() {

    //Arrange
    int expectedRow = 29;
    int expectedCol = 28;
    int resultRow;
    int resultCol;

    cell_t cMap[MAPSIZEROW][MAPSIZECOL];
    initEmptyCellMap(cMap);

    cMap[29][28].openList = true;
    cMap[29][28].f = 99;
    cMap[5][10].openList = true;
    cMap[5][10].f = 112;
    cMap[12][14].openList = true;
    cMap[12][14].f = 150;

    //Notice not in open, their lower f value should not have any impact
    cMap[4][2].openList = false;
    cMap[4][2].f = 45;
    cMap[18][8].openList = false;
    cMap[18][8].f = 24;

    //ACT
    bool first = fLinSearch(cMap, &resultRow, &resultCol);

    //Assert
    assert(first == false &&
           resultRow == expectedRow &&
           resultCol == expectedCol
           );
}
void test_fLinSearch_noneOpen_firstTrue() {
    //Arrange

    //TODO: Hvad sker i Astar, når der ingen åbne er?
    int expectedRow = -1;
    int expectedCol = -1;
    int resultRow = -1;    //Initialized here, to illustrate that they remain unchanged, when no open elements occur
    int resultCol = -1;

    cell_t cMap[MAPSIZEROW][MAPSIZECOL];
    initEmptyCellMap(cMap);

    //Notice not in open, their lower f value should not have any impact
    cMap[29][28].openList = false;
    cMap[29][28].f = 99;
    cMap[5][10].openList = false;
    cMap[5][10].f = 112;
    cMap[4][2].openList = false;
    cMap[4][2].f = 45;

    //ACT
    bool first = fLinSearch(cMap, &resultRow, &resultCol);

    //Assert
    assert(first == true &&
           resultRow == expectedRow &&
           resultCol == expectedCol
           );
}
void test_fLinSearch_1open_2not() {

    //Arrange
    int expectedRow = 12;
    int expectedCol = 14;
    int resultRow;
    int resultCol;

    cell_t cMap[MAPSIZEROW][MAPSIZECOL];
    initEmptyCellMap(cMap);

    cMap[12][14].openList = true;
    cMap[12][14].f = 150;

    //Notice not in open, their lower f value should not have any impact
    cMap[4][2].openList = false;
    cMap[4][2].f = 45;
    cMap[18][8].openList = false;
    cMap[18][8].f = 24;

    //ACT
    bool first = fLinSearch(cMap, &resultRow, &resultCol);

    //Assert
    assert(first == false &&
           resultRow == expectedRow &&
           resultCol == expectedCol
           );
}
