#include <stdbool.h>
#include <stdio.h>
#include "mapTest.c"
#include "TimTestHcalc.c"
#include "TimTestMineGen.c"
#include "aStarTest.c"


bool assertion(bool expression) {
    if (expression) {
        return true;
    }
    return false;
}

int main() {
    test_isWithinArray_5_5();
    test_isWithinArray_50_50();
    test_isWithinArray_neg1_16();
    test_isWithinArray_19_neg20();
    test_hCalc_s0000_d2525();
    test_hCalc_s1010_d3131();
    test_hCalc_s2928_d0204();
    test_hCalc_s2900_d0029();
    test_randomMineGen500();
    test_randomMineGen250();
    test_randomMineGen27();
    test_randomMineGen146();
    aStarRouteTest_s0100_d0004();
    aStarRouteTest_s0400_d0101();
    aStarVSdijkstra_s0400_d2929();
    aStarVSdijkstra_s1212_d0131();
}
