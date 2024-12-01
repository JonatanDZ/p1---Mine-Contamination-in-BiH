//
// Created by Lenovo on 01/12/2024.
//

#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#endif //DATASTRUCTURES_H

#include "header.h"

/**
 * A struct for one component of the linked list. Next is NULL if no next exists
 */
typedef struct listNode_t { //Needs name here...
    cell_t* cell;
    struct listNode_t* next; //so it can be used here
} listNode_t;

/**
 * The type for the list itself. In actuality it is simply a pointer to the head of the list.
 */
typedef struct {
    listNode_t* head;
} list_t;

void addItem();
void removeItem();





