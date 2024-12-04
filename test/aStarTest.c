#include <assert.h>
#include "../src/map.h"


void test_isWithinArray(void) {
    //ARRANGE, from input
    int test_row = 5;
    int test_col = 5;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == true);
}



int main(void) {
    test_isWithinArray();

}
