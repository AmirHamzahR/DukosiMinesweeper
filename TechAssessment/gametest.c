// gametest.c
#include "gametest.h"

/*
 * This function is used for testing purposes to reveal the state of every square
 * in the Minesweeper grid. It saves the current game state, reveals all squares, 
 * prints the grid, and then restores the original game state.
 */
void revealAllTest(Grid *grid) {
    int originalState = grid->continueGame;

    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            grid->squares[i][j].isRevealed = 1;
        }
    }
    printGame(grid);
    grid->continueGame = originalState;
    printf("revealAllTest completed.\n");
}

/*
 * This function reveals all non-bomb squares and prints the grid, thereby simulating
 * a win scenario. It then checks if the game recognizes the win condition.
 */
void winTest(Grid *grid) {
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            if (!grid->squares[i][j].isBomb) {
                grid->squares[i][j].isRevealed = 1;
            }
        }
    }
    printGame(grid);
    assert(grid->continueGame == 0);
    printf("Win condition: PASSED\n");
}

/*
 * The function iterates through the grid to find and reveal the first bomb, 
 * thereby simulating a loss scenario. It then checks if the game ends as expected.
 */
void loseTest(Grid *grid) {
    int bombRevealed = 0; 
    for (int i = 0; i < grid->size && !bombRevealed; i++) {
        for (int j = 0; j < grid->size && !bombRevealed; j++) {
            if (grid->squares[i][j].isBomb) {
                setRevealed(&grid->squares[i][j], 1);
                bombRevealed = 1; 
            }
        }
    }
    printGame(grid);
    assert(grid->continueGame == 0);
    printf("Lose condition: PASSED\n");
}

