#include "../src/aStar.h"
//#include <assert.h>

void aStarRouteTest_s0100_d0004() {
    //ARRANGE
    coor_t start;
    start.row = 1;
    start.col = 0;

    coor_t dest;
    dest.row = 0;
    dest.col = 4;

    int map[MAPSIZEROW][MAPSIZECOL] = {
        {water, water, mountain2, mountain1, asphalt},
        {asphalt, asphalt, mountain2, mountain2, asphalt},
        {asphalt, asphalt, asphalt, asphalt, water},
        {mine, mine, mountain2, asphalt, water},
        {mountain2, mountain1, mountain1, mountain2, mine}
    };


    int manualCalc = 87;

    //ACT
    int aStarCalc = aStarSearch(map, start, dest);

    //ASSERT
    assert(manualCalc == aStarCalc);
}

void aStarRouteTest_s0400_d0101() {
    //ARRANGE
    coor_t start;
    start.row = 4;
    start.col = 0;

    coor_t dest;
    dest.row = 1;
    dest.col = 1;

    int map[MAPSIZEROW][MAPSIZECOL] = {
        {water, water, mountain2, mountain1, asphalt},
        {asphalt, asphalt, mountain2, mountain2, asphalt},
        {asphalt, asphalt, asphalt, asphalt, water},
        {mine, mine, mountain2, asphalt, water},
        {mountain2, mountain1, mountain1, mountain2, mine}
    };

    int manualCalc = 189;
    //ACT
    int aStarCalc = aStarSearch(map, start, dest);

    //ASSERT
    assert(manualCalc == aStarCalc);
}

void aStarVSdijkstra() {
    //ARRANGE
    coor_t start;
    start.row = 4;
    start.col = 0;

    coor_t dest;
    dest.row = 1;
    dest.col = 1;

    int map[MAPSIZEROW][MAPSIZECOL] = {
        {water, water, mountain2, mountain1, asphalt},
        {asphalt, asphalt, mountain2, mountain2, asphalt},
        {asphalt, asphalt, asphalt, asphalt, water},
        {mine, mine, mountain2, asphalt, water},
        {mountain2, mountain1, mountain1, mountain2, mine}
    };

    int mapD[MAPSIZEROW][MAPSIZECOL] = {
        {water, water, mountain2, mountain1, asphalt},
        {asphalt, asphalt, mountain2, mountain2, asphalt},
        {asphalt, asphalt, asphalt, asphalt, water},
        {mine, mine, mountain2, asphalt, water},
        {mountain2, mountain1, mountain1, mountain2, mine}
    };

    //ACT
    int aStarCalc = aStarSearch(map, start, dest);

    int dijkstraCalc = dijkstra(mapD, start, dest);

    //ASSERT
    assert(aStarCalc == dijkstraCalc);
}