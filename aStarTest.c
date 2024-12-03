#include "src/header.h"

void test_isWithinArray(const int test_row, const int test_column) {
    //ARRANGE, from input

    //ACT
    bool result = isWithinArray(test_row,test_column);

    //ASSERT
    assert(result == true);
}

