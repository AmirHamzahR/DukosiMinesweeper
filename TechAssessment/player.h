#ifndef player_h
#define player_h

#include "square.h"
#include "grid.h"
#include <stdio.h>

void startGame();
void askUser();
int askCoordinates(Grid *grid, char *coordinate);

#endif



