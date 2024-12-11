#include <stdbool.h>
#include <stdio.h>
#include "mapTest.c"

#include "TimTestHcalc.c"
#include "TimTestMineGen.c"
#include "aStarTest.c"
#include "dataStructuresTest.c"

int main() {

    /*----------------------------- aStarTest ------------------------------*/
    //Search test
    test_fLinSearch_3open_2not();
    test_fLinSearch_noneOpen_firstTrue();
    test_fLinSearch_1open_2not();

    //Complete test
    aStarRouteTest_s0100_d0004();
    aStarRouteTest_s0400_d0101();
    aStarVSdijkstra_s1212_d2929();
    aStarVSdijkstra_s1616_d0000();

    //hCalc
    test_hCalc_s0000_d2525();
    test_hCalc_s1010_d3131();
    test_hCalc_s2928_d0204();
    test_hCalc_s2900_d0029();

    /*------------------------- dataStructuresTest -------------------------*/
    test_initEmptyCellMap();
    test_initCell_rc00_d2525();

    /*------------------------------- mapTest -------------------------------*/

    //test_createMapWFile(); TODO: Passes in test.exe, fails in allCTest because file is isn't found

    //isMineable
    test_isMineable_0_4_water();
    test_isMineable_0_3_forest();
    test_isMineable_4_2_mine();
    test_isMineable_0_1_field();
    test_isMineable_1_1_asphalt();
    test_isMineable_4_3_mountain1();
    test_isMineable_4_4_mountain2();
    test_isMineable_2_4_startPosition();
    test_isMineable_3_4_endPosition();

    //shortestRoute
    test_shortestRoute();
    test_shortestRoute_miniMap();

    //isWithinArray
    test_isWithinArray_5_5();
    test_isWithinArray_50_50();
    test_isWithinArray_neg1_16();
    test_isWithinArray_19_neg20();


    //isUnblocked
    test_isUnblocked_0_4_water();
    test_isUnblocked_0_3_forest();
    test_isUnblocked_4_2_mine();
    test_isUnblocked_0_1_field();
    test_isUnblocked_1_1_asphalt();
    test_isUnblocked_4_3_mountain1();
    test_isUnblocked_4_4_mountain2();
    test_isUnblocked_2_4_startPosition();
    test_isUnblocked_3_4_endPosition();


    //randomMineGen
    test_randomMineGen500();
    test_randomMineGen250();
    test_randomMineGen146();
    test_randomMineGen27();
    
}
