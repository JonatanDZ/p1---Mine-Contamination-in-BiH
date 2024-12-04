#include <assert.h>
#include "../src/map.h"
#include <stdio.h>


bool test_isWithinArray5_5(void) {
    //ARRANGE, from input
    int test_row = 5;
    int test_col = 5;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == true);

    return result;
}

bool test_isWithinArray7_55(void) {
    //ARRANGE, from input
    int test_row = 7;
    int test_col = 55;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == false);

    return result;
}





int main(void) {
    printf("Is Within Array 5,5: %d",test_isWithinArray5_5());
    printf("Is Within Array 7,55: %d",test_isWithinArray7_55());
}
