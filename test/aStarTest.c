#include <assert.h>
#include "../src/map.h"

void test_isWithinArray() {
    //ARRANGE, from input
    int test_row = 0;
    int test_col = 0;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == true);
}
