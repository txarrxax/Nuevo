#include <stdio.h>
#include <stdlib.h>

#include "gps.h"

int main (){
    Position *orig, *dest;
    Track *track;
    GPS *g;

    /* create positions */
    orig = position_create(34, 58);
    dest = position_create(41, 71);

    /* create a track */
    track = track_create(orig, dest);

    /* create a GPS */
    g = gps_create();

    /* add the track to the gps */
    gps_addTrack(g, track);

    /* print the gps */
    gps_print(stdout, g);

    /* remove the track from the gps */
    gps_removeTrack(g, track);

    /* print the gps */
    gps_print(stdout, g);

    /* free the memory allocated */
    position_free(orig);
    position_free(dest);
    track_destroy(track);
    gps_destroy(g);

    return 0;
}