/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

Graphic_engine *graphic_engine_create();
void graphic_engine_destroy(Graphic_engine *ge);
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
