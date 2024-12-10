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

//isMineable
void test_isMineable_0_4_water() {
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
    bool result = isMineable(map2, test_row,test_col);

    //ASSERT
    assert(result == false);
}
void test_isMineable_0_3_forest() {
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
    bool result = isMineable(map2, test_row,test_col);

    //ASSERT
    assert(result == true);
}
void test_isMineable_4_2_mine() {
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
    bool result = isMineable(map2, test_row,test_col);

    //ASSERT
    assert(result == false);
}
void test_isMineable_0_1_field() {
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
    bool result = isMineable(map2, test_row,test_col);

    //ASSERT
    assert(result == true);
}
void test_isMineable_1_1_asphalt() {
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
    bool result = isMineable(map2, test_row,test_col);

    //ASSERT
    assert(result == false);
}
void test_isMineable_4_3_mountain1() {
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
    bool result = isMineable(map2, test_row,test_col);

    //ASSERT
    assert(result == true);
}
void test_isMineable_4_4_mountain2() {
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
    bool result = isMineable(map2, test_row,test_col);

    //ASSERT
    assert(result == true);
}
void test_isMineable_2_4_startPosition() {
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
    bool result = isMineable(map2, test_row,test_col);

    //ASSERT
    assert(result == true);
}
void test_isMineable_3_4_endPosition() {
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
    bool result = isMineable(map2, test_row,test_col);

    //ASSERT
    assert(result == true);
}

//shortestRoute
void test_shortestRoute() {
    //ARRANGE
    int hardcodedFlatMap[MAPSIZEROW][MAPSIZECOL];
    createFlatMap(hardcodedFlatMap);

    int convertedMap[MAPSIZEROW][MAPSIZECOL];
    createMap(convertedMap);

    //ACT
    shortestRoute(convertedMap);

    //ASSERT
    for (int i = 0; i < MAPSIZEROW; i++) {
        for (int j = 0; j < MAPSIZECOL; j++) {
            assert(hardcodedFlatMap[i][j] == convertedMap[i][j]);
        }
    }
}

void test_shortestRoute_miniMap() {
    //ARRANGE       TODO: In the for loops
    int rowSize = 5;
    int colSize = 5;

    int hardcodedFlatMap[32][32] = {
        {water, asphalt, asphalt, asphalt, water},
        {water, asphalt, asphalt, water, water},
        {asphalt, asphalt, asphalt, asphalt, 10},
        {asphalt, asphalt, asphalt, water, 10},
        {asphalt, asphalt, mine, asphalt, asphalt}
    };

    int convertedMap[32][32] = {
        {water, field, asphalt, forest, water},
        {water, asphalt, forest, water, water},
        {forest, asphalt, city, city, startPosition},
        {asphalt, forest, forest, water, endPosition},
        {forest, asphalt, mine, mountain1, mountain2}
    };

    //ACT
    shortestRoute(convertedMap);

    //ASSERT
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            assert(hardcodedFlatMap[i][j] == convertedMap[i][j]);
        }
    }
}

//isWithin array
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


//isUnblocked, all enum types
void test_isUnblocked_0_4_water() {
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
}
void test_isUnblocked_0_3_forest() {
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
}
void test_isUnblocked_4_2_mine() {
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
}
void test_isUnblocked_0_1_field() {
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
}
void test_isUnblocked_1_1_asphalt() {
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
}
void test_isUnblocked_4_3_mountain1() {
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
}
void test_isUnblocked_4_4_mountain2() {
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
}
void test_isUnblocked_2_4_startPosition() {
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
}
void test_isUnblocked_3_4_endPosition() {
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
}