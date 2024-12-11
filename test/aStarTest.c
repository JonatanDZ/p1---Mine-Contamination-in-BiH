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

void aStarVSdijkstra_s0400_d2929() {
    //ARRANGE
    coor_t start;
    start.row = 4;
    start.col = 0;

    coor_t dest;
    dest.row = 29;
    dest.col = 29;



    int map[MAPSIZEROW][MAPSIZECOL];
    createMap(map);


    int mapD[MAPSIZEROW][MAPSIZECOL];
    createMap(mapD);


    //ACT
    int aStarCalc = aStarSearch(map, start, dest);

    int dijkstraCalc = dijkstra(mapD, start, dest);

    //ASSERT
    assert(aStarCalc == dijkstraCalc);
}

void aStarVSdijkstra_s1212_d0131() {
    //ARRANGE
    coor_t start;
    start.row = 00;
    start.col = 00;

    coor_t dest;
    dest.row = 0;
    dest.col = 31;



    int map[MAPSIZEROW][MAPSIZECOL];
    createMap(map);


    int mapD[MAPSIZEROW][MAPSIZECOL];
    createMap(mapD);


    //ACT
    double startTimeAStar = clock();
    int aStarCalc = aStarSearch(map, start, dest);
    double aStarTime = (clock() - startTimeAStar) / CLOCKS_PER_SEC;
    printf("A* time: %lf\n", aStarTime);

    double startTimeDijkstra = clock();
    int dijkstraCalc = dijkstra(mapD, start, dest);

    double dijkstraTime = (clock() - startTimeDijkstra) / CLOCKS_PER_SEC;
    printf("Dijkstra time: %lf\n", dijkstraTime);

    //ASSERT
    assert(aStarCalc == dijkstraCalc);

    assert(aStarTime < dijkstraTime);


}

