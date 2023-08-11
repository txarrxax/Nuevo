/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 2000
#define NO_ID -1
#define HEIGHT 5
#define LENGTH 10

typedef long Id;

typedef enum {
  FALSE, /*!< It assigns to FALSE BOOL the value 0*/
  TRUE /*!< It assigns to TRUE BOOL the value 1*/
} BOOL;

typedef enum {
  ERROR, /*!< It assigns to ERROR STATUS the value 0*/
  OK /*!< It assigns to OK STATUS the value 1*/
} STATUS;

typedef enum {
  N, /*!< It assigns to North DIRECTION the value 0*/
  S, /*!< It assigns to South DIRECTION the value 1*/
  E, /*!< It assigns to East DIRECTION the value 2*/
  W /*!< It assigns to West DIRECTION the value 3*/
} DIRECTION;

#endif
