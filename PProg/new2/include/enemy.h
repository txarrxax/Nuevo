/**
 * @brief It implements the enemy module
 *
 * @file enemy.h
 * @author Álvaro Grande
 * @version 1.0
 * @date 14-2-2023
 * @copyright GNU Public License
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <types.h>

/**
 * @brief This struct stores all the information for enemies
 */
typedef struct _Enemy Enemy;

/**
 * @brief It creates a new enemy struct, allocating memory for it
 * @author Álvaro Grande
 *
 * @return a pointer to the new enemy
 */
Enemy *enemy_create();

/**
 * @brief Destroys the enemy
 * @author Álvaro Grande
 *
 * @param e enemy to be destroyed
 */
STATUS enemy_destroy(Enemy *e);

/**
 * @brief Finds the id of an enemy
 * @author Álvaro Grande
 *
 * @param e target enemy
 * @return Id of the target enemy, NO_ID if there was an issue
 */
Id enemy_get_id(const Enemy *e);

/**
 * @brief Sets the id of an enem
 * @author Álvaro Grande
 *
 * @param e target enemy
 * @param new_id the new id
 * @return OK if successful, ERROR if there was an issue
 */
STATUS enemy_set_id(Enemy *e, const Id new_id);

/**
 * @brief Finds the location of an enemy
 * @author Álvaro Grande
 *
 * @param e target enemy
 * @return id of the room where the enemy is located, NO_ID if there was an issue
 */
Id enemy_get_location(const Enemy *e);

/**
 * @brief Sets the location of an enemy
 * @author Álvaro Grande
 *
 * @param e target enemy
 * @param new_location id of the room where the enemy will be located
 * @return OK if successful, ERROR if there was an issue
 */
STATUS enemy_set_location(Enemy *e, const Id new_location);

/**
 * @brief Finds the name of an enemy
 * @author Álvaro Grande
 *
 * @param e target enemy
 * @return const pointer to the name of the enemy, NULL if there was an error
 */
const char *enemy_get_name(const Enemy *e);

/**
 * @brief Sets the name of an enemy
 * @author Álvaro Grande
 *
 * @param e target enemy
 * @param new_name pointer to the new name
 * @return OK if successful, ERROR if there was an issue
 */
STATUS enemy_set_name(Enemy *e, const char *new_name);

/**
 * @brief Finds the health of an enemy
 * @author Álvaro Grande
 *
 * @param e target enemy
 * @return the points of health of the enemy,-1 if there was an issue
 */
int enemy_get_health(const Enemy *e);

/**
 * @brief Sets the health of an enemy
 * @author Álvaro Grande
 *
 * @param e target enemy
 * @param new_health the new health for the enemy
 * @return OK if successful, ERROR if there was an issue
 */
STATUS enemy_set_health(Enemy *e, const int new_health);

/**
 * @brief Prints the information of an enemy
 * @author Álvaro Grande
 *
 * @param e target enemy
 * @return OK if successful, ERROR if there was an issue
 */
STATUS enemy_print(const Enemy *e);

/**
 * @brief it gets the strength of an enemy
 * @author Diego Fernández
 *
 * @param e target enemy
 * @return strength stat, 0 if there was an issue
 */
int enemy_get_strength(const Enemy *e);

/**
 * @brief It sets the strength of an enemy
 * @author Diego Fernández
 *
 * @param e target enemy
 * @param strength new strength stat
 * @return OK if successful, ERROR if there was an issue
 */
STATUS enemy_set_strength(Enemy *e, const int strength);

#endif
