# 2023
## 11/6
The functionality for grid has been developed. It can now update game state of a "fixed" game state without any randomness of the order. The squares containing mines will only have mines, and those without will have adjacentMines() function to detect the number of surrounding mines.

Now, I need to add a functionality for the player to play the game as intended using Minesweeper. This will be added in the player.c source code with player.h file. From this, it will allow the interaction of player to make a new game, select actions to reveal or flag, and quit the game.