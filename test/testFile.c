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
    test_isWithinArray_5_5();
    test_isWithinArray_50_50();
    test_isWithinArray_neg1_16();
    test_isWithinArray_19_neg20();
    test_createMapWFile();
}
