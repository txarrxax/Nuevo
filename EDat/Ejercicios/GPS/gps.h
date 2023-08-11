#ifndef GPS_H_
#define GPS_H_

#include "track.h"

/**
 * @brief GPS TAD
*/
typedef struct _GPS GPS;

/**
 * @brief It creates a new GPS
 * 
 * @return a pointer to a new GPS
*/
GPS *gps_create ();

/**
 * @brief It destroys a GPS
 * 
 * @param g a pointer to a GPS
 * @return no return
*/
void gps_destroy (GPS *g);

/**
 * @brief It adds a new track to a GPS
 * 
 * @param g a pointer to a GPS
 * @param track a pointer to a track
 * @return OK if everything goes well, ERROR if not
*/
Status gps_addTrack (GPS *g, const Track *track);

/**
 * @brief It removes a track from a GPS
 * 
 * @param g a pointer to a GPS
 * @param track a pointer to a track
 * @return OK if everyhting goes well, ERROR if not
*/
Status gps_removeTrack (GPS *g, const Track *track);

/**
 * @brief It gets the number of tracks of a GPS
 * 
 * @param g a pointer to a GPS
 * @return an integer with the number of tracks of a GPS
*/
int gps_getNumberOfTracks (const GPS *g);

/**
 * @brief It prints the information of a GPS
 * 
 * @param f a pointer to a file
 * @param g a pointer to a GPS
 * @return OK if everything goes well, ERROR if not
*/
Status gps_print (FILE *f, const GPS *g);

#endif