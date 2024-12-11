#include <assert.h>
#include "../src/dataStructures.h"

void test_hCalc_s0000_d2525() {
    //ARRANGE
    double expectedResult = 525;
    double result;
    double tolerance = 0.1;
    //ACT
    result = hCalc(0, 0, 25, 25);

    //ASSERT
    assert(fabs(result - expectedResult) < tolerance);
}
/* TODO: Denne fejler*/
void test_hCalc_s1010_d3131() {
    //ARRANGE
    double expectedResult = 441;
    double result;
    double tolerance = 0.1;
    //ACT
    result = hCalc(10, 10, 31, 31);

    //ASSERT
    assert(fabs(result - expectedResult) < tolerance);
}
/* TODO: Denne fejler*/
void test_hCalc_s2928_d0204() {
    //ARRANGE
    double expectedResult = 549;
    double result;
    double tolerance = 0.1;
    //ACT
    result = hCalc(29, 28, 2, 4);

    //ASSERT
    assert(fabs(result - expectedResult) < tolerance);
}
/* TODO: Denne fejler*/
void test_hCalc_s2900_d0029() {
    //ARRANGE
    double expectedResult = 609;
    double result;
    double tolerance = 0.1;
    //ACT
    result = hCalc(29, 0, 0, 29);

    //ASSERT
    assert(fabs(result - expectedResult) < tolerance);
}