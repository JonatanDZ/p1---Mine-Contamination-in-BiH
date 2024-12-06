#include <assert.h>
#include "../src/map.h"


void test_isWithinArray_5_5() {
    //ARRANGE
    int test_row = 5;
    int test_col = 5;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == true);
}

void test_isWithinArray_50_50() {
    //ARRANGE
    int test_row = 50;
    int test_col = 50;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == false);
}

void test_isWithinArray_neg1_16() {
    //ARRANGE
    int test_row = -1;
    int test_col = 16;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == false);
}

void test_isWithinArray_19_neg20() {
    //ARRANGE
    int test_row = 19;
    int test_col = -20;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == false);
}

void test_createMapWFile() {
    //ARRANGE
    int mapHardcoded[MAPSIZEROW][MAPSIZECOL];
    int mapFromFile[MAPSIZEROW][MAPSIZECOL];

    //ACT
    createMap(mapHardcoded);
    createMapWFile(mapFromFile);

    //ASSERT
    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {
            assert(mapHardcoded[i][j] == mapFromFile[i+1][j]);
        }
    }
}