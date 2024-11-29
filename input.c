//
// Created by Jonatan Muhle-Zimino on 13/11/2024.
//


#include "header.h"
//Makes the start and end posistions.
int input(int map[MAPSIZEROW][MAPSIZECOL], coor_t* start, coor_t* dest) {
    // Starter fra 0, så minus en for koordinat.

    int startRow = -1, startCol = -1;

    printf("Input x og y koordinat for start koordinator, det går fra 0 0 til %d>", MAPSIZE-1);
    scanf(" %d %d", &start->row, &start->col);

    map[start->row][start->col] = startPosition;

    if (isUnblocked(map, start->row, start->col) == false) {
        printf("Error: start cant be on a mine or river, pleas reenter the first coordinates \n");
        return input(map, start, dest);
    }


    printf("Input x og y koordinat for end koordinator, det går fra 0 0 til %d>", MAPSIZE-1);
    scanf(" %d %d", &dest->row, &dest->col);



    if (isUnblocked(map, dest->row, dest->col) == false) {
        printf("Error: distination cant be on a mine or river, pleas reenter both coordinates \n");
        return input(map, start, dest);
    }

    map[dest->row][dest->col] = endPosition;

    if (start->row == dest->row && start->col == dest->row) {
        return input(map, start, dest);
    }

}






