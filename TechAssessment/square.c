// Square.c
#include "square.h"
#include <stdio.h>

void initSquare(Square *sq, int isBomb, int isFlagged, int isRevealed, int numBombs) {
    if (sq != NULL) {
        sq->isBomb = isBomb;
        sq->isRevealed = isRevealed;
        sq->isFlagged = isFlagged;
        sq->numBombs = numBombs;
    }
}

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

void setBomb(Square *sq, int isBomb) {
    if (sq != NULL && !sq->isBomb) {
        sq->isBomb = isBomb;
    }
}

void setNumBombs(Square *sq, int numBombs) {
    if (sq != NULL && !sq->numBombs) {
        sq->numBombs = numBombs;
    }
}