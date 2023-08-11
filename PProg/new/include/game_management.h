/**
 * @brief It implements the loading of spaces
 *
 * @file game_management.h
 * @author Álvaro Grande
 * @author Diego Fernández
 * @version 2.0
 * @date 14/2/2023
 * @copyright GNU Public License
 */

#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include <types.h>
#include <game.h>
#include <space.h>

/**
 * @brief It reads the file where the space data is allocated and creates the space
 * @author Álvaro Grande
 *
 * @param game the pointer to the game struct that will be initialized
 * @param filename the name of the file where the room data will be read
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_spaces(Game *game, const char *filename);

/**
 * @brief It reads the file where the object data is allocated and creates the objects
 * @author Álvaro Grande
 *
 * @param game the pointer to the game struct that will be initialized
 * @param filename the name of the file where the object data will be read
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_objects(Game *game, const char *filename);

/**
 * @brief It creates a player from the data of a given file
 * @author Diego Fernández
 *
 * @param game game session
 * @param filename target file
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_management_load_player(Game *game, const char *filename);

/**
 * @brief It loads the enemies from a file
 * @author Diego Fernández
 *
 * @param game game session
 * @param filename target file
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_management_load_enemies(Game *game, const char *filename);

/**
 * @brief It reads the file where the link data is allocated and creates the link
 * @author Alberto Tarrasa
 *
 * @param game the pointer to the game struct that will be initialized
 * @param filename the name of the file where the link data will be read
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS game_management_load_links(Game *game, const char *filename);

/**
 * @brief It saves the state of the spaces of a game session in a given file stream
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param f file stream
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_management_save_spaces(const Game *game, FILE *f);

/**
 * @brief It saves the state of the player in a given file stream
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param f file stream
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_management_save_player(const Game *game, FILE *f);

/**
 * @brief It saves the state of the objects in a given file stream
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param f file stream
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_management_save_objects(const Game *game, FILE *f);

/**
 * @brief It saves the state of enemies in a given file stream
 * @author Diego Fernández
 *
 * @param game a pointer to a game session
 * @param f file stream
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_management_save_enemies(const Game *game, FILE *f);

/**
 * @brief It saves the state of the links in a given file stream
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param f file stream
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_management_save_links(const Game *game, FILE *f);

#endif
