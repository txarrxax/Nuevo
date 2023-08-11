/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Diego Fernández
 * @author Álvaro Grande
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include <object.h>
#include <set.h>
#include <types.h>

/**
 * @brief This struct stores all the information for the rooms
 */
typedef struct _Space Space;

/**
 * @brief Max number of spaces a game session can store
 */
#define MAX_SPACES 100

/**
 * @brief Number of lines gdesc can store
 */
#define G_SLOTS 5

/**
 * @brief Length of each gdesc line
 */
#define G_LENGTH 10

/**
 * @brief It creates a new space, allocating memory and initializing its
 * memebers
 * @author Profesores PPROG
 *
 * @param id the identification number for the new space
 * @return a new space, initialized
 */
Space *space_create(const Id id);

/**
 * @brief It destroys a space, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param space a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_destroy(Space *space);

/**
 * @brief It gets the id of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id of space
 */
Id space_get_id(const Space *space);

/**
 * @brief It sets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_set_name(Space *space, const char *name);

/**
 * @brief It gets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return  a string with the name of the space
 */
const char *space_get_name(const Space *space);

/**
 * @brief It adds an object to a given space
 * @author Diego Fernández
 *
 * @param space target space
 * @param obj_id id of the object to be added
 * @return OK if successful, ERROR if there was an issue
 */
STATUS space_add_object(Space *space, const Id obj_id);

/**
 * @brief It removes an object from a given space
 * @author Diego Fernández
 *
 * @param space target space
 * @param obj_id id of the object to be removed
 * @return OK if successful, ERROR if there was an issue
 */
STATUS space_del_object(Space *space, const Id obj_id);

/**
 * @brief Checks whether an object is in a given space or not
 * @author Diego Fernández
 *
 * @param space target space
 * @param obj_id id of the target object
 * @return TRUE if the object is in the space, FALSE if not or in case of error
 */
BOOL space_has_object(const Space *space, const Id obj_id);

/**
 * @brief It prints the space's information
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_print(Space *space);

/**
 * @brief It sets the description of the space
 * @author Álvaro Grande
 *
 * @param space a pointer to the space
 * @param desc a pointer to the description string
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_set_gdesc(Space *space, char desc[G_SLOTS][WORD_SIZE]);

/**
 * @brief It gets the description of the space
 * @author Álvaro Grande
 *
 * @param space a pointer to the space
 * @return pointer to the description string of the space
 */
const char **space_get_gdesc(const Space *space);

/**
 * @brief It sets the description of a space
 * @author Miguel Angel Sacristan
 *
 * @param space target space
 * @param description array with the description to set
 * @return OK if successful, ERROR if there was an issue
 */
STATUS space_set_description(Space *space, char *description);

/**
 * @brief It gets the description of a space
 * @author Miguel Angel Sacristan
 *
 * @param space target space
 * @return the description if successful, NULL if there was an issue
 */
const char *space_get_description(const Space *space);

/**
 * @brief It sets the illumination status of a space
 * @author Miguel Angel Sacristan
 *
 * @param space target space
 * @param light the illumination status
 * @return OK if successful, ERROR if there was an issue
 */
STATUS space_set_light(Space *space, BOOL light);

/**
 * @brief It gets the illumination status of a space
 * @author Miguel Angel Sacristan
 *
 * @param space target space
 * @return the illumination status, FALSE if there was an issue
 */
BOOL space_get_light(const Space *space);

/**
 * @brief It sets the long description of a space
 * @author Miguel Angel Sacristan
 *
 * @param space target space
 * @param new_ldes array with the long description to set
 * @return OK if successful, ERROR if there was an issue
 */
STATUS space_set_ldescription(Space *space, char *new_ldes);

/**
 * @brief It gets the long description of a space
 * @author Miguel Angel Sacristan
 *
 * @param space target space
 * @return the long description if successful, NULL if there was an issue
 */
const char *space_get_ldescription(const Space *space);

#endif
