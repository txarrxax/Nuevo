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

/*
 * Structure that contains the areas of a graphic engine
 */
typedef struct _Graphic_engine Graphic_engine;

/**
  * @brief It allocates memory for a new graphic engine and its areas, only if the graphic engine did not exist
  * @author Profesores PPROG
  * 
  * @return a graphic engine, initialized
  */
Graphic_engine *graphic_engine_create();

/**
  * @brief It frees the areas and the screen of an existing graphic engine
  * @author Profesores PPROG
  * 
  * @param ge a pointer to the graphic engine
  * @return no return
  */
void graphic_engine_destroy(Graphic_engine *ge);

/**
  * @brief It paints or writes on the different areas of the graphic engine
  * @author Profesores PPROG
  * 
  * @param ge pointer to a graphic engine
  * @param game the game where the graphic engine operates
  * @return no return 
  */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
