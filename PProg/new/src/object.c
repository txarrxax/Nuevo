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
  Id   id;                     /*!< Unique id of the object */
  char name[WORD_SIZE];        /*!< Name of the object */
  char description[WORD_SIZE]; /*!< Description of the object*/

  /*New properties*/

  BOOL hidden;     /*!< Tells if the object is visible or not*/
  BOOL movable;    /*!< Tells if the object is movable or not*/
  Id   dependency; /*!< Tells the id of the object which this depends of*/
  Id   open;       /*!< Tells if the object opens a link*/
  BOOL illuminate; /*!< Tells if the object can illuminate a room*/
  BOOL turnedon;   /*!< Tells if the object is turned on or not*/
  int  stats;      /*!< Defines the ATK(+)/DEF(-) stats for the object */
};

/* It gets the id of the object
 */
Id object_get_id(const Object *object) {
  if (!object) return NO_ID;

  return object->id;
}

/** object_set_id sets the id of an object
 */
STATUS object_set_id(Object *object, const Id id) {
  if (id == NO_ID || !object) return ERROR;

  object->id = id;

  return OK;
}

/*It gets the name of an object
 */
const char *object_get_name(const Object *object) {
  if (!object) return NULL;

  return object->name;
}

/* It sets the name of the object
 */
STATUS object_set_name(Object *object, const char *name) {
  if (!object || !name) return ERROR;

  if (!strcpy(object->name, name)) return ERROR;

  return OK;
}

/* It gets the description of an object
 */
const char *object_get_desc(const Object *object) {
  if (!object) return NULL;

  return object->description;
}

/* It sets the description of an object
 */
STATUS object_set_desc(Object *object, const char *desc) {
  if (!object || !desc) return ERROR;

  if (!strcpy(object->description, desc)) return ERROR;

  return OK;
}

/** Allocates memory for a new object and initializes its members
 */
Object *object_create() {
  Object *new_object;

  if (!(new_object = malloc(sizeof(Object)))) return NULL;

  /* Initialization of an empty object*/
  new_object->id             = NO_ID;
  new_object->name[0]        = '\0';
  new_object->description[0] = '\0';

  /*New properties*/

  new_object->hidden     = TRUE;
  new_object->movable    = FALSE;
  new_object->dependency = NO_ID;
  new_object->open       = NO_ID;
  new_object->illuminate = FALSE;
  new_object->turnedon   = FALSE;

  new_object->stats = 0;

  return new_object;
}

/** Frees the previous memory allocation for an object
 */
STATUS object_destroy(Object *object) {
  if (!object) return ERROR;

  free(object);
  return OK;
}

/* It prints the object information
 */
STATUS object_print(const Object *object) {
  /* Error Control */
  if (!object) return ERROR;

  /* Prints the id and the name of the object */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s; Description: %s)\n", object->id, object->name, object->description);

  return OK;
}

BOOL object_get_hidden(const Object *object) {
  if (!object) return TRUE;

  return object->hidden;
}

STATUS object_set_hidden(Object *object, BOOL hidden) {
  if (!object) return ERROR;

  object->hidden = hidden;
  return OK;
}

BOOL object_get_movable(const Object *object) {
  if (!object) return FALSE;

  return object->movable;
}

STATUS object_set_movable(Object *object, BOOL movable) {
  if (!object) return ERROR;

  object->movable = movable;
  return OK;
}

Id object_get_dependency(const Object *object) {
  if (!object) return NO_ID;

  return object->dependency;
}

STATUS object_set_dependency(Object *object, Id dependency) {
  if (!object) return ERROR;

  object->dependency = dependency;
  return OK;
}

Id object_get_open(const Object *object) {
  if (!object) return NO_ID;

  return object->open;
}

STATUS object_set_open(Object *object, Id open) {
  if (!object) return ERROR;

  object->open = open;
  return OK;
}

BOOL object_get_illuminate(const Object *object) {
  if (!object) return FALSE;

  return object->illuminate;
}

STATUS object_set_illuminate(Object *object, BOOL illuminate) {
  if (!object) return ERROR;

  object->illuminate = illuminate;
  return OK;
}

BOOL object_get_turnedon(const Object *object) {
  if (!object) return FALSE;

  return object->turnedon;
}

STATUS object_set_turnedon(Object *object, BOOL turnedon) {
  if (!object) return ERROR;

  object->turnedon = turnedon;
  return OK;
}

/** object_get_stats gets the ATK/DEF stats of an object
 */
int object_get_stats(const Object *obj) {
  if (!obj) return 0;

  return obj->stats;
}

/** object_set_stats sets the ATK/DEF stat of an object
 */
STATUS object_set_stats(Object *obj, const int stats) {
  if (!obj) return ERROR;

  obj->stats = stats;

  return OK;
}
