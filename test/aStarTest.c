#include "test.h"
#include "../src/aStar.h"
#include "../src/dataStructures.h"

void routeTest(void) {
    //ARRANGE
    coor_t start;
    start.row = 0;
    start.col = 0;

    coor_t dest;
    dest.row = 0;
    dest.col = 4;

    int map[MAPSIZEROW][MAPSIZECOL] = {
    {asphalt, mountain1, mountain2, mountain2, asphalt},
    {asphalt, mountain1, water, mountain2, asphalt},
    {asphalt, asphalt, asphalt, mountain2, asphalt},
    {asphalt, mountain1, asphalt, asphalt, asphalt},
    {asphalt, mountain1, mountain2, mountain2, asphalt}
    };



    aStarSearch(map, start, dest);

    //ACT

    //ASSERT
}