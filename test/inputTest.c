#include <assert.h>
#include <stdbool.h>
#include "../src/input.h"



void test_error(void);

int main(void) {
    test_error();
}

void test_error(void) {
//Arrange
    int map[MAPSIZEROW][MAPSIZECOL] = {{0}};
    coor_t start = {0, 0};
    coor_t dest = {30, 30};
//Act
    int expected = false;

    int result = isUnblocked(map, dest.row, dest.col);
    //Asser
    assert(result == expected);
}


