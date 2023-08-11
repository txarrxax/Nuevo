/**
 * @brief It implements the player module
 *
 * @file player.c
 * @author Diego Fernández
 * @author Álvaro Grande
 * @version 1.0
 * @date 14-2-2023
 * @copyright GNU Public License
 */

#include <player.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Player
 *
 * This struct stores all the information for the player
 */
struct _Player {
  Id         player_id;       /*!< Identifier for the player */
  Id         location;        /*!< Id of the room where the player is */
  char       name[WORD_SIZE]; /*!< Name of the player */
  Inventory *inventory;       /*!< Pointer of the inventory of the player*/
  int        health;          /*!< Player health */
  int        atk;             /*!< Attack stat */
  int        def;             /*!< Defense stat */
};

/** player_create creates a new player
 */
Player *player_create() {
  Player *p;

  /*Error control*/
  if (!(p = (Player *)malloc(sizeof(Player)))) return NULL;

  /*Default ids are NO_ID, the default name is blank and no item is carried by
   * default*/
  p->player_id = NO_ID;
  p->location  = NO_ID;
  (p->name)[0] = '\0';
  if ((p->inventory = inventory_create()) == NULL) return NULL;
  p->health = 0;
  p->atk    = 0;
  p->def    = 0;

  return p;
}

/** player_destroy destroys a given player
 */
STATUS player_destroy(Player *p) {
  /*Error control*/
  if (!p) return ERROR;

  inventory_destroy(p->inventory);
  free(p);

  return OK;
}

/** player_get_id finds the id of a player
 */
Id player_get_id(const Player *p) {
  /*Error control*/
  if (!p) return NO_ID;

  return p->player_id;
}

/** player_set_id Sets the id of a player
 */
STATUS player_set_id(Player *p, const Id new_id) {
  /*Error control*/
  if (!p || new_id == NO_ID) return ERROR;

  p->player_id = new_id;

  return OK;
}

/** player_get_inventory gets the inventory of the player
 */
const Inventory *player_get_inventory(const Player *p) {
  /*Error control*/
  if (!p) return NULL;

  return p->inventory;
}

/** player_add_item adds a new item to the player's inventory
 */
STATUS player_add_item(Player *p, const Id item_id) {
  /*Error control*/
  if (!p) return ERROR;

  if (inventory_add_object(p->inventory, item_id) == ERROR) return ERROR;

  return OK;
}

/** player_del_item deletes an item from the player's inventory
 */
STATUS player_del_item(Player *p, const Id item_id) {
  if (!p) return ERROR;

  if (inventory_del_object(p->inventory, item_id) == ERROR) return ERROR;

  return OK;
}

/** player_get_location finds the location of a player
 */
Id player_get_location(const Player *p) {
  /*Error control*/
  if (!p) return NO_ID;

  return p->location;
}

/** player_set_location sets the location of a player
 */
STATUS player_set_location(Player *p, const Id new_loc) {
  /*Error control*/
  if (!p || new_loc == NO_ID) return ERROR;

  p->location = new_loc;

  return OK;
}

/** player_get_name Finds the name of a player
 */
const char *player_get_name(const Player *p) {
  /*Error control*/
  if (!p) return NULL;

  return p->name;
}

/** player_set_name sets the name of a player
 */
STATUS player_set_name(Player *p, const char *new_name) {
  /*Error control*/
  if (!p || !new_name) return ERROR;

  if (!strcpy(p->name, new_name)) return ERROR;

  return OK;
}

/** player_get_health gets the health of a player
 */
int player_get_health(const Player *p) {
  if (!p) return -1;

  return p->health;
}

/** player_set_health sets the health of a player
 */
STATUS player_set_health(Player *p, const int new_health) {
  if (!p) return ERROR;

  p->health = new_health;

  return OK;
}

/** player_print prints the information of a player
 */
STATUS player_print(const Player *p) {
  /*Error control*/
  if (!p) return ERROR;

  fprintf(stdout, "Id: %ld; Location: %ld; Name: %s; Health: %d\n", p->player_id, p->location, p->name, p->health);

  inventory_print(p->inventory);

  return OK;
}

/**
 * player_set_inv_cap sets the max cap of the player's inventory
 */
STATUS player_set_inv_cap(Player *p, const int cap) {
  if (!p) return ERROR;

  return inventory_set_cap(p->inventory, cap);
}

/** player_add_stat increments atk for positive stat and def for negative stat
 */
STATUS player_add_stat(Player *p, const int stat) {
  if (!p) return ERROR;

  if (stat >= 0)
    p->atk += stat;
  else
    p->def -= stat;

  return OK;
}

/** player_subs_stat decrements atk for positive stat and def for negative stat
 */
STATUS player_subs_stat(Player *p, const int stat) {
  if (!p) return ERROR;

  if (stat >= 0)
    p->atk -= stat;
  else
    p->def += stat;

  return OK;
}

/** player_get_atk gets the player's atk stat
 */
int player_get_atk(const Player *p) {
  if (!p) return 0;

  return p->atk;
}

/** player_get_def gets the player's def stat
 */
int player_get_def(const Player *p) {
  if (!p) return 0;

  return p->def;
}
