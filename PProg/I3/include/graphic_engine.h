/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Diego Fernández
 * @author Álvaro Grande
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include <game.h>

/**
 * @brief This struct contains all the elements of the graphic engine
 */
typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief It creates a new graphic engine
 * @author Profesores PPROG
 *
 * @return pointer to the new graphic engine, NULL if there was an issue
 */
Graphic_engine *graphic_engine_create();

/**
 * @brief It destroys a given graphic engine
 * @author Profesores PPROG
 *
 * @param ge graphic engine to be destroyed
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief It outputs the contents of the graphic engine to the interface
 * @author Profesores PPROG
 *
 * @param ge graphic engine
 * @param game game session
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
