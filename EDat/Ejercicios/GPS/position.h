#ifndef POSITION_H_
#define POSITION_H_

#include <stdio.h>
#include "types.h"


/**
 * @brief Position TAD
*/
typedef struct _Position Position;

/**
 * @brief It creates a new position
 * 
 * @param lat a long with the latitude of the position
 * @param alt a long with the altitude of the position
 * @return a pointer to a new position
*/
Position *position_create (const long lat, const long alt);

/**
 * @brief It destroys a position
 * 
 * @param pos a pointer to a position
 * @return no return
*/
void position_free (Position *pos);

/**
 * @brief It gets the latitude of a position
 * 
 * @param pos a pointer to a position
 * @return a long with the latitude of the position
*/
long position_getLat (const Position *pos);

/**
 * @brief It gets the altitude of a position
 * 
 * @param pos a pointer to a position
 * @return a long with the altitude of the position
*/
long position_getAlt (const Position *pos);

/**
 * @brief It sets the latitude of a position
 * 
 * @param pos a pointer to a position
 * @param lat a long with the latitude of a position
 * @return OK if everything goes well, ERROR if not
*/
Status position_setLat (Position *pos, const long lat);

/**
 * @brief It sets the altitude of a position
 * 
 * @param pos a pointer to a position
 * @param alt a long with the altitude of a position
 * @return OK if everything goes well, ERROR if not
*/
Status position_setAlt (Position *pos, const long alt);

/**
 * @brief It prints the information of a position
 * 
 * @param f a pointer to a file
 * @param pos a pointer to a position
 * @return OK if everything goes well, ERROR if not
*/
Status position_print (FILE *f, const Position *pos);

#endif