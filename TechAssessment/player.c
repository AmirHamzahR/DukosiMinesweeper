#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "grid.h"
#include "square.h"

void startGame(Grid *grid)
{
    char ans;
    printf("Welcome to the game!\n");
    printf("Do you want to play? (Y/N)\n");
    scanf("%c", &ans);
    if(ans == 'y' || 'Y')
    {
        grid->continueGame = 1;
        printf("Starting game...\n");
        generateGrid(grid, 8, 10);
        printGame(grid);
        askUser(grid);
    }
    else if (ans == 'n' || 'N')
    {
        grid->continueGame = 0;
        printf("Goodbye!\n");
    }
    else
    {
        printf("Invalid input!\n");
    }
}

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
            while (getchar() != '\n'); // Clear the input buffer
            continue; // Skip the rest of the loop iteration
        }

        switch (choice) {
            case 1:
                // Assuming setRevealed is implemented to reveal the square and check for game over conditions
                i = askCoordinates(grid, "x");
                j = askCoordinates(grid, "y");
                setRevealed(&grid->squares[i][j], 1);
                break;
            case 2:
                // Assuming setFlagged is implemented to flag the square
                i = askCoordinates(grid, "x");
                j = askCoordinates(grid, "y");
                setFlagged(&grid->squares[i][j], 1);
                break;
            case 3:
                // Assuming setFlagged is implemented to unflag the square
                i = askCoordinates(grid, "x");
                j = askCoordinates(grid, "y");
                setFlagged(&grid->squares[i][j], 0);
                break;
            case 4:
                // Assuming startGame is implemented to reset the grid and start a new game
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
        printGame(grid); // Assuming printGame function is defined to print the current state of the grid
    }
    printf("Game over!\n");
}

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
            printf("Coordinates out of bounds! Please enter a value from 0 to %d.\n", grid->size - 1);
        }
    } while (x < 0 || x > grid->size);  // Repeat until a valid coordinate is entered

    return x-1;  // Return the valid coordinate
}




