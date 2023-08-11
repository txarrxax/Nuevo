/**
 * @brief It implements the inventory module
 *
 * @file inventory.h
 * @author Álvaro Grande
 * @author Diego Fernández
 * @version 2.0
 * @date 10/3/2023
 * @copyright GNU Public License
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <object.h>
#include <set.h>
#include <types.h>

/**
 * @brief Max inventory size
 */
#define DEF_SIZE 5

/**
 * @brief Inventory
 * A struct that defines the inventory
 */
typedef struct _Inventory Inventory;

/**
 * @brief It creates the inventory of the player
 * @author Álvaro Grande
 *
 * @return A pointer to the new inventory, NULL if there was an issue
 */
Inventory *inventory_create();

/**
 * @brief It frees the inventory
 * @author Álvaro Grande
 *
 * @param i Target inventory
 * @return OK if successful, ERROR if there was an issue
 */
STATUS inventory_destroy(Inventory *i);

/**
 * @brief It sets the max number of objects for the inventory
 * @author Álvaro Grande
 *
 * @param i Target inventory
 * @param new_max set
 * @return OK if successful, ERROR if there was an issue
 */
STATUS inventory_set_max_objs(Inventory *i, const int new_max);

/**
 * @brief It gets the max number of objects for the inventory
 * @author Álvaro Grande
 *
 * @param i Target inventory
 * @return max number of objects the inventory can have
 */
int inventory_get_max_objs(const Inventory *i);

/**
 * @brief It adds a new object to the inventory
 * @author Álvaro Grande
 *
 * @param i Target inventory
 * @param obj_id Id of the new object
 * @return OK if successful, ERROR if there was an issue
 */
STATUS inventory_add_object(Inventory *i, const Id obj_id);

/**
 * @brief It deletes an object from the inventory
 * @author Álvaro Grande
 *
 * @param i Target inventory
 * @param obj_id Id of the object to be deleted
 * @return OK if successful, ERROR if there was an issue
 */
STATUS inventory_del_object(Inventory *i, const Id obj_id);

/**
 * @brief It prints the information of the inventory
 * @author Álvaro Grande
 *
 * @param i Target inventory
 * @return OK if successful, ERROR if there was an issue
 */
STATUS inventory_print(Inventory *i);

/**
 * @brief It checks if the inventory is empty
 * @author Álvaro Grande
 *
 * @param i Target inventory
 * @return TRUE if empty, FALSE if not
 */
BOOL inventory_is_empty(Inventory *i);

/**
 * @brief It checks if the inventory has a determined object
 * @author Álvaro Grande
 *
 * @param i Target inventory
 * @param obj_id Id of the object
 * @return TRUE if the object is in the inventory, FALSE if not
 */
BOOL inventory_has_object(const Inventory *i, const Id obj_id);

/**
 * @brief It gets the pointer to the set of the inventory
 * @author Álvaro Grande
 *
 * @param i Target inventory
 * @return pointer to the set of objects
 */
const Set *inventory_get_objs(const Inventory *i);

/**
 * @brief It sets the maximun capacity of an inventory
 * @author Diego Fernández
 *
 * @param inv target inventory
 * @param cap new maximun capacity
 * @return OK if successful, ERROR if there was an issue
 */
STATUS inventory_set_cap(Inventory *inv, const int cap);

#endif
