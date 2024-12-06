#include <assert.h>
#include "../src/map.h"
#include <stdio.h>
#include "../src/input.h"


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

bool test_isUnblocked0_5(void) {
    //ARRANGE
    int test_row = 0;
    int test_col = 5;
    int map2[5][5] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, forest, forest, water},
        {asphalt, forest, forest, water, water},
        {forest, asphalt, mine, water, forest}
        };
    //ACT
    bool result = isUnblocked(map2, test_row,test_col);

    //ASSERT
    assert(result == false);

    return result;
}

bool test_isUnblocked0_3(void) {
    //ARRANGE
    int test_row = 0;
    int test_col = 3;
    int map2[5][5] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, forest, forest, water},
        {asphalt, forest, forest, water, water},
        {forest, asphalt, mine, water, forest}
    };
    //ACT
    bool result = isUnblocked(map2, test_row,test_col);

    //ASSERT
    assert(result == true);

    return result;
}

bool test_isUnblocked3_5(void) {
    //ARRANGE
    int test_row = 3;
    int test_col = 5;
    int map2[5][5] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, forest, forest, water},
        {asphalt, forest, forest, water, water},
        {forest, asphalt, mine, water, forest}
    };
    //ACT
    bool result = isUnblocked(map2, test_row,test_col);

    //ASSERT
    assert(result == false);

    return result;
}




int main(void) {
    printf("Is Within Array 5,5: %d\n",test_isWithinArray5_5());
    printf("Is Within Array 7,55: %d\n",test_isWithinArray7_55());
    printf("Is Unblocked 0,5: %d\n", test_isUnblocked0_5());
    printf("Is Unblocked 0,3: %d\n", test_isUnblocked0_3());
    printf("Is Unblocked 3,5: %d\n", test_isUnblocked3_5());


}
