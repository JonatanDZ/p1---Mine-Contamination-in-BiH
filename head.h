/*
#ifndef head.h
#define head.h 
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h> 

typedef enum {
    mine = 167,
    water = 247,
    asphalt = 223,
    city = 202,
    field = 173,
    forest = 216,
    mountain1 = 133,
    mountain2 = 142
} moveValue;


void createMap(int* map, const int mapSize);
//void printMap(int* map, const int mapSize);