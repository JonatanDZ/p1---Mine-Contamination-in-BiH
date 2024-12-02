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


void fLinSearch(list_t* list) {
    listNode_t* currentNode = list->head;
    listNode_t* resultNode = currentNode;


    for (currentNode; currentNode != NULL; currentNode = currentNode->next ) {
        if (currentNode->cell->f < resultNode->cell->f) {

        }

    }



}

void removeCell(list_t* list, cell_t* cell) {

}

