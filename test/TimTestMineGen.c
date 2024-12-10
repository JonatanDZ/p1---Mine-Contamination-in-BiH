#include <assert.h>
#include "../src/map.h"

void test_randomMineGen500() {
    //ARRANGE
    int map[MAPSIZEROW][MAPSIZECOL];
    int expected = 500;
    int mineAmount = 0;

    //ACT
    createMap(map);
    randomMineGen(map, expected);

    for(int i = 0; i < MAPSIZEROW; i++) {
        for(int j = 0; j < MAPSIZECOL; j++) {
            if(map[i][j] == mine){
                mineAmount++;
            }
        }
    }
    printf("%d", mineAmount);
    //ASSSERT
    assert(mineAmount == expected);
}
void test_randomMineGen250() {
    //ARRANGE
    int map[MAPSIZEROW][MAPSIZECOL];
    int expected = 250;
    int mineAmount = 0;

    //ACT
    createMap(map);
    randomMineGen(map, expected);

    for(int i = 0; i < MAPSIZEROW; i++) {
        for(int j = 0; j < MAPSIZECOL; j++) {
            if(map[i][j] == mine){
                mineAmount++;
            }
        }
    }
    printf("%d", mineAmount);
    //ASSSERT
    assert(mineAmount == expected);
}

void test_randomMineGen146() {
    //ARRANGE
    int map[MAPSIZEROW][MAPSIZECOL];
    int expected = 146;
    int mineAmount = 0;

    //ACT
    createMap(map);
    randomMineGen(map, expected);

    for(int i = 0; i < MAPSIZEROW; i++) {
        for(int j = 0; j < MAPSIZECOL; j++) {
            if(map[i][j] == mine){
                mineAmount++;
            }
        }
    }
    printf("%d", mineAmount);
    //ASSSERT
    assert(mineAmount == expected);
}

void test_randomMineGen27() {
    //ARRANGE
    int map[MAPSIZEROW][MAPSIZECOL];
    int expected = 27;
    int mineAmount = 0;

    //ACT
    createMap(map);
    randomMineGen(map, expected);

    for(int i = 0; i < MAPSIZEROW; i++) {
        for(int j = 0; j < MAPSIZECOL; j++) {
            if(map[i][j] == mine){
                mineAmount++;
            }
        }
    }
    printf("%d", mineAmount);
    //ASSSERT
    assert(mineAmount == expected);
}