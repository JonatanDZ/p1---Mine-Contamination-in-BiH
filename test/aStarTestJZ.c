
#include <assert.h>
#include <stdio.h>
#include "../src/aStar.h"

void testIsDestination0() {
    int testRow = 20;
    int testCol = 20;

    coor_t test_t;
    test_t.row = 20;
    test_t.col = 20;

    //ACT
    bool result = isDestination(testRow, testCol, test_t);

    //ASSERT
    assert(result == true);
}

void testIsDestination1() {
    int testRow = 10;
    int testCol = 10;

    coor_t test_t;
    test_t.row = 20;
    test_t.col = 20;

    //ACT
    bool result = isDestination(testRow, testCol, test_t);

    //ASSERT
    assert(result == false);
}