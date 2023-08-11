/**
 * @file types.h
 * @author Alberto Tarrasa
 * @date 13 February 2023
 * @brief ADT Boolean and Status
 *
 * 
 * @see 
 */

#ifndef TYPES_H_
#define TYPES_H_

/**
 * @brief ADT Boolean
 */
typedef enum {
    FALSE = 0, /*!< False value */
    TRUE = 1   /*!< True value  */
} Bool;

/** 
 * @brief ADT Status
 */
typedef enum {
    ERROR = 0, /*!< To codify an ERROR output */
    OK = 1     /*!< OK output */
} Status;

#endif