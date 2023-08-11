/**
 * @brief It implements the set interface
 *
 * @file set.h
 * @author Diego Fernández
 * @version 2.0
 * @date 10/3/2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <types.h>

#ifndef SET_H
#define SET_H

/**
 * A struct that contains a set of ids
 */
typedef struct _Set Set;

/**
 * @brief It creates a new set
 * @author Diego Fernández
 *
 * @return A pointer to the new set, NULL if there was an issue
 */
Set *set_create();

/**
 * @brief It frees a given set
 * @author Diego Fernández
 *
 * @param set Target set
 */
STATUS set_destroy(Set *set);

/**
 * @brief It checks whether a set is empty or not
 * @author Diego Fernández
 *
 * @param set target set
 * @return TRUE if the set is empty or there was an issue, FALSE otherwise
 */
BOOL set_is_empty(const Set *set);

/**
 * @brief It adds a new id to a set
 * @author Diego Fernández
 *
 * @param set target set
 * @param id new id to add
 * @return OK if successful, ERROR if there was an issue
 */
STATUS set_add(Set *set, const Id id);

/**
 * @brief It deletes an id from a set
 * @author Diego Fernández
 *
 * @param set target set
 * @param id id to delete
 * @return OK if successful, ERROR if there was an issue
 */
STATUS set_del(Set *set, const Id id);

/**
 * @brief It prints the contents of a set
 * @author Diego Fernández
 *
 * @param set target set
 * @return OK if successful, ERROR if there was an issue
 */
STATUS set_print(const Set *set);

/**
 * @brief It gets the size of a given set
 * @author Diego Fernández
 *
 * @param set target set
 * @return the size of the set if successful, -1 if there was an issue
 */
int set_get_size(const Set *set);


/**
 * @brief It gets the array of ids from a set
 * @author Diego Fernández
 *
 * @param set target set
 * @return pointer to the array if successful, NULL if there was an issue
 */
const Id *set_get_ids(const Set *set);

/**
 * @brief It checks whether an id is within a set or not
 * @author Diego Fernández
 *
 * @param set target set
 * @param id id that will be searched in the set
 * @return TRUE if the id is whitin the set, FALSE otherwise
 */
BOOL set_has_id(const Set *set, const Id id);

#endif
