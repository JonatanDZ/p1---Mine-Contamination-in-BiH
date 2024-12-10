#include <assert.h>
#include "../src/dataStructures.h"

void test_hCalc_s00_d2525() {
    //ARRANGE
    double expectedResult = 525;
    double result;
    double tolerance = 0.1;
    //ACT
    result = hCalc(0, 0, 25, 25);

    //ASSERT
    assert(result - expectedResult < tolerance);
}

void test_hCalc_s1010_d3131() {
    //ARRANGE
    double expectedResult = 819;
    double result;
    double tolerance = 0.1;
    //ACT
    result = hCalc(10, 10, 31, 31);

    //ASSERT
    assert(result - expectedResult < tolerance);
}

void test_hCalc_s2928_d24() {
    //ARRANGE
    double expectedResult = 762;
    double result;
    double tolerance = 0.1;
    //ACT
    result = hCalc(29, 29, 2, 4);

    //ASSERT
    assert(result - expectedResult < tolerance);
}

void test_hCalc_s290_d029() {
    //ARRANGE
    double expectedResult = 870;
    double result;
    double tolerance = 0.1;
    //ACT
    result = hCalc(29, 0, 0, 29);

    //ASSERT
    assert(result - expectedResult < tolerance);
}