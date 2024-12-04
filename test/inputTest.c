#include <assert.h>
#include <stdbool.h>  // For 'false'
#include "../src/input.h"  // Assuming input.h declares 'input' and 'coor_t'



void test_error(void);

int main(void) {
    test_error();
}

void test_error(void) {
    int map[MAPSIZEROW][MAPSIZECOL] = {{0}};  // Example 2D array initialization
    coor_t start = {0, 0};
    coor_t dest = {1, 1};

    int expected = false;  // Assuming 'false' represents an error code

    int result = input(map, &start, &dest);
    assert(result == expected);
}
