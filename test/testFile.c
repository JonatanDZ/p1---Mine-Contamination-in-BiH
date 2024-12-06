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
    int map2[32][32] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, city, city, startPosition},
        {asphalt, forest, forest, water, endPosition},
        {forest, asphalt, mine, mountain1, mountain2}
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
    int map2[32][32] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, city, city, startPosition},
        {asphalt, forest, forest, water, endPosition},
        {forest, asphalt, mine, mountain1, mountain2}
    };
    //ACT
    bool result = isUnblocked(map2, test_row,test_col);

    //ASSERT
    assert(result == true);

    return result;
}

bool test_isUnblocked4_2mine(void) {
    //ARRANGE
    int test_row = 4;
    int test_col = 2;
    int map2[32][32] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, city, city, startPosition},
        {asphalt, forest, forest, water, endPosition},
        {forest, asphalt, mine, mountain1, mountain2}
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
    int map2[32][32] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, city, city, startPosition},
        {asphalt, forest, forest, water, endPosition},
        {forest, asphalt, mine, mountain1, mountain2}
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
    int map2[32][32] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, city, city, startPosition},
        {asphalt, forest, forest, water, endPosition},
        {forest, asphalt, mine, mountain1, mountain2}
    };
    //ACT
    bool result = isUnblocked(map2, test_row,test_col);

    //ASSERT
    assert(result == true);

    return result;
}

bool test_isUnblocked4_3mountain1(void) {
    //ARRANGE
    int test_row = 4;
    int test_col = 3;
    int map2[32][32] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, city, city, startPosition},
        {asphalt, forest, forest, water, endPosition},
        {forest, asphalt, mine, mountain1, mountain2}
    };
    //ACT
    bool result = isUnblocked(map2, test_row,test_col);

    //ASSERT
    assert(result == true);

    return result;
}

bool test_isUnblocked4_4mountain2(void) {
    //ARRANGE
    int test_row = 4;
    int test_col = 4;
    int map2[32][32] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, city, city, startPosition},
        {asphalt, forest, forest, water, endPosition},
        {forest, asphalt, mine, mountain1, mountain2}
    };
    //ACT
    bool result = isUnblocked(map2, test_row,test_col);

    //ASSERT
    assert(result == true);

    return result;
}

bool test_isUnblocked2_4startPosition(void) {
    //ARRANGE
    int test_row = 2;
    int test_col = 4;
    int map2[32][32] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, city, city, startPosition},
        {asphalt, forest, forest, water, endPosition},
        {forest, asphalt, mine, mountain1, mountain2}
    };
    //ACT
    bool result = isUnblocked(map2, test_row,test_col);

    //ASSERT
    assert(result == true);

    return result;
}

bool test_isUnblocked3_4endPosition(void) {
    //ARRANGE
    int test_row = 3;
    int test_col = 4;
    int map2[32][32] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, city, city, startPosition},
        {asphalt, forest, forest, water, endPosition},
        {forest, asphalt, mine, mountain1, mountain2}
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
    printf("Is Unblocked 4,2 mine: %d\n", test_isUnblocked4_2mine());
    printf("Is Unblocked 0,1 field: %d\n", test_isUnblocked0_1field());
    printf("Is Unblocked 1,1 asphalt: %d\n", test_isUnblocked1_1asphalt());
    printf("Is Unblocked 4,3 mountain1: %d\n", test_isUnblocked4_3mountain1());
    printf("Is Unblocked 4,4 mountain1: %d\n", test_isUnblocked4_4mountain2());
    printf("Is Unblocked 2,4 Start position: %d\n", test_isUnblocked2_4startPosition());
    printf("Is Unblocked 3,4 Start position: %d\n", test_isUnblocked3_4endPosition());

}
