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
    test_isWithinArray();
    test_isWithinArray_50_50();
}
