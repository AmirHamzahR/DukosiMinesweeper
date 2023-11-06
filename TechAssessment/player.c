#include <stdio.h>
#include "player.h"

void startGame()
{
    char ans;
    printf("Welcome to the game!\n");
    printf("Do you want to play? (Y/N)\n");
    scanf("%c", &ans);
    if(ans == 'y' || 'Y')
    {
        askUser();
    }
}

void askUser()
{
    // prints out the board by 'X' to close it as default
    
    int choice;
    printf("Choose your action:\n");
    printf("1. Clear Square\n");
    printf("2. Flag Square\n");
    printf("3. New Game\n");
    printf("4. Quit\n");
    
    switch (choice)
    {
        case 1:
            /* Clear Square */
            break;
        case 2:
            /* Flag Square */
            break;
        case 3:
            /* Unflag Square */
            break;
        case 4:
            /* New Game */
            break;
        case 5:
            /* Quit */
            break;
        default:
        
            break;
    }
}



