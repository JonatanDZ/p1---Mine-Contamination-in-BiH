#include "header.h"
bool isEmpty(cell_t *open);


void tAstar(cell_t* map, const int mapSize, cell_t spawn, cell_t goal) {
    double open[]; // Besøgte celler, men ikke valgte/udvidet til.
    double closed[]; // Besøgte celler, som er blevet valgt/udvidet til.

    // Tjekker spawn og goal er walkable celler
    if (isWithinArray(spawn.Col, spawn.Row) && ifObstacle(map, spawn.Col, spawn.Row)
        && isWithinArray(goal.Col, goal.Row) && ifObstacle(map, goal.Col, goal.Row)) {
        printf("Valid spawn & goal\n");
    } else {
        printf("Invalid spawn & goal\n");
        exit(EXIT_FAILURE);
    }

    // Linje 1 i Barcelona, laver
    open[spawn.Row * mapSize + spawn.Col] = hCalc(spawn.Row, spawn.Col, goal.Row, goal.Col);

    // Man kan ikke dette i C så vidt jeg kan se, men ved ikke lige hvordan jeg skulle omskrive det.
    // Linje 2
    while(!isEmpty(open)) {

    }



}


bool isEmpty(cell_t *open) {
    return open[] == NULL;
}