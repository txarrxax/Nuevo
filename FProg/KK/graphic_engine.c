/**
 * @brief Implementation of the GRAPHIC_ENGINE module
 * @file graphic_engine.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "graphic_engine.h"
#include "libscreen.h"

#define ROWS 23
#define COLUMNS 80

/**
 * Graphic_engine structure
*/
struct _Graphic_engine{
        Area *map, *descript, *banner, *help, *feedback;
};
