/**
 * @brief It implements the enemy module
 *
 * @file enemy.c
 * @author Álvaro Grande
 * @version 1.0
 * @date 14-2-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <enemy.h>

/**
 * @brief Enemy
 *
 * This struct stores all the information for the enemy
 */
struct _Enemy {
  Id   enemy_id;        /*!< Id of the enemy */
  Id   location;        /*!< Location of the enemy */
  char name[WORD_SIZE]; /*!< Name of the enemy */
  int  health;          /*!< Health of the enemy */
  int  strength;        /*!< Enemy strength in battle */
};

/** enemy_create creates a new enemy
 */
Enemy *enemy_create() {
  Enemy *e;

  /*Error control*/
  if (!(e = (Enemy *)malloc(sizeof(Enemy)))) return NULL;

  /*Default ids are NO_ID, the default name is blank and the default health is 0*/
  e->enemy_id  = NO_ID;
  e->location  = NO_ID;
  (e->name)[0] = '\0';
  e->health    = 0;
  e->strength  = 0;

  return e;
}

/** enemy_destroy destroys a given enemy
 */
STATUS enemy_destroy(Enemy *e) {
  /*Error control*/
  if (!e) return ERROR;

  free(e);
  return OK;
}

/** enemy_get_id finds the id of an enemy
 */
Id enemy_get_id(const Enemy *e) {
  /*Error control*/
  if (!e) return NO_ID;

  return e->enemy_id;
}

/** enemy_set_id sets the id of an enemy
 */
STATUS enemy_set_id(Enemy *e, const Id new_id) {
  /*Error control*/
  if (!e || new_id == NO_ID) return ERROR;

  e->enemy_id = new_id;

  return OK;
}

/** enemy_get_location finds the location of an enemy
 */
Id enemy_get_location(const Enemy *e) {
  /*Error control*/
  if (!e) return NO_ID;

  return e->location;
}

/** enemy_set_location sets the location of an enemy
 */
STATUS enemy_set_location(Enemy *e, const Id new_location) {
  /*Error control*/
  if (!e || new_location == NO_ID) return ERROR;

  e->location = new_location;

  return OK;
}

/** enemy_get_name finds the name of an enemy
 */
const char *enemy_get_name(const Enemy *e) {
  /*Error control*/
  if (!e) return NULL;

  return e->name;
}

/** enemy_set_name sets the name of an enemy
 */
STATUS enemy_set_name(Enemy *e, const char *new_name) {
  /*Error control*/
  if (!e || new_name == NULL) return ERROR;

  if (!strcpy(e->name, new_name)) return ERROR;

  return OK;
}

/** enemy_get_health finds the health of an enemy
 */
int enemy_get_health(const Enemy *e) {
  /*Error control*/
  if (!e) return -1;

  return e->health;
}

/** enemy_set_health sets the health of an enemy
 */
STATUS enemy_set_health(Enemy *e, const int new_health) {
  /*Error control*/
  if (!e) return ERROR;

  e->health = new_health;

  return OK;
}

/** enemy_print prints the information of an enemy
 */
STATUS enemy_print(const Enemy *e) {
  /*Error control*/
  if (!e) return ERROR;

  fprintf(stdout, "Id: %ld; Location: %ld; Name: %s; Health: %d\n", e->enemy_id, e->location, e->name, e->health);

  return OK;
}

/** enemy_get_strength gets the strength stat of an enemy
 */
int enemy_get_strength(const Enemy *e) {
  if (!e) return 0;

  return e->strength;
}

/** enemy_set_strength sets the strength of an enemy
 */
STATUS enemy_set_strength(Enemy *e, const int strength) {
  if (!e) return ERROR;

  e->strength = strength;

  return OK;
}
