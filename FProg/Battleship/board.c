/**
 * @brief Implementation of the BOARD module
 * @file board.c
*/

#include "board.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Board structure 
*/
struct _Board{
    int **boxes;    /*!< Data of the board*/
    int rows;       /*!< Number of rows of the board*/
    int columns;    /*!< Number of columns of the board*/
};

/**
 * board_create creates a new board, allocating memory for it
*/
Board *board_create(const int rows, const int columns){
    Board *board = NULL;
    int i, j;

    /*check arguments*/
    if (rows < ROW_MIN || rows > ROW_MAX || columns < COLUMN_MIN || columns > COLUMN_MAX) return NULL;

    board = (Board *)malloc(sizeof(Board));
    if (!board) return NULL;

    board->rows = rows;
    board->columns = columns;

    board->boxes = (int **)malloc(columns*sizeof(int));
    if (!board->boxes){
        free(board);
        return NULL;
    }

    for (i=0; i<columns; i++){
        board->boxes[i] = (int *)malloc(rows*sizeof(int));
        if (!board->boxes[i]){
            for (j=0; j<i; j++){
                free(board->boxes[j]);
            }
            free(board->boxes);
            free(board);
            return NULL;
        }
    }

    for (i=0; i<columns; i++){
        for (j=0; j<rows; j++){
            board->boxes[i][j] = 0;
        }
    }

    return board;
}

/**
 * board_destroy destroys a board, freeing the allocated memory for it
*/
Status board_destroy(Board *board){
    int i;

    /*check arguments*/
    if (!board) return ERROR;

    for (i=0; i<board->columns; i++){
        free(board->boxes[i]);
    }

    free(board->boxes);
    free(board);

    return OK;
}

/**
 * board_get_rows gets the number of rows of a board
*/
int board_get_rows(const Board *board){

    /*check arguments*/
    if (!board) return -1;

    return board->rows;
}

/**
 * board_get_columns gets the number of columns of a board
*/
int board_get_columns(const Board *board){

    /*check arguments*/
    if (!board) return -1;

    return board->columns;
}

/**
 * board_set_box sets the value of a box in a board
*/
Status board_set_box(Board *board, const int row, const int column, const int value){
    
    /*check arguments*/
    if (!board || row < ROW_MIN || row > board->rows || column < COLUMN_MIN || column > board->columns) return ERROR;

    board->boxes[column][row] = value;

    return OK;
}

/**
 * board_get_boxes gets the boxes of a board
*/
int **board_get_boxes(const Board *board){
    
    /*check arguments*/
    if (!board) return NULL;

    return board->boxes;
}

/**
 * board_print prints the information related to a board
*/
void board_print(const Board *board){

    /*check arguments*/
    if (!board) return;

    printf("\tBOARD:");
    printf("\t\tboard rows: %d\n", board->rows);
    printf("\t\tboard columns: %d\n", board->columns);
}