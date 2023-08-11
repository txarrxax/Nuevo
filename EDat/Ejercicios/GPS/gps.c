#include <stdio.h>
#include <stdlib.h>

#include "gps.h"

#define MAX_TRACKS 100

/* GPS TAD */
struct _GPS{
    Track *tracks[MAX_TRACKS];
    int num_tracks;
};

/*<------------------------------------------------------->*/
Bool _gps_isFull (const GPS *g){
    /* check arguments */
    if (!g) return TRUE;

    /* check if the GPS is full */
    if (g->num_tracks == MAX_TRACKS) return TRUE;

    return FALSE;
}

int _gps_hasTrack (const GPS *g, const Track *track){
    int i;

    /* check arguments */
    if (!g || !track) return -1;

    /* finde the track */
    for (i=0; i<MAX_TRACKS; i++)
        if (g->tracks[i] == track)
            return i;
    
    return -1;
}

Bool _gps_isEmpty (const GPS *g){
    /* check arguments */
    if (!g) return TRUE;

    /* check if the GPS is empty */
    if (g->num_tracks == 0) return TRUE;

    return FALSE;
}
/*<------------------------------------------------------->*/

/* gps_create creates a new GPS */
GPS *gps_create (){
    GPS *g = NULL;
    int i;

    /* allocate memory */
    g = (GPS *)malloc(sizeof(GPS));
    if (!g) return NULL;

    /* set values */
    g->num_tracks = 0;
    for (i=0; i<MAX_TRACKS; i++)
        g->tracks[i] = NULL;
    
    return g;
}

/* gps_destroy destroys a GPS */
void gps_destroy (GPS *g){
    free(g);
}

/* gps_addTrack adds a new track to a GPS */
Status gps_addTrack (GPS *g, const Track *track){
    int i;

    /* check arguments */
    if (!g || !track || _gps_isFull(g) || _gps_hasTrack(g, track) != -1) return ERROR;

    /* add the track */
    for (i=0; i<MAX_TRACKS; i++){
        if (!g->tracks[i]){
            g->tracks[i] = (Track *)track;
            g->num_tracks++;
            break;
        }
    }

    return OK;
}

/* gps_removeTrack removes a track from a GPS */
Status gps_removeTrack (GPS *g, const Track *track){
    int i;
    
    /* check arguments */
    if (!g || !track || _gps_isEmpty(g) || (i = _gps_hasTrack(g, track) == -1)) return ERROR;

    /* remove the track */
    g->tracks[i] = NULL;
    g->num_tracks--;

    return OK;
}

/* gps_getNumberOfTracks gets the number of tracks of a GPS */
int gps_getNumberOfTracks (const GPS *g){
    /* check arguments */
    if (!g) return -1;

    return g->num_tracks;
}

/* gps_print prints the information of a GPS */
Status gps_print (FILE *f, const GPS *g){
    int i;
    /* check arguments */
    if (!f || !g) return ERROR;

    /* print the data */
    fprintf(f, "-> GPS\n");
    for (i=0; i<MAX_TRACKS; i++){
        if (g->tracks[i])
            track_print(f, g->tracks[i]);
    }

    return OK;
}