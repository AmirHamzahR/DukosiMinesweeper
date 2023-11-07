#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "grid.h"
#include "square.h"

/*
 * This function welcomes the player and asks if they want to start a game. If the player
 * chooses to play, the game grid is initialized and the game loop begins. If the player
 * chooses not to play or inputs an invalid response, the game will exit or prompt again.
 */
void startGame(Grid *grid)
{
    char ans;
    int inputValid = 0;
    printf("Welcome to the game!\n");
    while (!inputValid) {
        printf("Do you want to play? (Y/N)\n");

        if (scanf(" %c", &ans) == 1) { 
            while (getchar() != '\n');
            
            if (ans == 'y' || ans == 'Y') {
                grid->continueGame = 1;
                printf("Starting game...\n");
                generateGrid(grid, 8, 10);
                printGame(grid);
                askUser(grid);
                inputValid = 1;
            } else if (ans == 'n' || ans == 'N') {
                grid->continueGame = 0;
                printf("Goodbye!\n");
                inputValid = 1; 
            } else {
                printf("Invalid input! Please enter Y for Yes or N for No.\n");
            }
        } else {
            while (getchar() != '\n');
            printf("Invalid input! Please enter Y for Yes or N for No.\n");
        }
    }
}

/*
 * In this loop, the player can choose to clear or flag squares, start a new game, or quit.
 * The function handles invalid input by prompting the user to try again. Each valid action
 * taken by the user results in an updated game state and grid display.
 */
void askUser(Grid *grid) {
    int i, j;
    int choice;
    while (grid->continueGame) {
        printf("Choose your action:\n");
        printf("1. Clear Square\n");
        printf("2. Flag Square\n");
        printf("3. Unflag Square\n");
        printf("4. New Game\n");
        printf("5. Quit\n");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter a number.\n");
            while (getchar() != '\n'); 
            continue; 
        }

        switch (choice) {
            case 1:
                // Reveal the squares
                i = askCoordinates(grid, "y");
                j = askCoordinates(grid, "x");
                setRevealed(&grid->squares[i][j], 1);
                break;
            case 2:
                // Flag the square
                i = askCoordinates(grid, "y");
                j = askCoordinates(grid, "x");
                grid->flagsUsed = setFlagged(&grid->squares[i][j], 1, grid->flagsUsed);
                break;
            case 3:
                // Unflag the square
                i = askCoordinates(grid, "y");
                j = askCoordinates(grid, "x");
                grid->flagsUsed = setFlagged(&grid->squares[i][j], 0, grid->flagsUsed);
                break;
            case 4:
                // To reset the grid and start a new game
                startGame(grid);
                return;
                break;
            case 5:
                // Quit the game
                printf("Goodbye!\n");
                grid->continueGame = 0; // Set to 0 to exit the loop and end the game
                return;
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        printGame(grid);
    }
    printf("Game over!\n");
}

/*
 * The function repeatedly prompts for a coordinate until a valid number within the grid
 * bounds is entered. If 'b' is entered, the function signals the caller to go back.
 */
int askCoordinates(Grid *grid, char *coordinate) {
    int x;
    do {
        printf("Enter %s coordinate: ", coordinate);
        while (scanf("%d", &x) != 1) {
            // Input was not a number, prompt the user again
            printf("Invalid input, please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Enter %s coordinate: ", coordinate);
        }
        // If the input is out of bounds, inform the user and prompt again
        if (x < 0 || x > grid->size) {
            printf("Coordinates out of bounds! Please enter a value from 1 to %d.\n", grid->size);
        }
    } while (x < 0 || x > grid->size);  // Repeat until a valid coordinate is entered

    return x-1;  // Return the valid coordinate
}




