//
// Created by Lenovo on 01/12/2024.
//

#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#endif //DATASTRUCTURES_H

#include "header.h"

/**
 * A struct for one component of the linked list. Next is NULL if no next ecists
 */
typedef struct node_t { //Needs name here...
    cell_t* cell;
    struct node_t* next; //so it can be used here
} node_t;

/**
 * The type for the list itself. In actuality it is simply a pointer to the head of the list.
 */
typedef struct {
    node_t* head;
} list_t;





