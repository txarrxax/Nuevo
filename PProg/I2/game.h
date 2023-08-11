/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "player.h"
#include "object.h"
#include "enemy.h"

#define MAX_ARG 128

typedef struct _Game {
  Player *player;               /*!< Pointer to the player */
  Enemy *enemy;                 /*!< Pointer to the enemy */
  Object *objects[MAX_OBJECTS]; /*!< Objects array containing all the objects for the game */
  Space *spaces[MAX_SPACES];    /*!< Spaces array containing all the spaces for the game */
  T_Command last_cmd;           /*!< Last command taken from que user */
  STATUS st_last_cmd;           /*!< Status of the last command used */
} Game;

/**
  * @brief It creates a new game, deleting the information saved in the memory
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game that must be created
  * @return OK,if everything goes well or ERROR if there was some mistake
  */
STATUS game_create(Game *game);

/**
  * @brief It sets the object and the player in the first location
  * @author Profesores PPROG
  * 
  * @param game a pointer to the game created, filename a pointer to a file
  * @return OK,if everything goes well or ERROR if there was some mistake
  */
STATUS game_create_from_file(Game *game, char *filename);

/**
  * @brief It selects the next command taken for the game
  * @author Profesores PPROG
  * 
  * @param game a pointer to the current game, cmd a new command introduced
  * @return OK,if everything goes well or ERROR if there was some mistake
  */
STATUS game_update(Game *game, T_Command cmd);

/**
  * @brief It destroys the game and the spaces in it
  * @author Profesores PPROG
  * 
  * @param game a pointer to the current game
  * @return OK,if everything goes well or ERROR if there was some mistake
  */
STATUS game_destroy(Game *game);

/**
  * @brief It decides if the game has ended
  * @author Profesores PPROG
  * 
  * @param game a pointer to the current game
  * @return FALSE
  */
BOOL game_is_over(Game *game);

/**
  * @brief It prints the information about the spaces, the object's location and the player's location
  * @author Profesores PPROG
  * 
  * @param game a pointer to the current game
  * @return no return
  */
void game_print_data(Game *game);

/**
  * @brief It selects an specific space from the current game
  * @author Profesores PPROG
  * 
  * @param game a pointer to the current game
  * @param id the identification number of the space selected
  * @return the space selected if everything goes well or NULL if the was some mistake
  */
Space *game_get_space(Game *game, Id id);

/**
  * @brief It takes the player's location
  * @author Profesores PPROG
  * 
  * @param game a pointer to the current game
  * @return the id of the space where the player is located
  */
Id game_get_player_location(Game *game);

/**
  * @brief It takes the enemy's location
  * @author Profesores PPROG
  * 
  * @param game a pointer to the current game
  * @return the id of the space where the enemy is located
  */
Id game_get_enemy_location(Game *game);


/**
  * @brief It takes the object's location
  * @author Profesores PPROG
  * 
  * @param game a pointer to the current game
  * @return the id of the space where the object is located
  */
Id game_get_object_location(Game *game, Id object);

/**
  * @brief It takes the object's location
  * @author Miguel Angel Sacristan
  * 
  * @param game a pointer to the current game
  * @param object the id of the object to get
  * @return the object with matching ids or NO_ID
  */
Object *game_get_object(Game *game, Id object);

/**
  * @brief It takes the last command used
  * @author Profesores PPROG
  * 
  * @param game a pointer to the current game
  * @return the last command taken by the user
  */
T_Command game_get_last_command(Game *game);

/**
 * @brief It takes the status of the last command used
 * @author Alberto Tarrasa
 * 
 * @param game a pointer to the current game
 * @return the status of the last command taken by the user
*/
STATUS game_get_last_commandSt(Game *game);

/**
  * @brief It adds a new space to the current game
  * @author Profesores PPROG
  *
  * @param game a pointer to the current game
  * @param space a pointer to the new space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_add_space(Game *game, Space *space);

/**
  * @brief It adds a new object to the current game
  * @author Miguel Angel Sacristan
  *
  * @param game a pointer to the current game
  * @param object a pointer to the new object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_add_object(Game *game, Object *object);

/**
  * @brief It gets the id number of a given space's location
  * @author Profesores PPROG
  *
  * @param game a pointer to the current game
  * @param position an integer with the position of the space
  * @return the space id, if everything goes well or NO_ID if there was some mistake
  */
Id game_get_space_id_at(Game *game, int position);

/**
  * @brief It sets the player's location
  * @author Profesores PPROG
  *
  * @param game a pointer to the current game
  * @param id number of the player location
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_set_player_location(Game *game, Id id);

/**
  * @brief It sets the enemy's location
  * @author Profesores PPROG
  *
  * @param game a pointer to the current game
  * @param id number of the enemy location
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_set_enemy_location(Game *game, Id id);

/**
  * @brief It sets an object's location
  * @author Miguel Angel Sacristan
  *
  * @param game a pointer to the current game
  * @param object number of the object
  * @param location number of the new object location
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_set_object_location(Game *game, Id object, Id location);

/**
  * @brief It makes the player take the object
  * @author Miguel Angel Sacristan
  *
  * @param game a pointer to the current game
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS game_command_take(Game *game);

/**
  * @brief It makes the player drop the object
  * @author Miguel Angel Sacristan
  *
  * @param game a pointer to the current game
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS game_command_drop(Game *game);

/**
  * @brief It lets the player attack the enemy
  * @author Alberto Tarrasa
  *
  * @param game a pointer to the current game
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_command_attack(Game *game);
#endif











