#include <assert.h>

#include "../src/map.h"
#include "test.h"

void test_isWithinArray(void) {
    //ARRANGE
    int test_row = 5;
    int test_col = 5;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == true);
}

void test_isWithinArray_50_50(void) {
    //ARRANGE
    int test_row = 50;
    int test_col = 50;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == false);
}

