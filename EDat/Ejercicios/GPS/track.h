#ifndef TRACK_H_
#define TRACK_H_

#include "position.h"

/**
 * @brief Track TAD
*/
typedef struct _Track Track;

/**
 * @brief It creates a new track
 * 
 * @param orig a pointer to a position of origin
 * @param dest a pointer to a position of destination
 * @return a pointer to a new track
*/
Track *track_create (const Position *orig, const Position *dest);

/**
 * @brief It destroys a track
 * 
 * @param track a pointer to a track
 * @return no return
*/
void track_destroy (Track *track);

/**
 * @brief It gets the position of origin of a track
 * 
 * @param track a pointer to a track
 * @return a pointer to the position of origin
*/
Position *track_getOrig (const Track *track);

/**
 * @brief It gets the position of destination of a track
 * 
 * @param track a pointer to a track
 * @return a pointer to the position of destination
*/
Position *track_getDest (const Track *track);

/**
 * @brief It sets the position of origin of a track
 * 
 * @param track a pointer to a track
 * @param orig a pointer to the position of origin
 * @return OK if everything goes well, ERROR if not
*/
Status track_setOrig (Track *track, const Position *orig);

/**
 * @brief It sets the position of destination of a track
 * 
 * @param track a pointer to a track
 * @param dest a pointer to the position of destination
 * @return OK if everything goes well, ERROR if not
*/
Status track_setDest (Track *track, const Position *dest);

/**
 * @brief It prints the information of a track
 * 
 * @param f a pointer to a file
 * @param track a pointer to a track
 * @return OK if everything goes well, ERROR if not
*/
Status track_print (FILE *f, const Track *track);

#endif