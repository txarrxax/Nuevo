#include <stdio.h>
#include <stdlib.h>

#include "track.h"

/* Track TAD */
struct _Track{
    Position *orig;
    Position *dest;
};

/* track_create creates a new track */
Track *track_create (const Position *orig, const Position *dest){
    Track *track = NULL;

    /* check arguments */
    if (!orig || !dest) return NULL;

    /* allocate memory */
    track = (Track *)malloc(sizeof(Track));
    if (!track) return NULL;

    /* set values */
    track->orig = (Position *)orig;
    track->dest = (Position *)dest;

    return track;
}

/* track_destroy destroys a track */
void track_destroy (Track *track){
    free(track);
}

/* track_getOrig gets the position of origin of a track */
Position *track_getOrig (const Track *track){
    /* check arguments */
    if (!track) return NULL;

    return track->orig;
}

/* track_getDest gets the position of destination of a track */
Position *track_getDest (const Track *track){
    /* check arguments */
    if (!track) return NULL;

    return track->dest;
}

/* track_setOrig sets the position of origin of a track */
Status track_setOrig (Track *track, const Position *orig){
    /* check arguments */
    if (!track || !orig) return ERROR;

    /* set values */
    track->orig = (Position *)orig;

    return OK;
}

/* track_setDest sets the position of destination of a track */
Status track_setDest (Track *track, const Position *dest){
    /* check arguments */
    if (!track || !dest) return ERROR;

    /* set values */
    track->dest = (Position *)dest;
    
    return OK;
}

/* track_print prints the information of a track */
Status track_print (FILE *f, const Track *track){
    /* check arguments */
    if (!f || !track) return ERROR;

    /* print the data */
    fprintf(f, "--> Track:\n");
    fprintf(f, "---> Position of origin: ");
    position_print(f, track->orig);
    fprintf(f, "---> Position of destination: ");
    position_print(f, track->dest);

    return OK;
}