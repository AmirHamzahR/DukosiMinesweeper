// Main.c
#include <stdio.h>
#include "grid.h"
#include "player.h"

/**
 * @brief Entry point of the Minesweeper game program.
 * 
 * This function sets up the game environment and starts the Minesweeper game.
 * It initializes a Grid structure to represent the game state and then calls
 * the startGame function to begin the game loop.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return int Returns 0 upon successful execution.
 */
int main(int argc, char *argv[]) {
    // Initializes the game grid structure.
    Grid grid;

    // Starts the game by initializing the grid and entering the game loop.
    startGame(&grid);

    // Indicates that the program has executed successfully.
    return 0; 
}