/**
 * @brief Implementation of the PLAYER module
 * @file player.h
*/

#include "board.h"

#ifndef PLAYER_H_

/**
 * @brief Player structure
*/
typedef struct _Player Player;

/**
 * @brief It creates a new player, allocating memory for it
 * 
 * @return a pointer to Player
*/
Player *player_create(const Id id, const int rows, const int columns);

/**
 * @brief It destroys a player, freeing the allocated memory for it
 * 
 * @param player a pointer to a Player
 * @return OK if everything goes well, ERROR if not
*/
Status player_destroy(Player *player);

/**
 * @brief It gets a player's id number
 * 
 * @param player a pointer to a Player
 * @return the id number of the player
*/
Id player_get_id(const Player *player);

/**
 * @brief It sets a player's name
 * 
 * @param player a pointer to a Player
 * @param name a string with a name
 * @return OK if everything goes well, ERROR if not
*/
Status player_set_name(Player *player, const char *name);

/**
 * @brief It gets a player's name
 * 
 * @param player a pointer to a Player
 * @return a string with the name of the player
*/
char *player_get_name(const Player *player);

/**
 * @brief It gets a pointer to the player's board
 * 
 * @param player a pointer to a Player
 * @return a pointer to the player's board
*/
Board *player_get_board(const Player *player);


#endif