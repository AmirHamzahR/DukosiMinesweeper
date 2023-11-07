// Square.c
#include "square.h"
#include <stdio.h>

/*
 * This function sets the initial state of a square including whether it is a bomb,
 * flagged, revealed, and the number of adjacent bombs.
 */
void initSquare(Square *sq, int isBomb, int isFlagged, int isRevealed, int numBombs) {
    if (sq != NULL) {
        sq->isBomb = isBomb;
        sq->isRevealed = isRevealed;
        sq->isFlagged = isFlagged;
        sq->numBombs = numBombs;
    }
}

/*
 * This function marks a square as revealed unless it is flagged. If the square is
 * already revealed, it prints an error message.
 */
void setRevealed(Square *sq, int isRevealed) {
    if (sq != NULL && !sq->isRevealed) {
        if(sq->isFlagged) {
            printf("Square is flagged! Unflag it first!\n");
            return;
        }
        else{
            sq->isRevealed = isRevealed;
        }
    }
    else {
        printf("Square is already revealed!\n");
    }
}

/*
 * This function marks a square as flagged unless it is already revealed. If the square
 * is already flagged, it prints an error message or unflags it if the intention is to
 * remove the flag.
 */
void setFlagged(Square *sq, int isFlagged) {
    if (sq != NULL && !sq->isFlagged) {
        if(sq->isRevealed){
            printf("Square is revealed! Cannot flag it!\n");
            return;
        }
        else{
            sq->isFlagged = isFlagged;
        }
    }
    else {
        if(isFlagged == 0){
            sq->isFlagged = isFlagged;
        }
        else
        printf("Square is already flagged!\n");
    }
}

/*
 * This function marks a square as a bomb if it is not already one.
 */
void setBomb(Square *sq, int isBomb) {
    if (sq != NULL && !sq->isBomb) {
        sq->isBomb = isBomb;
    }
}

/*
 * This function updates the count of adjacent bombs for a square if it hasn't been
 * set already.
 */
void setNumBombs(Square *sq, int numBombs) {
    if (sq != NULL && !sq->numBombs) {
        sq->numBombs = numBombs;
    }
}