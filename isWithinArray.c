//
// Created by a-bti on 20/11/2024.
//
#include <assert.h>
#include <stdbool.h>

#include "header.h"

bool isWithinArray(int row, int col) {
    if (row >= 0 && row < ROW && col >= 0 && col < COL) {
        return true;
    }
    return false;
}

void test_isWithinArray(const int test_row, const int test_column) {
    //ARRANGE, from input

    //ACT
    bool result = isWithinArray(test_row,test_column);

    //ASSERT
    assert(result == true);
}
