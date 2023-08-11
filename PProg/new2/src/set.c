/**
 * @brief It implements the set module
 *
 * @file set.c
 * @author Diego Fernández
 * @version 2.0
 * @date 10/3/2023
 * @copyright GNU Public License
 */

#include <set.h>
#include <stdlib.h>

/**
 * @brief Max set size
 */
#define SET_SIZE 128

/**
 * @brief default initial set size
 */
#define INIT_SIZE 5

/**
 * @brief growth factor applied to the set each time it is expanded
 */
#define GROWTH_FACTOR 2

/**
 * @brief Set
 * A struct that contains a set of ids
 */
struct _Set {
  Id *ids;      /*!< Array of ids contained within the set */
  int n_ids;    /*!< Total number of ids stored in the set */
  int capacity; /*!< Current capacity of the set*/
};

/*Private prototypes*/
/**
 * @brief It checks whether a set is full or not
 * @author Diego Fernández
 *
 * @param set target set
 * @return TRUE if the set is empty or there was an issue, FALSE otherwise
 */
BOOL set_is_full(const Set *set);

/**
 * @brief Increases the capacity of a set. If it fails it leaves it intact
 * @author Diego Fernández
 *
 * @param set target set
 * @return OK if successful, ERROR if there was an issue
 */
STATUS set_grow(Set *set);

/*Public functions*/
/** set_create creates a new set
 */
Set *set_create() {
  Set *res;
  int  i;

  /*We allocate memory for the set*/
  if (!(res = malloc(sizeof(Set)))) return NULL;

  /*The set is empty and has an initial size by default*/
  res->n_ids    = 0;
  res->capacity = INIT_SIZE;

  /*We allocate memory for the ids*/
  if (!(res->ids = malloc(INIT_SIZE * sizeof(Id)))) {
    free(res);
    return NULL;
  }

  /*Empty slots are assigned the NO_ID value*/
  for (i = 0; i < INIT_SIZE; i++) {
    (res->ids)[i] = NO_ID;
  }

  return res;
}

/** set_destroy frees the target set
 */
STATUS set_destroy(Set *set) {
  if (set != NULL) {
    if (set->ids != NULL)
      free(set->ids);
    else
      return ERROR;
    free(set);
  } else
    return ERROR;

  return OK;
}

/** set_is_empty checks whether a set is empty or not
 */
BOOL set_is_empty(const Set *set) {
  /*Error control*/
  if (!set) return TRUE;

  return set->n_ids == 0;
}

/** set_add adds a new id to the set
 */
STATUS set_add(Set *set, const Id id) {
  /*Error control*/
  if (!set || set->n_ids < 0 || id == NO_ID || !(set->ids)) return ERROR;

  /*If the set is full we attempt to increase it*/
  if (set_is_full(set)) {
    if (set_grow(set) == ERROR) return ERROR;
  }

  /*The new id is added to the end of the set*/
  (set->ids)[(set->n_ids)++] = id;

  return OK;
}

/** set_del removes an id from the set
 */
STATUS set_del(Set *set, const Id id) {
  int i;

  /*Error control*/
  if (!set || set->n_ids < 0 || id == NO_ID) return ERROR;

  if (set_is_empty(set)) return ERROR;

  /*We loop through the set until we find a matching id*/
  for (i = 0; i < set->n_ids; i++) {
    if ((set->ids)[i] == id) {
      /*Matching id is deleted and swapped with the end of the set*/
      if (i != --(set->n_ids)) (set->ids)[i] = (set->ids)[set->n_ids];
      (set->ids)[set->n_ids] = NO_ID;
      return OK;
    }
  }

  /*If no matching id was found ERROR is returned*/
  return ERROR;
}

/** set_print prints the information of a set
 */
STATUS set_print(const Set *set) {
  int i;

  /*Error control*/
  if (!set) return ERROR;

  printf("Capacity: %d\n", set->capacity);
  printf("Size: %d\n", set->n_ids);
  for (i = 0; i < set->n_ids; i++) {
    printf("%d: %ld\n", i, (set->ids)[i]);
  }

  return OK;
}

/** set_get_size gets the size of a given set
 */
int set_get_size(const Set *set) {
  if (!set) return -1;

  return set->n_ids;
}

/** set_get_ids gets the array of ids from a set
 */
const Id *set_get_ids(const Set *set) {
  if (!set) return NULL;

  return set->ids;
}

/** set_has_id checks if an id is contained in a set
 */
BOOL set_has_id(const Set *set, const Id id) {
  int i;

  if (!set || id == NO_ID) return FALSE;

  for (i = 0; i < set->n_ids; i++) {
    if (id == (set->ids)[i]) return TRUE;
  }

  return FALSE;
}

/*Private functions*/
/** set_is_full checks whether a set is full or not
 */
BOOL set_is_full(const Set *set) {
  /*Error control*/
  if (!set) return TRUE;

  return set->capacity == set->n_ids;
}

/** set_grow increases the capacity of a set
 */
STATUS set_grow(Set *set) {
  int new_capacity;
  Id *backup;

  /*Error control*/
  if (!set || set->capacity <= 0) return ERROR;

  /*There is a hard cap for the capacity*/
  if ((new_capacity = set->capacity * GROWTH_FACTOR) > SET_SIZE) return ERROR;

  /*Error control*/
  if (!(backup = realloc(set->ids, new_capacity * sizeof(Id)))) return ERROR;

  set->ids      = backup;
  set->capacity = new_capacity;

  return OK;
}
