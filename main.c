#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

// Enum for move values (Tile Costs)
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

#define ROW 32
#define COL 32

// Define the structure for a node in the grid
typedef struct {
    int parentRow, parentCol;
    double gCost, hCost, fCost;
    bool inOpenList;
    bool inClosedList;
} Node;

int direction[4][2] = {
    {0, 1},  // Right
    {1, 0},  // Down
    {0, -1}, // Left
    {-1, 0}  // Up
};

// Function to check if a cell is valid
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Function to check if a cell is an obstacle (water or mine)
bool isObstacle(int grid[ROW][COL], int row, int col) {
    return (grid[row][col] == water || grid[row][col] == mine);
}

// Heuristic function (Manhattan Distance)
double heuristic(int row, int col, int goalRow, int goalCol) {
    return abs(row - goalRow) + abs(col - goalCol);
}

// A* Algorithm
void aStar(int grid[ROW][COL], int startRow, int startCol, int goalRow, int goalCol) {
    // Initialize the nodes array
    Node nodes[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            nodes[i][j].parentRow = -1;
            nodes[i][j].parentCol = -1;
            nodes[i][j].gCost = DBL_MAX;
            nodes[i][j].hCost = DBL_MAX;
            nodes[i][j].fCost = DBL_MAX;
            nodes[i][j].inOpenList = false;
            nodes[i][j].inClosedList = false;
        }
    }

    // Initialize the starting node
    nodes[startRow][startCol].gCost = 0.0;
    nodes[startRow][startCol].hCost = heuristic(startRow, startCol, goalRow, goalCol);
    nodes[startRow][startCol].fCost = nodes[startRow][startCol].hCost;
    nodes[startRow][startCol].inOpenList = true;

    // Priority queue replacement using a simple loop (inefficient but simple for small grids)
    while (1) {
        // Find the node with the lowest fCost in the open list
        int currentRow = -1, currentCol = -1;
        double minFCost = DBL_MAX;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (nodes[i][j].inOpenList && nodes[i][j].fCost < minFCost) {
                    minFCost = nodes[i][j].fCost;
                    currentRow = i;
                    currentCol = j;
                }
            }
        }

        // If no node found in open list, path does not exist
        if (currentRow == -1 || currentCol == -1) {
            printf("No path found.\n");
            return;
        }

        // If goal is reached, reconstruct the path
        if (currentRow == goalRow && currentCol == goalCol) {
            // Replace the path cells with 69
            while (currentRow != startRow || currentCol != startCol) {
                grid[currentRow][currentCol] = 69; // Mark the path
                int tempRow = nodes[currentRow][currentCol].parentRow;
                int tempCol = nodes[currentRow][currentCol].parentCol;
                currentRow = tempRow;
                currentCol = tempCol;
            }
            grid[startRow][startCol] = 69; // Mark the start position
            return;
        }

        // Move current node from open list to closed list
        nodes[currentRow][currentCol].inOpenList = false;
        nodes[currentRow][currentCol].inClosedList = true;

        // Check all neighbors
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + direction[i][0];
            int newCol = currentCol + direction[i][1];

            // If the neighbor is valid, not an obstacle, and not in the closed list
            if (isValid(newRow, newCol) && !isObstacle(grid, newRow, newCol) && !nodes[newRow][newCol].inClosedList) {
                // Calculate the new gCost (cost to move from the start to this tile)
                double moveCost = grid[newRow][newCol];  // Cost based on tile type (from the enum)
                double newGCost = nodes[currentRow][currentCol].gCost + moveCost;
                double newHCost = heuristic(newRow, newCol, goalRow, goalCol);
                double newFCost = newGCost + newHCost;

                // If the new path is better, update the neighbor
                if (!nodes[newRow][newCol].inOpenList || newFCost < nodes[newRow][newCol].fCost) {
                    nodes[newRow][newCol].gCost = newGCost;
                    nodes[newRow][newCol].hCost = newHCost;
                    nodes[newRow][newCol].fCost = newFCost;
                    nodes[newRow][newCol].parentRow = currentRow;
                    nodes[newRow][newCol].parentCol = currentCol;
                    nodes[newRow][newCol].inOpenList = true;
                }
            }
        }
    }
}

// Function to print the grid
void printGrid(int grid[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%02c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[ROW][COL] = { //This is our hardcoded map
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain1,mountain1,mountain1,forest,forest, field, asphalt, city, water, water, city, city, asphalt, field,field,field,mine, forest, forest, mine, forest, forest, mine, mountain1, mountain2, mountain2, mountain2},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1,mountain1,forest,forest,asphalt,asphalt, city, water, water, city, asphalt, field, field, field, field,mine,forest,forest,forest,forest,forest,mountain1, mountain1, mountain2, mountain2,},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain1, mountain1, forest, field, asphalt, asphalt, city, water, water, asphalt, asphalt, field, field, field, field, field, field, forest, mine, forest, forest, mountain1, mountain1, mountain2},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1, forest, forest, field, asphalt, city, water, water, water, asphalt,field,field,field, field, field, mine, field, forest, forest, forest, forest, mountain1, mountain2},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1, mountain1, forest, forest, asphalt, asphalt, water, water, water, asphalt, asphalt, city, field,field,field,field,field,forest, forest, mine, forest, mountain1, mountain1},
            {mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2,mountain2, mountain1, mountain1, mountain1, forest, field, asphalt, asphalt, water, water, water, asphalt, city, city, city, field, field, field, mine, forest, forest, forest, mountain1, mountain1},
            {mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, forest, forest, field, asphalt, water, water, water, asphalt , city, city, city, field, field, field, forest, forest, forest, mountain1, mountain1, mountain2},
            {mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, forest, forest, forest, field, asphalt, water, water, water, asphalt, city, city, city, field, field, field, forest,forest,forest, mountain1, mountain1, mountain2 },
            {mountain2, mountain2, mountain2,mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, mountain1, forest, forest, forest, field, asphalt, asphalt, city, water, water, asphalt, city, city, city, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain2 },
            {mountain2,mountain2,mountain2,mountain2,mountain2, mountain1,mountain1,mountain1,mountain1, forest, forest, field, field, field, asphalt, city, city, water, water, asphalt, city, city, city, field, field, forest, mine, forest, mountain1, mountain1, mountain2, mountain2},
            {mountain2, mountain2, mountain2, mountain1, mountain1, mountain1, forest, forest, forest, field, field, field, asphalt, asphalt, asphalt, city, city, water, water, asphalt, city, city, city, field, field, forest, forest, forest, forest, mountain1, mountain1,mountain2},
            {mountain2, mountain2, mountain2, mountain1, mountain1, forest, forest, field, field, field, asphalt, asphalt, asphalt, city, city, city, water, water, water, asphalt, city, city, field, field, mine, forest, forest, forest, mountain1, mountain2, mountain2, mountain2 },
            {mountain2, mountain2, mountain2, mountain1, forest, forest, field, field, city, city, asphalt, city,city,city,city,city, water, water, asphalt, asphalt, city, city, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain2, mountain2},
            {mountain2, mountain2, mountain1, mountain1, forest, city, city, city, city, city, asphalt, city, city, city, city, water, water, water, asphalt, city, city, city, field, field, forest, forest, mine, forest, mountain1, mountain1, mountain1, mountain2},
            {mountain2, mountain2, mountain1, forest, forest, city, city, city, city, city, asphalt, asphalt, city, city, city, water, water, asphalt, city, city, city, field, field, field, mine, forest, forest, forest, forest, mountain1, mountain1, mountain1},
            {mountain2, mountain2, mountain1, forest, city, city, city, city, city, city, city, asphalt, city, city, water, water, water, asphalt, city, city, city, field, field, field, mine, forest, forest, forest, forest, mountain1, mountain1, mountain1},
            {mountain2, mountain1, mountain1, forest, city, city, city, city, city, city, city, city, asphalt, water, water, asphalt, asphalt, city, city, city, field, field, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain2},
            {mountain2, mountain1, mountain1, forest, city, city, city, city, city, city, city, asphalt, asphalt, water, water, asphalt, city, city, city, city, field, field, field, field, forest, forest, forest, mountain1, mountain1, mountain1, mountain2, mountain2},
            {mountain2, mountain1, mountain1, forest, city, city, city, city, city, city, city, asphalt, asphalt, water, water, asphalt, city, city, city, city, field, field, field, field, forest, forest, forest, mountain1, mountain1, mountain1, mountain2, mountain2},
            {mountain2, mountain1, mountain1, forest, city, city, city, city, city, city, asphalt, asphalt, water, water, water, asphalt, city, city, city, field, field, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain2, mountain2}, //
            {mountain1, mountain1, forest, forest, city, city, city, city, city, asphalt, asphalt, asphalt, asphalt, water, asphalt, asphalt, city, city, field, field, field, field, field, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2}, //
            {mountain1, mountain1, forest, field, field, asphalt, asphalt, asphalt, asphalt, asphalt, water, water, asphalt, asphalt, asphalt, city, city, field, field, field, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2}, //
            {mountain1, forest, forest, field, asphalt, asphalt, water, water, water, water, water, city, city, city, city, city, city, city, city, field, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2}, //
            {mountain1, forest, forest, asphalt, asphalt, water, water, water, water, water, city, city, city, city, city, city, city, city, city, mine, field, field, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2}, //
            {mountain1, forest, field, asphalt, water, water, water, water, city, city, city, city, city , city, city, city, city, city, field, field, field, mine, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2}, //
            {forest, forest, asphalt, asphalt, water, city, water, city, city, field, mine, city, city, city, city, city, city, field, mine, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2}, //
            {forest, field, asphalt, water, water, city, water, city, field, field, field, field, field, field, field, field, field, field, field, forest, mine, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2}, //
            {field, asphalt, asphalt, water, city, water, water, city, mine, field, field, mine, field, forest, forest, forest, forest, mine, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mine, mountain2, mountain2, mountain2, mountain2}, //
            {field, asphalt, water, water, city, water, city, field, field, field, mine, forest, forest, forest, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2}, //
            {asphalt, asphalt, water, water, city, water, city, mine, field, field, forest, forest, forest, forest, forest, forest, mountain1, mountain1, mountain1, mine, mountain1, mountain1, mountain1, mountain2, mine, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2, mountain2}, //
            {asphalt, water, water, city, city, water, city, field, mine, forest, mine, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mine, mountain2}, //
            {asphalt, water, water, city, city, water, mine, field, field, forest, forest, forest, forest, mountain1, mountain1, mountain1, mountain1, mountain1, mountain2, mountain2, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mine, mountain2, mountain2, mountain2, mountain2}, //
            };

    int startRow = 0, startCol = 0;
    int goalRow = 31, goalCol = 31;

    aStar(grid, startRow, startCol, goalRow, goalCol);

    // Print the grid with the shortest path marked by 69
    printf("Grid with the path (marked as 69):\n");
    printGrid(grid);

    return 0;
}
