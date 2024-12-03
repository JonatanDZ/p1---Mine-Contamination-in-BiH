//
// Created by Jonatan Muhle-Zimino on 13/11/2024.
//


#include "header.h"
//Makes the start and end posistions.
int input(int map[MAPSIZEROW][MAPSIZECOL], coor_t* start, coor_t* dest) {
    // Starter fra 0, så minus en for koordinat.

    int startRow = -1, startCol = -1;

    printf("\nInput x y coordinates for the start location, within the coordinate interval from 0 0 to %d %d.\n>  ", MAPSIZE-1, MAPSIZE-1);
    scanf(" %d %d", &start->row, &start->col);

    map[start->row][start->col] = startPosition;

    if (isUnblocked(map, start->row, start->col) == false) {
        printf("Error: Start cannot be on a mine or river, please enter the first coordinates again.\n>");
        return input(map, start, dest);
    }


    printf("\nInput x y coordinates for the destination, within the coordinate interval 0 0 to %d %d.\n>", MAPSIZE-1, MAPSIZE-1);
    scanf(" %d %d", &dest->row, &dest->col);



    if (isUnblocked(map, dest->row, dest->col) == false) {
        printf("Error: Destination cannot be on a mine or river, please enter both coordinates again.\n");
        return input(map, start, dest);
    }

    map[dest->row][dest->col] = endPosition;

    if (start->row == dest->row && start->col == dest->row) {
        return input(map, start, dest);
    }

}






