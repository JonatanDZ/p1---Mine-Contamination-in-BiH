#include <assert.h>
#include "../src/map.h"
#include <stdio.h>

bool assertion(void* input, void* expected);
bool test_isWithinArray(void) {
    //ARRANGE, from input
    int test_row = 5;
    int test_col = 5;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    return assertion((bool*)result ,(bool*)true);
}

bool assertion(void* input, void* expected) {
    if (input == expected) {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    printf("%d",test_isWithinArray());

}
