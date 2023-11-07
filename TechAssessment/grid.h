#ifndef grid_h
#define grid_h

#include "square.h"

/**
 * @brief Represents the game board for Minesweeper.
 *
 * This structure holds the entire game state for a Minesweeper game, including the size of
 * the grid, the total number of mines placed on the board, a flag to indicate if the game
 * should continue, and a two-dimensional array of Square structures that represent each
 * cell on the grid.
 */
typedef struct Grid {
    int size;
    int mineCount;
    int flagsUsed;
    int continueGame;
    Square squares[8][8];
} Grid;

/**
 * @brief Initializes the game grid with mines placed and calculates adjacent mines.
 * @param grid Pointer to the Grid structure to be initialized.
 * @param size The size of the grid (size x size).
 * @param mineCount The number of mines to place on the grid.
 */
void generateGrid(Grid *grid, int size, int mineCount);

/**
 * @brief Prints the current state of the game grid to the console.
 * @param grid Pointer to the Grid structure containing the game state.
 */
void printGame(Grid *grid);

/**
 * @brief Counts the number of mines adjacent to a given square on the grid.
 * @param grid Pointer to the Grid structure containing the game state.
 * @param x The x-coordinate of the square to check.
 * @param y The y-coordinate of the square to check.
 * @return The number of mines adjacent to the square at (x, y).
 */
int adjacentBombs(Grid *grid, int x, int y);

#endif