#include <assert.h>
#include "../src/map.h"
#include <stdio.h>

bool assertion(int expression);
bool test_isWithinArray(void) {
    //ARRANGE, from input
    int test_row = 5;
    int test_col = 5;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    return assertion(result == true);
}

bool assertion(int expression) {
    if (expression) {
        return true;
    }
    return false;
}

int main(void) {
    printf("%d",test_isWithinArray());

}
