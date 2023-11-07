// Grid.c
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

/* UPDATING THE STATE OF THE GAME*/
void generateGrid(Grid *grid, int size, int mineCount) {
    grid->size = size;
    grid->mineCount = mineCount;

    // Place mines and initialize squares
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            initSquare(&grid->squares[i][j], 0, 0, 0, 0); // Initialize squares without adjacent bomb count
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

// Function to calculate adjacent bombs for a square
int adjacentBombs(Grid *grid, int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            // Skip the current square
            if (i == x && j == y) continue;
            
            // Check if the indices are within bounds
            if (i >= 0 && i < grid->size && j >= 0 && j < grid->size) {
                // Increment count if a bomb is found
                if (grid->squares[i][j].isBomb) {
                    count++;
                }
            }
        }
    }
    return count;
}

/* UI ASPECT TO SHOW THE GRID AND SQUARES */

/* Function to print out the grid in console*/
/* Function to print out the grid in console */
void printGame(Grid *grid) {
    int revealedNonBombCount = 0;
    int totalNonBombCount = grid->size * grid->size - grid->mineCount; // Total number of non-bomb squares

    // Print the grid
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            if (grid->squares[i][j].isFlagged) {
                printf("F  ");  // Flagged square
            } else if (grid->squares[i][j].isRevealed) {
                if (grid->squares[i][j].isBomb) {
                    printf("M  ");  // Revealed bomb
                    grid->continueGame = 0; // The player hit a bomb and loses the game
                } else {
                    printf("%d  ", grid->squares[i][j].numBombs);  // Number of adjacent bombs
                    revealedNonBombCount++; // Increment the count of revealed non-bomb squares
                }
            } else {
                printf("X  ");  // Hidden square
            }
        }
        printf("\n");  // New line at the end of the row
    }

    // Check for a win
    if (revealedNonBombCount == totalNonBombCount) {
        printf("Congratulations, you've won!\n");
        grid->continueGame = 0; // End the game loop after winning
    }
}





