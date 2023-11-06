# 2023
## 11/6
The functionality for grid has been developed. It can now update game state of a "fixed" game state without any randomness of the order. The squares containing mines will only have mines, and those without will have adjacentMines() function to detect the number of surrounding mines.

Now, I need to add a functionality for the player to play the game as intended using Minesweeper. This will be added in the player.c source code with player.h file. From this, it will allow the interaction of player to make a new game, select actions to reveal or flag, and quit the game.

## 11/7
I added the startGame and askUser inside the player.c and player.h code. It turns out that the askUser was looping infinitely. I need to change the loop logic to ensure that it only loops everytime the player has finished the action.

Now, the loop can function properly with the setRevealed and setFlagged also works. However, when a new game is created, the UI on the console automatically prints out the amount of times new game is being created. If 3 new games are created, then 3 grids will be outputted when the game ends which is wrong. It also prints 3 times sequentially with "Game over!" string. This must be due to 3 while loop being operated at the same time. I need to fix this.

I added return after startGame() function inside the case 4 loop for restarting the game. After testing, it can then break out from the nested while loops so that it can properly start a new game.

The isFlagged functionality seems to work but unflagging it causes some issues on the UI aspect. I added another if statement inside the else part when it is flagged so it will continuously set the flag to zero even if it is already zero. This helps to use setFlagged() function for the unflagging part.

Now, the whole game should work with minor bugs on the input.