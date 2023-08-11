/**
 * @brief It defines the types
 * @file types.h
*/

#ifndef TYPES_H_

/**
 * @brief Max word size
*/
#define MAX_WORD 128

/**
 * @brief Wrong id number value
*/
#define NO_ID -1

/**
 * @brief Status type
*/
typedef enum {
    ERROR,  /*!< ERROR value set to 0*/
    OK      /*!< OK value set to 1*/
} Status;

/**
 * @brief Boolean type
*/
typedef enum {
    FALSE, /*!< FALSE value set to 0*/
    TRUE   /*!< TRUE value set to 1*/
} BOOL;

/**
 * @brief Id structure
*/
typedef long Id;

#endif /*TYPES_H_*/