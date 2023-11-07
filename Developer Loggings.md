# 2023
## 3/11
The functionality for grid has been developed. It can now update game state of a "fixed" game state without any randomness of the order. The squares containing mines will only have mines, and those without will have adjacentMines() function to detect the number of surrounding mines.

Now, I need to add a functionality for the player to play the game as intended using Minesweeper. This will be added in the player.c source code with player.h file. From this, it will allow the interaction of player to make a new game, select actions to reveal or flag, and quit the game.

## 4/11
I added the startGame and askUser inside the player.c and player.h code. It turns out that the askUser was looping infinitely. I need to change the loop logic to ensure that it only loops everytime the player has finished the action.

Now, the loop can function properly with the setRevealed and setFlagged also works. However, when a new game is created, the UI on the console automatically prints out the amount of times new game is being created. If 3 new games are created, then 3 grids will be outputted when the game ends which is wrong. It also prints 3 times sequentially with "Game over!" string. This must be due to 3 while loop being operated at the same time. I need to fix this.

## 5/11
I added return after startGame() function inside the case 4 loop for restarting the game. After testing, it can then break out from the nested while loops so that it can properly start a new game.

The isFlagged functionality seems to work but unflagging it causes some issues on the UI aspect. I added another if statement inside the else part when it is flagged so it will continuously set the flag to zero even if it is already zero. This helps to use setFlagged() function for the unflagging part.

## 6/11
Now, the whole game should work with minor bugs on the input. However, there are still some UI issues for the coordinate part. It turns out there was a slight mistake on outputting string inside printf function. %s should be used instead of %c.

All the functionalities have been developed except when trying to win in the game. This should be added next. An idea for this is by inserting in the for loop of printGame to contain a boolean that says win when all the squares that has bigger than 0 adjacent mines have been revealed (isRevealed = 1). 

Now the game can be played until it wins.

## 7/11
I have added the error checks inside each of the function. I believe that the error check can be better put by making a separate class for each error checks for the userInputs(). This can be implemented int he future. The comments for each of the code section has also been done. Now, the game can be played like a normal Minesweeper game, except for the recursive zero elimination and add a bar that shows the time and number of flags left.

I have added the flag numbers implementation. However, I feel like there would be another way that would be more efficient to see the amount of flags left. This can be further be ventured in the future. Maybe I can also add in the time functionality.

Now, the documentation for the overall code can be finished with the initial and final ideas for the whole game.