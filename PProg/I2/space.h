/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1

/**
  * @brief It creates a new space, allocating memory and initializing its memebers
  * @author Profesores PPROG
  * 
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
Space* space_create(Id id);

/**
  * @brief It destroys a space, freeing the allocated memory
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_destroy(Space* space);

/**
  * @brief It gets the id of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space  
  * @return the id of space
  */
Id space_get_id(Space* space);

/**
  * @brief It sets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_name(Space* space, char* name);

/**
  * @brief It gets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @return  a string with the name of the space
  */
const char* space_get_name(Space* space);

/**
  * @brief It sets the id of the space located at the north
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param id the id number of the space located at the north
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_north(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the north
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the north 
  */
Id space_get_north(Space* space);

/**
  * @brief It sets the id of the space located at the south
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the south
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_south(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the south
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the south 
  */
Id space_get_south(Space* space);

/**
  * @brief It sets the id of the space located at the east
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the east
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_east(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the east
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the east
  */
Id space_get_east(Space* space);

/**
  * @brief It sets the id of the space located at the west
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the west
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_west(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the west
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the west
  */
Id space_get_west(Space* space);

/**
  * @brief It adds a new object to a space
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the object to be located in the space
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_add_object(Space* space, Id id);

/**
  * @brief It deletes an object from a space
  * @author Miguel Angel Sacristan
  *
  * @param space a pointer to the space
  * @param object the id number of the object to be deleted from the space
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_destroy_object(Space *space, Id object);

/**
  * @brief It gets the number of objects that a space contains
  * @author Miguel Angel Sacristan
  *
  * @param space a pointer to the space
  * @return the number of objects in a space 
  */
int space_get_numberOfObjects(Space *space);

/**
  * @brief It gets the array of objects from a space
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return an array with the objects in a space
  */
Set *space_get_objects(Space* space);

/**
  * @brief It checks if an object is in a space
  * @author Miguel Angel Sacristan
  *
  * @param space a pointer to the space
  * @param id the id number of the object to be checked 
  * @return TRUE, if the object is in the space or FALSE if the object is NOT in the space 
  */
BOOL space_checkObject (Space *space, Id id);

/**
 * @brief It sets a graphic description to a space
 * @author Alberto Tarrasa
 * 
 * @param space a pointer to the space
 * @param desc a string with the graphic description
 * @return OK, if everything goes well or ERROR if there was some mistake
*/
STATUS space_set_gDesc (Space *space, char *desc);

/**
 * @brief It gets the graphic description of an space
 * @author Alberto Tarrasa
 * 
 * @param space a pinter to the space
 * @return an array with the strings of the graphic description
*/
char **space_get_gDesc (Space *space);

/**
  * @brief It prints the space information
  * @author Profesores PPROG
  *
  * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_print(Space* space);

#endif