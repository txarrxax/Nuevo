/**
 * @brief It defines the game_reader interface
 *
 * @file game_reader.h
 * @author Alberto Tarrasa
 * @version 2.0
 * @date 07-02-3
 * @copyright GNU Public License
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "game.h"

/**
  * @brief It loads the spaces from a file
  * @author Profesores PPROG
  *
  * @param game a pointer to the current game
  * @param filename an array with the name of the file
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_reader_load_spaces(Game *game, char *filename);

/**
  * @brief It loads the objects from a file
  * @author Miguel Ángel Sacristán
  *
  * @param game a pointer to the current game
  * @param filename an array with the name of the file
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_reader_load_objects(Game *game, char *filename);

#endif 