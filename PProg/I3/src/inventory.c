/**
 * @brief It implements the inventory module
 *
 * @file inventory.c
 * @author Álvaro Grande
 * @author Diego Fernández
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <inventory.h>

/**
 * @brief Max inventory size
 */
#define DEF_SIZE 3

/**
 * @brief Inventory
 * A struct that defines the inventory
 */
struct _Inventory {
  Set *objs;    /*!< Pointer to a set of objects */
  int max_objs; /*!< Max number of objects*/
};

/*Private prototypes*/
/**
 * @brief It checks if the inventory is full
 * @author Álvaro Grande
 *
 * @param i Target inventory
 * @return TRUE if full, FALSE if not
 */
BOOL inventory_is_full(Inventory *i);

/** inventory_create creates the inventory of the player
 */
Inventory *inventory_create() {
  Inventory *new_i;

  if (!(new_i = malloc(sizeof(Inventory))))
    return NULL;

  new_i->objs = set_create();
  if (new_i->objs == NULL) {
    free(new_i);
    return NULL;
  }

  new_i->max_objs = DEF_SIZE;

  return new_i;
}

/** inventory_destroy frees the inventory
 */
STATUS inventory_destroy(Inventory *i) {
  if (!i)
    return ERROR;
  else {
    set_destroy(i->objs);
    free(i);
    return OK;
  }
}

/** inventory_set_max_objs sets the max number of objects the inventory will
 * have
 */
STATUS inventory_set_max_objs(Inventory *i, const int new_max) {
  if (!i || new_max <= 0)
    return ERROR;

  i->max_objs = new_max;

  return OK;
}

/** inventory_get_max_objs gets the max number of objects the inventory can have
 */
int inventory_get_max_objs(const Inventory *i) {
  if (!i)
    return -1;

  return i->max_objs;
}

/** inventory_add_object adds a new object to the inventory
 */
STATUS inventory_add_object(Inventory *i, const Id obj_id) {
  if (inventory_is_full(i))
    return ERROR;

  return set_add(i->objs, obj_id);
}

/** inventory_del_object deletes an object from the inventory
 */
STATUS inventory_del_object(Inventory *i, const Id obj_id) {
  if (!i)
    return ERROR;

  return set_del(i->objs, obj_id);
}

/** inventory_print prints the information of the inventory
 */
STATUS inventory_print(Inventory *i) {
  if (!i)
    return ERROR;

  fprintf(stdout, "--> Inventory max_objs: %d\n", i->max_objs);
  fprintf(stdout, "--> Inventory objs: \n");
  set_print(i->objs);

  return OK;
}

/** inventory_isEmpty checks if the inventory is empty
 */
BOOL inventory_is_empty(Inventory *i) {
  if (!i)
    return FALSE;

  return (set_is_empty(i->objs));
}



/** inventory_hasObject checks if an object is in the inventory
 */
BOOL inventory_has_object(Inventory *i, const Id obj_id) {
  if (!i)
    return FALSE;

  return set_has_id(i->objs, obj_id);
}

/** inventory_get_objs gets the pointer to the Set struct of inventory
 */
const Set *inventory_get_objs(const Inventory *i) {
  if (!i)
    return NULL;

  return i->objs;
}

/** inventory_set_cap sets the maximun capacity of an inventory
 */
STATUS inventory_set_cap(Inventory *inv, const int cap){ 
  if (!inv || cap < 0)
    return ERROR;

  inv->max_objs = cap;

  return OK;
}

/*Private function definition*/
/** inventory_is_full checks if the inventory is full
 */
BOOL inventory_is_full(Inventory *i) {
  if (!i)
    return TRUE;

  return (set_get_size(i->objs) == i->max_objs);
}
