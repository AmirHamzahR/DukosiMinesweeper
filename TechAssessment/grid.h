#ifndef grid_h
#define grid_h

#include "square.h"

typedef struct Grid {
    int size;
    int mineCount;
    int continueGame;
    Square squares[8][8];
} Grid;

void generateGrid(Grid *grid, int size, int mineCount);

void printGame(Grid *grid);

int adjacentBombs(Grid *grid, int x, int y);

#endif