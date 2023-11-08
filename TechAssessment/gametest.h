#ifndef gametest_h
#define gametest_h

#include "square.h"
#include "grid.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Reveals all squares in the grid without ending the game.
 * @param grid Pointer to the Grid structure representing the Minesweeper game.
 */
void revealAllTest(Grid *grid);

/**
 * @brief Simulates a winning condition for the Minesweeper game.
 * @param grid Pointer to the Grid structure representing the Minesweeper game.
 */
void winTest(Grid *grid);

/**
 * @brief Simulates a losing condition by revealing a bomb.
 * @param grid Pointer to the Grid structure representing the Minesweeper game.
 */
void loseTest(Grid *grid);

#endif