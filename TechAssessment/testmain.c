// testmain.c
#include <stdio.h>
#include "grid.h"
#include "player.h"
#include "gametest.h"

int main() {
    Grid revealGrid;
    Grid winGrid;
    Grid loseGrid;
    generateGrid(&revealGrid, 8, 10);  
    generateGrid(&winGrid, 8, 10);   
    generateGrid(&loseGrid, 8, 10);    
    
    // Run the tests
    revealAllTest(&revealGrid);
    winTest(&winGrid);
    loseTest(&loseGrid);

    return 0;
}