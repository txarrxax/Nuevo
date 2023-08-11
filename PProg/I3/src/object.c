/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author Álvaro Grande
 * @version 2.0
 * @date 15/2/2023
 * @copyright GNU Public License
 */

#include <object.h>
#include <game.h>
#include <types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Object
 *
 * This struct stores all the information of an object.
 */
struct _Object {
  Id id;                       /*!< Unique id of the object */
  char name[WORD_SIZE];        /*!< Name of the object */
  char description[WORD_SIZE]; /*!< Description of the object*/
};

/* It gets the id of the object
 */
Id object_get_id(const Object *object) {
  if (!object)
    return NO_ID;

  return object->id;
}

/** object_set_id sets the id of an object
 */
STATUS object_set_id(Object *object, const Id id) {

  if (id == NO_ID || !object)
    return ERROR;

  object->id = id;

  return OK;
}

/*It gets the name of an object
 */
const char *object_get_name(const Object *object) {
  if (!object)
    return NULL;

  return object->name;
}

/* It sets the name of the object
 */
STATUS object_set_name(Object *object, const char *name) {
  if (!object || !name)
    return ERROR;

  if (!strcpy(object->name, name))
    return ERROR;

  return OK;
}

/* It gets the description of an object
 */
const char *object_get_desc(const Object *object) {
  if (!object)
    return NULL;

  return object->description;
}

/* It sets the description of an object
 */
STATUS object_set_desc(Object *object, const char *desc) {
  if (!object || !desc)
    return ERROR;

  if (!strcpy(object->description, desc))
    return ERROR;

  return OK;
}

/** Allocates memory for a new object and initializes its members
 */
Object *object_create() {
  Object *new_object;

  if (!(new_object = malloc(sizeof(Object))))
    return NULL;

  /* Initialization of an empty object*/
  new_object->id = NO_ID;
  new_object->name[0] = '\0';
  new_object->description[0] = '\0';

  return new_object;
}

/** Frees the previous memory allocation for an object
 */
void object_destroy(Object *object) {
  if (!object)
    return;

  free(object);
}

/* It prints the object information
 */
STATUS object_print(const Object *object) {
  /* Error Control */
  if (!object)
    return ERROR;

  /* Prints the id and the name of the object */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s; Description: %s)\n", object->id, object->name, object->description);

  return OK;
}
