#include <assert.h>
#include "../src/map.h"


void test_createMapWFile() {
    //ARRANGE
    int mapHardcoded[MAPSIZEROW][MAPSIZECOL];
    int mapFromFile[MAPSIZEROW][MAPSIZECOL];

    //ACT
    createMap(mapHardcoded);
    createMapWFile(mapFromFile);

    //ASSERT
    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {
            assert(mapHardcoded[i][j] == mapFromFile[i][j]);
        }
    }
}

void test_isWithinArray_5_5() {
    //ARRANGE
    int test_row = 5;
    int test_col = 5;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == true);
}
void test_isWithinArray_50_50() {
    //ARRANGE
    int test_row = 50;
    int test_col = 50;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == false);
}
void test_isWithinArray_neg1_16() {
    //ARRANGE
    int test_row = -1;
    int test_col = 16;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == false);
}
void test_isWithinArray_19_neg20() {
    //ARRANGE
    int test_row = 19;
    int test_col = -20;

    //ACT
    bool result = isWithinArray(test_row,test_col);

    //ASSERT
    assert(result == false);
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