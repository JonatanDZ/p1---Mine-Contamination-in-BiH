//
// Created by Lenovo on 01/12/2024.
//

#include "dataStructures.h"

void addCell(list_t* list, cell_t* cell) {
    listNode_t* newNode = (listNode_t*) malloc(sizeof(listNode_t));
    newNode->cell = cell;
    newNode->next = list->head; //Make the current list head the 'next' of this node
    list->head = newNode;       //Update the head of the list to this node
}

void deleteCell