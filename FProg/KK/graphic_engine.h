/**
 * @brief Implementation of the GRAPHIC_ENGINE module
 * @file graphic_engine.h
*/

#include "game.h"

#ifndef GRAPHIC_ENGINE_H_

/**
 * @brief Graphic_engine structure
*/
typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief It creates a new graphic_engine, allocating memory for it
 * 
 * @return a pointer to Graphic_engine
*/
Graphic_engine *graphic_engine_create();

/**
 * @brief It destroys a graphic_engine, freeing the allocated memory for it
 * 
 * @param ge a pointer to a Graphic_engine
 * @return OK if everything goes well, ERROR if not
*/
Status graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief It paints and writes on the graphic_engine
 * 
 * @param ge a pointer to a Graphic_engine
 * @param game a pointer to a Game
 * @return no return
*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif /*GRAPHIC_ENGINE_*/