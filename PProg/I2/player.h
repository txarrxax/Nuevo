#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "object.h"

/*
 * @brief Player
 *
 * This struct stores all the information of a player
 */
typedef struct _Player {
    Id id;                   /*!< Id number of the player, it must be unique */
    Id location;             /*!< Id location of the player, it must be unique */
    Object *player_object;   /*!< The object of the player */
    char name[WORD_SIZE +1]; /*!< Name of the player */
    int health;              /*!< Health points*/
}Player;

/**
  * @brief It creates a new player, allocating memory and initializing it
  * @author Miguel Angel Sacristan
  * 
  * @param id the identification number of the new player
  * @return a new player
  */
Player *player_create(Id id);

/**
  * @brief It frees the memory of an existing player
  * 
  * @author Miguel Angel Sacristan
  * 
  * @param player a pointer to the player to destroy
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS player_destroy(Player *player);

/**
  * @brief It gets the memory of a player
  * 
  * @author Miguel Angel Sacristan
  * 
  * @param player a pointer to the player
  * @return id number of the player
  */
Id player_get_id (Player *player);

/**
  * @brief It gets the location of a player
  * 
  * @author Miguel Angel Sacristan
  * 
  * @param player a pointer to the player
  * @return id location of the player
  */
Id player_get_location (Player *player);

/**
  * @brief It gets the name of a player
  * 
  * @author Miguel Angel Sacristan
  * 
  * @param player a pointer to the player
  * @return a pointer to the player name
  */
char *player_get_name(Player *player);

/**
  * @brief It gets the object of a player
  * 
  * @author Miguel Angel Sacristan
  * 
  * @param player a pointer to the player
  * @return a pointer to the object of the player
  */
Object *player_get_object(Player *player);

/**
  * @brief It gets the health points of a player
  * 
  * @author Alberto Tarrasa
  * 
  * @param player a pointer to the player
  * @return health points of the player
  */
int player_get_health (Player *player);

/**
  * @brief It sets the id number of a player
  * 
  * @author Miguel Angel Sacristan
  * 
  * @param player a pointer to the player
  * @param id the id to set
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS player_set_id(Player *player, Id id);

/**
  * @brief It sets the id location of a player
  * 
  * @author Miguel Angel Sacristan
  * 
  * @param player a pointer to the player
  * @param location the location to set
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS player_set_location(Player *player, Id location);

/**
  * @brief It sets the object of a player
  * 
  * @author Miguel Angel Sacristan
  * 
  * @param player a pointer to the player
  * @param object a pointer to the object to set
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS player_set_object (Player *player, Object *object);

/**
  * @brief It sets the name of a player
  * 
  * @author Miguel Angel Sacristan
  * 
  * @param player a pointer to the player
  * @param name the name to set
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS player_set_name (Player *player, char *name);

/**
  * @brief It sets the health points of a player
  * 
  * @author Alberto Tarrasa
  * 
  * @param player a pointer to the player
  * @param health the health points to set
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS player_set_health (Player *player, int health);

/**
  * @brief It prints the id, location, name and object of a player
  * 
  * @author Miguel Angel Sacristan
  * 
  * @param player a pointer to the player
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS player_print (Player *player);

#endif
