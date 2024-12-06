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

bool test_isUnblocked0_4water(void) {
    //ARRANGE
    int test_row = 0;
    int test_col = 4;
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

bool test_isUnblocked0_3forest(void) {
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

bool test_isUnblocked2_4mine(void) {
    //ARRANGE
    int test_row = 2;
    int test_col = 4;
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


bool test_isUnblocked0_1field(void) {
    //ARRANGE
    int test_row = 0;
    int test_col = 1;
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



bool test_isUnblocked1_1asphalt(void) {
    //ARRANGE
    int test_row = 1;
    int test_col = 1;
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



int main(void) {
    printf("Is Within Array 5,5: %d\n",test_isWithinArray5_5());
    printf("Is Within Array 7,55: %d\n",test_isWithinArray7_55());
    printf("Is Unblocked 0,4 water: %d\n", test_isUnblocked0_4water());
    printf("Is Unblocked 0,3 forest: %d\n", test_isUnblocked0_3forest());
    printf("Is Unblocked 2,4 mine: %d\n", test_isUnblocked2_4mine());
    printf("Is Unblocked 0,1 field: %d\n", test_isUnblocked0_1field());
    printf("Is Unblocked 1,1 asphalt: %d\n", test_isUnblocked1_1asphalt());
}
