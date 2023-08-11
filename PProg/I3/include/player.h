/**
 * @brief It defines the player interface
 *
 * @file player.h
 * @author Diego Fernández
 * @version 1.0
 * @date 14-2-2023
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <inventory.h>
#include <object.h>
#include <types.h>

/**
 * @brief This struct stores all the information for players
 */
typedef struct _Player Player;

/**
 * @brief It creates a new player struct, allocating memory for it
 * @author Diego Fernández
 *
 * @return a pointer to the new player
 */
Player *player_create();

/**
 * @brief Destroys the player
 * @author Diego Fernández
 *
 * @param p player to be destroyed
 */
void player_destroy(Player *p);

/**
 * @brief Finds the id of a player
 * @author Diego Fernández
 *
 * @param p target player
 * @return Id of the target player, NO_ID if there was an issue
 */
Id player_get_id(const Player *p);

/**
 * @brief Sets the id of a player
 * @author Diego Fernández
 *
 * @param p target player
 * @param new_id the new id
 * @return OK if successful, ERROR if there was an issue
 */
STATUS player_set_id(Player *p, const Id new_id);

/**
 * @brief Gets the struct for the inventory of the player
 * @author Álvaro Grande
 *
 * @param p target player
 * @return pointer to player's inventory, NULL if there was an issue
 */
const Inventory *player_get_inventory(const Player *p);

/**
 * @brief Adds a new item to the player's inventory
 * @author Álvaro Grande
 *
 * @param p target player
 * @param item_id id number of the item to add
 * @return OK if successful, NULL if there was an issue
 */
STATUS player_add_item(Player *p, const Id item_id);

/**
 * @brief Deletes an item from the player's inventory
 * @author Álvaro Grande
 *
 * @param p target player
 * @param item_id id number of the item to delete
 * @return OK if successful, NULL if there was an issue
 */
STATUS player_del_item(Player *p, const Id item_id);

/**
 * @brief Finds the location of a player
 * @author Diego Fernández
 *
 * @param p target player
 * @return id of the room where the player is located, NO_ID if there was an
 * issue
 */
Id player_get_location(const Player *p);

/**
 * @brief Sets the location of a player
 * @author Diego Fernández
 *
 * @param p target player
 * @param new_loc id of the room where the player will be located
 * @return OK if successful, ERROR if there was an issue
 */
STATUS player_set_location(Player *p, const Id new_loc);

/**
 * @brief Finds the name of a player
 * @author Diego Fernández
 *
 * @param p target player
 * @return const pointer to the name of the player, NULL if there was an error
 */
const char *player_get_name(const Player *p);

/**
 * @brief Sets the name of a player
 * @author Diego Fernández
 *
 * @param p target player
 * @param new_name pointer to the new name
 * @return OK if successful, ERROR if there was an issue
 */
STATUS player_set_name(Player *p, const char *new_name);

/**
 * @brief It gets the health of a given player
 * @author Diego Fernández
 *
 * @param p target player
 * @return the player health or -1 if there was an issue
 */
int player_get_health(const Player *p);

/**
 * @brief It sets the health of a player
 * @author Diego Fernández
 *
 * @param p target player
 * @param new_health the health points to be assigned
 * @return OK if successful, ERROR if there was an issue
 */
STATUS player_set_health(Player *p, const int new_health);

/**
 * @brief Prints the information of a player
 * @author Diego Fernández
 *
 * @param p target player
 * @return OK if successful, ERROR if there was an issue
 */
STATUS player_print(const Player *p);

/**
 * @brief It sets the max cap of the player's inventory
 * @author Diego Fernández
 *
 * @param p target player
 * @param cap new capacity
 * @return OK if successful, ERROR if there was an issue
 */
STATUS player_set_inv_cap(Player *p, const int cap);

#endif
