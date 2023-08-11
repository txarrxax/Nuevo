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
  FALSE, /*!< The exit value for a FALSE statement is 0 */
  TRUE   /*!< The exit value for a TRUE statement is 1 */
} BOOL;

/**
 * @brief This enumeration defines exit codes
 */
typedef enum {
  ERROR, /*!< The exit code for a failed process is 0 */
  OK     /*!< The exit code for a successful process is 1 */
} STATUS;

/**
 * @brief This enumeration defines the four cardinal directions
 */
typedef enum {
  X = -1, /*!< The UNKNOWN direction is represented by -1 */
  N,      /*!< The NORTH direction is represented by 0 */
  S,      /*!< The SOUTH direction is represented by 1 */
  E,      /*!< The EAST direction is represented by 2 */
  W,      /*!< The WEST direction is represented by 3*/
  U,      /*!< The UP direction is represented by 4 */
  D       /*!< The DOWN direction is represented by 5*/
} DIRECTION;

#endif
