#include <stdio.h>
#include <stdlib.h>

#include "position.h"

/* Position TAD */
struct _Position{
    long lat;
    long alt;
};

/* position_create creates a new position */
Position *position_create (const long lat, const long alt){
    Position *pos = NULL;

    /* check arguments */
    if (lat < 0 || alt < 0) return NULL;

    /* allocate memory */
    pos = (Position *)malloc(sizeof(Position));
    if (!pos) return NULL;

    /* set values */
    pos->lat = lat;
    pos->alt = alt;
    
    return pos;
}

/* position_free destroys a position */
void position_free (Position *pos){
    free(pos);
}

/* position_getLat gets the latitude of a position */
long position_getLat (const Position *pos){
    /* check arguments */
    if (!pos) return -1;

    return pos->lat;
}

/* position_getAlt gets the altitude of a position */
long position_getAlt (const Position *pos){
    /* check arguments */
    if (!pos) return -1;

    return pos->alt;
}

/* position_setLat sets the latitude of a position */
Status position_setLat (Position *pos, const long lat){
    /* check arguments */
    if (!pos || lat < 0) return ERROR;

    /* set values */
    pos->lat = lat;
    
    return OK;
}

/* position_setAlt sets the altitude of a position */
Status position_setAlt (Position *pos, const long alt){
    /* check arguments */
    if (!pos || alt < 0) return ERROR;

    /* set values */
    pos->alt = alt;

    return OK;
}

/* position_print prints the information of a position */
Status position_print (FILE *f, const Position *pos){
    /* check arguments */
    if (!f || !pos) return ERROR;

    /* print the data */
    fprintf(f, "(%ld, %ld)\n", pos->lat, pos->alt);

    return OK;
}