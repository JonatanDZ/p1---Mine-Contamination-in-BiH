#include <stdbool.h>
#include <stdio.h>
#include "mapTest.c"
#include "dataStructuresTest.c"

bool assertion(bool expression) {
    if (expression) {
        return true;
    }
    return false;
}

int main() {

    test_initEmptyCellMap();
    test_initCell();

    /* --- mapTest --- */

    //test_createMapWFile();


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

    test_shortestRoute();


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
}
