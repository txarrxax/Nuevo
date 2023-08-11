#ifndef ENEMY_H
#define ENEMY_H

#include "types.h"

/**
  * @brief 
  * @author Alberto Tarrasa
  * 
  * @param
  * @return 
  */

/**
  * @brief Enemy
  * 
  * This struct stores all the information of an enemy
  */

typedef struct _Enemy {
    Id id;                   /*!< Id number of the enemy, it must be unique */
    Id location;             /*!< Id number of the location of the enemy, it must be unique */
    char name[WORD_SIZE +1]; /*!< Name of the enemy*/
    int health;              /*!< Health points */
}Enemy;

/**
  * @brief It creates a new enemy, allocating memory and initializing it
  * @author Alberto Tarrasa
  * 
  * @param id the identification number of the new enemy
  * @return a new enemy
  */
Enemy *enemy_create (Id id);

/**
  * @brief It frees the memory of an existing enemy
  * @author Alberto Tarrasa
  * 
  * @param enemy a pointer to the enemy to destroy
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS enemy_destroy (Enemy *enemy);

/**
  * @brief It gets the id of an enemy
  * @author Alberto Tarrasa
  * 
  * @param enemy a pointer to the enemy
  * @return id number of the enemy
  */
Id enemy_get_id (Enemy *enemy);

/**
  * @brief It gets the location of an enemy
  * 
  * @author Alberto Tarrasa
  * 
  * @param enemy a pointer to the enemy
  * @return id location of the enemy
  */
Id enemy_get_location (Enemy *enemy);

/**
  * @brief It gets the name of an enemy
  * 
  * @author Alberto Tarrasa
  * 
  * @param enemy a pointer to the enemy
  * @return a pointer to the enemy name
  */
char *enemy_get_name(Enemy *enemy);

/**
  * @brief It gets the health points of an enemy
  * 
  * @author Alberto Tarrasa
  * 
  * @param enemy a pointer to the enemy
  * @return health points of the enemy
  */
int enemy_get_health (Enemy *enemy);

/**
  * @brief It sets the id number of an enemy
  * 
  * @author Alberto Tarrasa
  * 
  * @param enemy a pointer to the enemy
  * @param id the id to set
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS enemy_set_id (Enemy *enemy, Id id);

/**
  * @brief It sets the id location of an enemy
  * 
  * @author Alberto Tarrasa
  * 
  * @param enemy a pointer to the enemy
  * @param location the location to set
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS enemy_set_location (Enemy *enemy, Id location);

/**
  * @brief It sets the name of an enemy
  * 
  * @author Alberto Tarrasa
  * 
  * @param enemy a pointer to the enemy
  * @param name the name to set
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS enemy_set_name (Enemy *enemy, char *name);

/**
  * @brief It sets the health points of an enemy
  * 
  * @author Alberto Tarrasa
  * 
  * @param enemy a pointer to the enemy
  * @param health the health points to set
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS enemy_set_health (Enemy *enemy, int health);

/**
  * @brief It prints the id, location, name and health points of an enemy
  * 
  * @author Alberto Tarrasa
  * 
  * @param player a pointer to the enemy
  * @return OK, if everything goes well or ERROR if there was a mistake
  */
STATUS enemy_print (Enemy *enemy);
#endif