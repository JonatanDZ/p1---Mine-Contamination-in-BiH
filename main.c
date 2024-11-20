#include <assert.h>
#include "header.h"
#include <stdbool.h>

bool isValid(int row, int col);
#define MAPSIZEROW 32
#define MAPSIZECOL 32


    typedef struct {
    int parentRow;
    int parentCol;
    double g;
    double h;
    double f;
    bool OpenList;
    bool ClosedList;
} cell_t;



int main(){

    //ARRANGE
    int row = 31;
    int col = 31;
    //ACT
    bool result = ifArray(row, col);
    //ASSERT
    assert(result == 1);

    return 0;
}

/**
 *Utility function checking if a cell is in the array or not. by returning 0 or 1.
 **/
bool ifArray(int row, int col) {
    if ((row >= 0) && (row < ROW) && (col >= 0) && (col < COL)) {
        return 1;
    }
    return 0;
}