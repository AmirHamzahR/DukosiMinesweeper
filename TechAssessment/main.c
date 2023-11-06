#include <stdio.h>
#include "grid.h"
#include "square.h"

int main(int argc, char *argv[]) {
    Grid grid;
    printf("Starting game...\n");
    generateGrid(&grid, 8, 10);
    printGame(&grid);
    return 0; 
}