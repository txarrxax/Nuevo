/** 
 * @brief It implements the object module
 * 
 * @file object.h
 * @author Álvaro Grande
 * @version 2.0 
 * @date 15/2/2023
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <types.h>

/**
 * @brief Struct that stores the information of objects
 */
typedef struct _Object Object;

/**
  * @brief It gets the id of the object
  * @author Álvaro Grande
  * 
  * @param object the pointer to the object struct
  * @return Id of the object 
  */
Id object_get_id (const Object *object);

/**
  * @brief It gets the name of the object
  * @author Álvaro Grande
  * 
  * @param object the pointer to the object struct
  * @return the name of the object
  */
const char * object_get_name (const Object *object);

/**
  * @brief It sets a new name for an object
  * @author Álvaro Grande
  * 
  * @param object the pointer to the object struct
  * @param name the new name for the object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_set_name (Object *object, const char *name);

/**
  * @brief It gets the description of the object
  * @author Miguel Angel Sacristan
  * 
  * @param object the pointer to the object struct
  * @return the description of the object or NULL if there was some mistake
  */
const char * object_get_desc(const Object *object);

/**
  * @brief It sets a new description for an object
  * @author Miguel Angel Sacristan
  * 
  * @param object the pointer to the object struct
  * @param desc the new description for the object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_set_desc(Object *object, const char *desc);


/**
  * @brief It creates a new object
  * @author Álvaro Grande
  * 
  * @return a pointer to the new object
  */
Object* object_create();

/**
  * @brief It erases an object
  * @author Álvaro Grande
  * 
  * @param object the pointer to the object struct that will be erased
  */
void object_destroy(Object *object);

/**
  * @brief It prints the object information 
  * @author Álvaro Grande
  * 
  * @param object the pointer to the object struct whose information will be printed
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_print(const Object* object);

/**
 * @brief It sets the id of the object
 * @author Álvaro Grande
 *
 * @param object target object
 * @param id new id
 * @return OK if successful, ERROR if there was an issue
 */
STATUS object_set_id (Object *object, const Id id);

#endif
