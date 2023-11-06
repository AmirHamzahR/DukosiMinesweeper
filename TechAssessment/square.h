#ifndef SQUARE_H
#define SQUARE_H

typedef struct Square {
    int isBomb;
    int isFlagged;
    int isRevealed;
    int numBombs;
} Square;

void initSquare(Square *square, int isBomb, int isFlagged, int isRevealed, int numBombs);

void setBomb(Square *square, int isBomb);

void setFlagged(Square *square, int isFlagged);

void setRevealed(Square *square, int isRevealed);

void setNumBombs(Square *square, int numBombs);

#endif