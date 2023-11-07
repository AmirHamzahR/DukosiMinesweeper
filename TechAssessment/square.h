#ifndef SQUARE_H
#define SQUARE_H

/**
 * @brief Represents a single square on the Minesweeper grid.
 *
 * The Square struct is used to store the state of each cell in the Minesweeper game, 
 * including whether it's a bomb, whether it has been flagged by the player, whether it 
 * has been revealed, and the count of adjacent bombs if it's not a bomb.
 */
typedef struct Square {
    int isBomb;
    int isFlagged;
    int isRevealed;
    int numBombs;
} Square;

/**
 * @brief Initializes a square with the given properties.
 * @param sq Pointer to the Square to initialize.
 * @param isBomb Indicates if the square is a bomb (1) or not (0).
 * @param isFlagged Indicates if the square is flagged (1) or not (0).
 * @param isRevealed Indicates if the square is revealed (1) or hidden (0).
 * @param numBombs The number of adjacent bombs to this square.
 */
void initSquare(Square *square, int isBomb, int isFlagged, int isRevealed, int numBombs);

/**
 * @brief Sets the revealed state of a square.
 * @param sq Pointer to the Square to modify.
 * @param isRevealed The new revealed state to set (1 for revealed, 0 for hidden).
 */
void setBomb(Square *square, int isBomb);

/**
 * @brief Sets the flagged state of a square.
 * @param sq Pointer to the Square to modify.
 * @param isFlagged The new flagged state to set (1 for flagged, 0 for unflagged).
 */
void setFlagged(Square *square, int isFlagged);

/**
 * @brief Sets the bomb state of a square.
 * @param sq Pointer to the Square to modify.
 * @param isBomb The new bomb state to set (1 for bomb, 0 for no bomb).
 */
void setRevealed(Square *square, int isRevealed);

/**
 * @brief Sets the number of adjacent bombs for a square.
 * @param sq Pointer to the Square to modify.
 * @param numBombs The number of adjacent bombs to set for the square.
 */
void setNumBombs(Square *square, int numBombs);

#endif