/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Diego Fernández
 * @author Álvaro Grande
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

/**
 * @brief Max number of games that can be stored in a game session
 */
#define MAX_OBJ 20

#include <command.h>
#include <enemy.h>
#include <link.h>
#include <object.h>
#include <player.h>
#include <space.h>
#include <types.h>


/**
 * @brief Struct that stores the information of the game
 */
typedef struct _Game Game;

/**
 * @brief It creates a new game from a file
 * @author Profesores PPROG
 *
 * @param game pointer to the game struct where the new game session will be
 * stored
 * @param filename path to the file where the data for the new game is found
 * @return OK if successful or ERROR if there was an issue
 */
STATUS game_create_from_file(Game **game, const char *filename);

/**
 * @brief It deletes a game session
 * @author Profesores PPROG
 * @author Diego Fernández
 *
 * @param game a pointer to the game session to be deleted
 * @return OK if successful or ERROR if there was an issue
 */
STATUS game_destroy(Game *game);

/**
 * @brief Adds a room to the game session
 * @author Álvaro Grande
 *
 * @param game a pointer to the game session
 * @param space space to be added
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_add_space(Game *game, Space *space);

/**
 * @brief It finds a space that has the given id
 * @author Profesores PPROG
 *
 * @param game a pointer to the game session
 * @param id the id of the space being searched
 * @return pointer to the found space or NULL if no coincidences were found
 */
Space *game_get_space(const Game *game, const Id id);

/**
 * @brief It updates the state of the game with a command
 * @author Profesores PPROG
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param cmd the command read from the user
 * @param arg parameters for the command
 * @return OK if successful or ERROR if there was an issue
 */
STATUS game_update(Game *game, const T_Command cmd, const char *arg);

/**
 * @brief It checks whether gameover conditions have been reached or not
 * @author Profesores PPROG
 *
 * @param game a pointer to the game session
 * @return TRUE if gameover conditions are met, FALSE otherwise
 */
BOOL game_is_over(const Game *game);

/**
 * @brief It gets the last command used
 * @author Profesores PPROG
 *
 * @param game a pointer to the game session
 * @return last command used
 */
T_Command game_get_last_command(const Game *game);

/**
 * @brief It prints data of the current game state to the console
 * @author Profesores PPROG
 *
 * @param game a pointer to the game session
 * @return OK if successful, ERROR if not
 */
STATUS game_print_data(const Game *game);

/**
 * @brief Gets the location of an object
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param object a pointer to the target object
 * @return The location of the object, NO_ID if there was an issue
 */
Id game_get_object_location(const Game *game, const Object *object);

/**
 * @brief Adds a new object to the game
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param object a pointer to the target object
 * @return OK if the object was added, else ERROR
 */
STATUS game_add_object(Game *game, Object *object);

/**
 * @brief Gets the player of the game
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @return a pointer to the player, NULL if there was an issue
 */
Player *game_get_player(Game *game);

/**
 * @brief Gets the enemy of the game
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @return a pointer to the enemy, NULL if there was an issue
 */
Enemy *game_get_enemy(Game *game);

/**
 * @brief Gets the number of objects contained in the game
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @return the number of objects in the game, -1 if there was an issue
 */
int game_get_number_of_objects(Game *game);

/**
 * @brief Gets an object from its position in the game
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param position an integer with the objects position
 * @return a pointer to the object, NULL if there was an issue
 */
Object *game_get_object_from_position(Game *game, int position);

/**
 * @brief Gets the STATUS of the last command
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @return the STATUS of the last command
 */
STATUS game_get_last_command_exit(Game *game);

/**
 * @brief Gets the STATUS of a connection
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param space id of the origin space
 * @param dir DIRECTION of the link to check
 * @return OK if there is a connection from the space, ERROR if the connection
 * does NOT exist or there was an issue
 */
STATUS game_get_connection_status(Game *game, Id space, DIRECTION dir);

/**
 * @brief Gets the id of the destination link
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param space id of the origin space
 * @param dir DIRECTION of the link
 * @return the id of the destination space
 */
Id game_get_connection(Game *game, Id space, DIRECTION dir);

/**
 * @brief It adds a new link to the game
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param link the link to add
 * @return OK if the link was added successfully, else ERROR
 */
STATUS game_add_link(Game *game, Link *link);

/**
 * @brief It initializes an empty game session
 * @author Profesores PPROG
 * @author Diego Fernández
 *
 * @param game double pointer to the game struct that will be initialized
 * @return OK if successful, ERROR if the argument was NULL
 */
STATUS game_create(Game **game);

/**
 * @brief Sets the last description of the game
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param des the new description
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_set_last_description(Game *game, char *des);

/**
 * @brief Sets the last description of the game
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @return the last description of the game
 */
char *game_get_last_description(Game *game);

/**
 * @brief It gets an object from its id
 * @author Diego Fernández
 *
 * @param g game session
 * @param id id of the object
 * @return pointer to target object, NULL if there was an issue
 */
Object *game_get_object_from_id(const Game *g, const Id id);

/**
 * @brief It gets an object from its name
 * @author Diego Fernández
 *
 * @param g game session
 * @param name target name
 * @return pointer to the target object, NULL if there was an issue
 */
Object *game_get_object_from_name(const Game *g, const char *name);

/**
 * @brief It prints the visualization of the objects within a space to a
 * variable
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param space target space
 * @param res pointer to which the output will be written
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_get_space_obj_desc(Game *game, const Space *space, char *res);

#endif
