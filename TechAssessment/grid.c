// Grid.c
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

/* UPDATING THE STATE OF THE GAME*/

/*
 * The function generates a new game grid, places the specified number of mines in a
 * predetermined pattern (currently on even coordinates), and then initializes the rest
 * of the grid. Finally, it calculates the number of adjacent mines for each square.
 */
void generateGrid(Grid *grid, int size, int mineCount) {
    grid->size = size;
    grid->mineCount = mineCount;

    // Place mines and initialize squares
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            initSquare(&grid->squares[i][j], 0, 0, 0, 0);
            /* In the future can add the random functionality for the mine */
            if (mineCount > 0 && i % 2 == 0 && j % 2 == 0) {
                setBomb(&grid->squares[i][j], 1);
                mineCount--;
            }
        }
    }

    // Calculate adjacent bombs for each square
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (!grid->squares[i][j].isBomb) {
                setNumBombs(&grid->squares[i][j], adjacentBombs(grid, i, j));
            }
        }
    }
}

/*
 * This function checks all adjacent squares to the given coordinates (x, y) and
 * counts how many of those are mines. The count does not include the square at
 * (x, y) itself.
 */
int adjacentBombs(Grid *grid, int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) continue;
            // Check if the indices are within bounds
            if (i >= 0 && i < grid->size && j >= 0 && j < grid->size) {
                if (grid->squares[i][j].isBomb) {
                    count++;
                }
            }
        }
    }
    return count;
}

/* UI ASPECT TO SHOW THE GRID AND SQUARES */

/*
 * The grid is displayed to the user with symbols representing the state of each square:
 * 'F' for flagged squares, 'M' for revealed mines (indicating a loss), 'X' for unrevealed
 * squares, and the count of adjacent mines for revealed non-mine squares. It also shows the
 * amount of flags left in the game for the user. If all non-mine squares are revealed, a 
 * win is declared.
 */
void printGame(Grid *grid) {
    int revealedNonBombCount = 0;
    int totalNonBombCount = grid->size * grid->size - grid->mineCount;
    printf("\n1  2  3  4  5  6  7  8\n");
    printf("-----------------------\n");
    // Print the grid
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            if (grid->squares[i][j].isFlagged) {
                printf("F  ");  
            } else if (grid->squares[i][j].isRevealed) {
                if (grid->squares[i][j].isBomb) {
                    printf("M  ");  
                    grid->continueGame = 0; 
                } else {
                    printf("%d  ", grid->squares[i][j].numBombs);
                    revealedNonBombCount++; 
                }
            } else {
                printf("X  ");
            }
        }
        printf("| %d\n", i+1);
    }

    // Checks flags left, in the near future can also add in time here.
    printf("\nFlags left: %d\n\n", grid->mineCount - grid->flagsUsed /* add time variable */);

    // Check for a win
    if (revealedNonBombCount == totalNonBombCount) {
        printf("Congratulations, you've won!\n");
        grid->continueGame = 0;
    }
}
