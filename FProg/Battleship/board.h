/**
 * @brief Implementation of the BOARD module
*/

#include "types.h"

#ifndef BOARD_H_

/**
 * @brief Minimum number of rows
*/
#define ROW_MIN 10

/**
 * @brief Maximum number of rows
*/
#define ROW_MAX 20

/**
 * @brief Minimum number of columns
*/
#define COLUMN_MIN 10

/**
 * @brief Maximum number of columns
*/
#define COLUMN_MAX 20

/**
 * @brief Board structure
*/
typedef struct _Board Board;

/**
 * @brief It creates a new board, allocating memory for it
 * 
 * @param rows the number of rows
 * @param columns the numner of columns
 * @return a pointer to Board
*/
Board *board_create(const int rows, const int columns);

/**
 * @brief It destroys a board, freeing the allocated memory for it
 * 
 * @param board a pointer to a Board
 * @return OK if everything goes well, ERROR if not
*/
Status board_destroy(Board *board);

/**
 * @brief It gets the number of rows of a board
 * 
 * @param board a pointer to a Board
 * @return OK if everything goes well, ERROR if not
*/
int board_get_rows(const Board *board);

/**
 * @brief It gets the number of columns of a board
 * 
 * @param board a pointer to a Board
 * @return OK if everything goes well, ERROR if not
*/
int board_get_columns(const Board *board);

/**
 * @brief It sets the value of a box in a board
 * 
 * @param board a pointer to a board
 * @param row the row of the box
 * @param column the column of the box
 * @param value the value for the box
 * @return OK if everything goes well, ERROR if not
*/
Status board_set_box(Board *board, const int row, const int column, const int value);

/**
 * @brief It gets the boxes of a board
 * 
 * @param board a pointer to a Board
 * @return a double pointer to boxes
*/
int **board_get_boxes(const Board *board);

/**
 * @brief It prints the information related to a board
 * 
 * @param board a pointer to a Board
 * @return no return
*/
void board_print(const Board *board);


#endif /*BOARD_H_*/