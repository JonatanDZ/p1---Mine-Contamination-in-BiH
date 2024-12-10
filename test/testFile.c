#include <stdbool.h>
#include <stdio.h>
#include "mapTest.c"


bool assertion(bool expression) {
    if (expression) {
        return true;
    }
    return false;
}

int main() {


    //test_createMapWFile();

    
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
