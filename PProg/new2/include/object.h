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
Id object_get_id(const Object *object);

/**
 * @brief It gets the name of the object
 * @author Álvaro Grande
 *
 * @param object the pointer to the object struct
 * @return the name of the object
 */
const char *object_get_name(const Object *object);

/**
 * @brief It sets a new name for an object
 * @author Álvaro Grande
 *
 * @param object the pointer to the object struct
 * @param name the new name for the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_name(Object *object, const char *name);

/**
 * @brief It gets the description of the object
 * @author Miguel Angel Sacristan
 *
 * @param object the pointer to the object struct
 * @return the description of the object or NULL if there was some mistake
 */
const char *object_get_desc(const Object *object);

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
Object *object_create();

/**
 * @brief It erases an object
 * @author Álvaro Grande
 *
 * @param object the pointer to the object struct that will be erased
 * @return Ok if everything goes well, ERROR if not
 */
STATUS object_destroy(Object *object);

/**
 * @brief It prints the object information
 * @author Álvaro Grande
 *
 * @param object the pointer to the object struct whose information will be printed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_print(const Object *object);

/**
 * @brief It sets the id of the object
 * @author Álvaro Grande
 *
 * @param object target object
 * @param id new id
 * @return OK if successful, ERROR if there was an issue
 */
STATUS object_set_id(Object *object, const Id id);

/**
 * @brief It gets object_hidden value
 * @author Álvaro Grande
 *
 * @param object target object
 * @return object_hidden
 */
BOOL object_get_hidden(const Object *object);

/**
 * @brief It sets object_hidden value
 * @author Álvaro Grande
 *
 * @param object target object
 * @param hidden new value
 * @return OK if successful, ERROR if there was an issue
 */
STATUS object_set_hidden(Object *object, BOOL hidden);

/**
 * @brief It gets object_movable value
 * @author Álvaro Grande
 *
 * @param object target object
 * @return object_movable
 */
BOOL object_get_movable(const Object *object);

/**
 * @brief It sets object_movable value
 * @author Álvaro Grande
 *
 * @param object target object
 * @param movable new value
 * @return OK if successful, ERROR if there was an issue
 */
STATUS object_set_movable(Object *object, BOOL movable);

/**
 * @brief It gets object_dependency value
 * @author Álvaro Grande
 *
 * @param object target object
 * @return object_dependency
 */
Id object_get_dependency(const Object *object);

/**
 * @brief It sets object_dependency value
 * @author Álvaro Grande
 *
 * @param object target object
 * @param dependency new value
 * @return OK if successful, ERROR if there was an issue
 */
STATUS object_set_dependency(Object *object, Id dependency);

/**
 * @brief It gets object_open value
 * @author Álvaro Grande
 *
 * @param object target object
 * @return object_open
 */
Id object_get_open(const Object *object);

/**
 * @brief It sets object_open value
 * @author Álvaro Grande
 *
 * @param object target object
 * @param open new value
 * @return OK if successful, ERROR if there was an issue
 */
STATUS object_set_open(Object *object, Id open);

/**
 * @brief It gets object_illuminate value
 * @author Álvaro Grande
 *
 * @param object target object
 * @return object_illuminate
 */
BOOL object_get_illuminate(const Object *object);

/**
 * @brief It sets object_illuminate value
 * @author Álvaro Grande
 *
 * @param object target object
 * @param illuminate new value
 * @return OK if successful, ERROR if there was an issue
 */
STATUS object_set_illuminate(Object *object, BOOL illuminate);

/**
 * @brief It gets object_turnedon value
 * @author Álvaro Grande
 *
 * @param object target object
 * @return object_turnedon
 */
BOOL object_get_turnedon(const Object *object);

/**
 * @brief It sets object_turnedon value
 * @author Álvaro Grande
 *
 * @param object target object
 * @param turnedon new value
 * @return OK if successful, ERROR if there was an issue
 */
STATUS object_set_turnedon(Object *object, BOOL turnedon);

/**
 * @brief It gets the ATK/DEF stats of the object
 * @author Diego Fernández
 *
 * @param obj target object
 * @return the stat value of the target, 0 if there was an issue
 */
int object_get_stats(const Object *obj);

/**
 * @brief It sets the ATK/DEF stat of an object
 * @author Diego Fernández
 *
 * @param obj target object
 * @param stats new stats parameter
 * @return OK if successful, ERROR if there was an issue
 */
STATUS object_set_stats(Object *obj, const int stats);

#endif
