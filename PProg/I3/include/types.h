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

/**
 * @brief Max word size for strings
 */
#define WORD_SIZE 1000

/**
 * @brief Error value for ids
 */
#define NO_ID -1

/**
 * @brief Variable type for assigning unique identification numbers to rooms or entities. Error value defined by macro NO_ID
 */
typedef long Id;

/**
 * @brief This enumeration defines the boolean values TRUE (1) and FALSE (0)
 */
typedef enum {
  FALSE,
  TRUE
} BOOL;

/**
 * @brief This enumeration defines exit codes
 */
typedef enum {
  ERROR,            /*!< The exit code for a failed process is 0 */
  OK                /*!< The exit code for a successful process is 1 */
} STATUS;

/**
 * @brief This enumeration defines the four cardinal directions
 */
typedef enum {
  U = -1,
  N,
  S,
  E,
  W
} DIRECTION;

#endif
