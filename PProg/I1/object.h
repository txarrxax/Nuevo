/**
 * @brief It defines the object interface
 * 
 * @file object.h
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 06-02-2023
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"


/**
 * @brief Object
 *
 * This struct stores all the information of an object
 */
typedef struct _Object{
    Id id;                   /*!< Id number of the object, it must be unique */
    Id location;             /*!< Id number of the object's location */
    char name[WORD_SIZE +1]; /*!< Name of the object */
}Object;

#define MAX_OBJECTS 100
#define FIRST_OBJECT 1

/**
  * @brief It creates a new object, allocating memory and initializing it
  * @author Alberto Tarrasa
  * 
  * @param id the identification number for the new object
  * @return a new object, initialized
  */
Object *object_create(Id id);

/**
  * @brief It destroys an object, freeing the allocated memory
  * @author Alberto Tarasa
  * 
  * @param object a pointer to the object that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_destroy(Object* object);

/**
  * @brief It gets the id of an object
  * @author Alberto Tarrasa
  * 
  * @param object a pointer to the object  
  * @return the id of the object
  */
Id object_get_id(Object* object);

/**
  * @brief It sets the name of an object
  * @author Alberto Tarrasa
  * 
  * @param object a pointer to the space
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_name(Object* object, char* name);

/**
  * @brief It gets the name of an object
  * @author Alberto Tarrasa
  * 
  * @param object a pointer to the object
  * @return  a string with the name of the object
  */
const char* object_get_name(Object* object);

/**
  * @brief It prints the object information
  * @author Alberto Tarrasa
  *
  * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
  * @param object a pointer to the object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_print(Object* object);

#endif 