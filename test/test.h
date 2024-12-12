
#ifndef TEST_H
#define TEST_H
#include "../src/map.h"
bool assertion(bool expression);

/* TODO: --- ONLY USED FOR TESTING --- */
void createMap(int map[MAPSIZEROW][MAPSIZECOL]);
void createFlatMap(int map[MAPSIZEROW][MAPSIZECOL]);

#endif //TEST_H