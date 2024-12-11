#include "../src/aStar.h"
//#include <assert.h>
#include <time.h>

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

void aStarVSdijkstra_s1212_d2929() {
    //ARRANGE
    coor_t start, dest;
    start.row = 12, start.col = 12;

    dest.row = 29, dest.col = 29;

    int map[MAPSIZEROW][MAPSIZECOL], mapD[MAPSIZEROW][MAPSIZECOL];

    createMap(map);

    createMap(mapD);

    //ACT
    double startTimeAStar = clock();
    int aStarCalc = aStarSearch(map, start, dest);
    double aStarTime = (clock() - startTimeAStar) / CLOCKS_PER_SEC;

    double startTimeDijkstra = clock();
    int dijkstraCalc = dijkstra(mapD, start, dest);
    double dijkstraTime = (clock() - startTimeDijkstra) / CLOCKS_PER_SEC;

    //ASSERT
    //Check if the two funcitons went the same path
    assert(aStarCalc == dijkstraCalc);

    //Compares the time between them
    assert(aStarTime < dijkstraTime + 0.0001);
}

void aStarVSdijkstra_s1616_d0000() {
    //ARRANGE
    coor_t start;
    start.row = 16;
    start.col = 16;

    coor_t dest;
    dest.row = 00;
    dest.col = 00;

    int map[MAPSIZEROW][MAPSIZECOL];
    createMap(map);

    int mapD[MAPSIZEROW][MAPSIZECOL];
    createMap(mapD);

    //ACT
    double startTimeAStar = clock();
    int aStarCalc = aStarSearch(map, start, dest);
    double aStarTime = (clock() - startTimeAStar) / CLOCKS_PER_SEC;

    double startTimeDijkstra = clock();
    int dijkstraCalc = dijkstra(mapD, start, dest);

    double dijkstraTime = (clock() - startTimeDijkstra) / CLOCKS_PER_SEC;

    //ASSERT
    //Check if the two funcitons went the same path
    assert(aStarCalc == dijkstraCalc);

    //Compares the time between them
    assert(aStarTime < dijkstraTime + 0.0001);
}

