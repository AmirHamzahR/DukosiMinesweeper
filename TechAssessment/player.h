#ifndef player_h
#define player_h

#include "square.h"
#include "grid.h"
#include <stdio.h>

/**
 * @brief Starts the Minesweeper game and handles the initial player interaction.
 * @param grid Pointer to the Grid structure that holds the game state.
 */
void startGame();

/**
 * @brief Manages the user interaction loop during the game.
 * @param grid Pointer to the Grid structure that holds the game state.
 */
void askUser();

/**
 * @brief Prompts the user for a grid coordinate and validates the input.
 * @param grid Pointer to the Grid structure to check the bounds against.
 * @param coordinate A string representing the coordinate axis being requested ("x" or "y").
 * @return The valid grid coordinate entered by the user or a special value to indicate 'back'.
 */
int askCoordinates(Grid *grid, char *coordinate);

#endif



