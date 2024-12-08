
#include <assert.h>
#include <stdio.h>
#include "../src/aStar.h"

void testIsDestination0() {
    int testRow = 20;
    int testCol = 20;


    int destRow = 20;
    int destCol = 20;

    //ACT
    bool result = isDestination(testRow, testCol, destRow, destCol);

    //ASSERT
    assert(result == true);
}

void testIsDestination1() {
    int testRow = 10;
    int testCol = 10;

    int destRow = 20;
    int destCol = 20;

    //ACT
    bool result = isDestination(testRow, testCol, destRow, destCol);

    //ASSERT
    assert(result == false);
}