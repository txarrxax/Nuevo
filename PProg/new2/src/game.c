/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Diego Fernández
 * @author Álvaro Grande
 * @version 3.0
 * @date 7-02-2023
 * @copyright GNU Public License
 */

#include <dialogue.h>
#include <game.h>
#include <game_management.h>
#include <inventory.h>
#include <object.h>
#include <link.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <player.h>

/**
 * @brief Max number of character of an objects description
 */
#define OBJ_LEN 14

/**
 * @brief This struct contains a game session
 */

struct _Game {
  Player   *p;                        /*!< Pointer to player struct */
  Object   *objects[MAX_OBJ];         /*!< Array of all objects in the game */
  int       num_obj;                  /*!< Number of objects */
  Space    *spaces[MAX_SPACES];       /*!< Array in which the rooms are stored */
  Link     *links[MAX_LINKS];         /*!< Array with the links between spaces */
  int       num_link;                 /*!< Number of links */
  T_Command last_cmd;                 /*!< Last command read from the prompt */
  STATUS    last_cmd_exit;            /*!< Exit of the last command used */
  Enemy    *e;                        /*!< Pointer to enemy struct */
  char      last_des[WORD_SIZE];      /*!< Array with the last description asked */
  char      last_dialogue[WORD_SIZE]; /*!< Array with the dialogue from the last command */
};

/**
   Private functions
*/

/**
 * @brief It executes the instructions for the UNKNOWN command
 * @author Profesores PPROG
 *
 * @param game a pointer to the game session
 */
void game_command_unknown(Game *game);

/**
 * @brief It executes the instructions for the EXIT command
 * @author Profesores PPROG
 *
 * @param game a pointer to the game session
 */
void game_command_exit(Game *game);

/**
 * @brief It moves the player to the space located in the NORTH direction of the current space
 * @author Profesores PPROG
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_north(Game *game);

/**
 * @brief It moves the player to the space located in the SOUTH direction of the current space
 * @author Profesores PPROG
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_south(Game *game);

/**
 * @brief It moves the player to the space located in the EAST direction of the current space
 * @author Álvaro Grande
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_east(Game *game);

/**
 * @brief It moves the player to the space located in the WEST direction of the current space
 * @author Álvaro Grande
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_west(Game *game);

/**
 * @brief It moves the player to the space located in the UP direction of the current space
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_up(Game *game);

/**
 * @brief It moves the player to the space located in the DOWN direction of the current space
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_down(Game *game);

/**
 * @brief It executes the instructions for the TAKE command
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param arg parameter specifying the id of the target object
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_take(Game *game, const char *arg);

/**
 * @brief It executes the instructions for the DROP command
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param arg parameter specifying the id of the target object
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_drop(Game *game, const char *arg);

/**
 * @brief It executes the instructions for the MOVE command
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param arg parameter specifying the direction
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_command_move(Game *game, const char *arg);

/**
 * @brief It executes the instructions for the ATTACK command
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_attack(Game *game);

/**
 * @brief It executes the instructions for the INSPECT command
 * @author Miguel Angel Sacristan
 *
 * @param game a pointer to the game session
 * @param arg parameter specifying the name of the target object
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_inspect(Game *game, const char *arg);

/**

 * @brief It executes the instructions for the SWITCH command
 * @author Alberto Tarrasa
 *
 * @param game a pointer to the game session
 * @param arg parameter specifying the name of the target object
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_switch(Game *game, const char *arg);

/**
 * @brief Opens a link with an object
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param arg parameter that follows the format 'lnk with obj'
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_command_open(Game *game, char *arg);

/**
 * @brief Saves the game
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param arg parameter that contains the save file's directory
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_command_save(Game *game, char *arg);

/**
 * @brief Loads the game from a file
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param arg parameter that contains the target file's directory
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_command_load(Game **game, char *arg);

/**
   Public Functions
*/

/** game_create_from_file creates a new game session from a file
 */
STATUS game_create_from_file(Game **game, const char *filename) {
  if (game_create(game) == ERROR || !filename) return ERROR;

  if (game_management_load_spaces(*game, filename) == ERROR) return ERROR;

  if (game_management_load_player(*game, filename) == ERROR) return ERROR;

  if (game_management_load_objects(*game, filename) == ERROR) return ERROR;

  if (game_management_load_enemies(*game, filename) == ERROR) return ERROR;

  if (game_management_load_links(*game, filename) == ERROR) return ERROR;

  if (game_set_last_description(*game, "\0") == ERROR) return ERROR;

  if (game_set_last_dialogue(*game, " >> ") == ERROR) return ERROR;

  return OK;
}

/** game_destroy deletes a game session
 */
STATUS game_destroy(Game *game) {
  int i;

  /*Error control*/
  if (!game) return ERROR;

  /*Spaces (rooms) are deleted one by one*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_destroy(game->spaces[i]);
  }

  /*Objects are deleted one by one*/
  for (i = 0; i < game->num_obj; i++) {
    object_destroy((game->objects)[i]);
  }

  /*Links are deleted one by one*/
  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++) link_destroy(game->links[i]);

  /*Player is deleted*/
  player_destroy(game->p);

  /*Enemy is deleted*/
  enemy_destroy(game->e);

  free(game);

  return OK;
}

/** game_add_space adds a space to the game session
 */
STATUS game_add_space(Game *game, Space *space) {
  int i = 0;

  if (!space || !game) return ERROR;

  while (i < MAX_SPACES && game->spaces[i] != NULL) {
    i++;
  }

  if (i >= MAX_SPACES) return ERROR;

  game->spaces[i] = space;

  return OK;
}

/** game_get_space finds a space with the given id
 */
Space *game_get_space(const Game *game, const Id id) {
  int i;

  /*Error control*/
  if (id == NO_ID || !game) return NULL;

  /*We loop through all spaces until we find one with the desired id
   * or until there are no more spaces*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    /*We return a pointer to the space with the matching id*/
    if (id == space_get_id(game->spaces[i])) return game->spaces[i];
  }

  /*If no space was found, NULL is returned*/
  return NULL;
}

/** game_update updates the state of the game given a command
 */
STATUS game_update(Game **game, const T_Command cmd, char *arg) {
  STATUS aux;

  /*Error control*/
  if (!game || !arg) return ERROR;

  /*The last command is updated*/
  (*game)->last_cmd = cmd;

  /*We execute the instructions given by the command*/
  switch (cmd) {
    case UNKNOWN:
      game_command_unknown(*game);
      (*game)->last_cmd_exit = ERROR;
      break;

    case EXIT:
      game_command_exit(*game);
      (*game)->last_cmd_exit = OK;
      break;

    case TAKE:
      (*game)->last_cmd_exit = game_command_take(*game, arg);
      break;

    case DROP:
      (*game)->last_cmd_exit = game_command_drop(*game, arg);
      break;

    case ATTACK:
      (*game)->last_cmd_exit = game_command_attack(*game);
      break;

    case INSPECT:
      (*game)->last_cmd_exit = game_command_inspect(*game, arg);
      break;

    case MOVE:
      (*game)->last_cmd_exit = game_command_move(*game, arg);
      break;

    case OPEN:
      (*game)->last_cmd_exit = game_command_open(*game, arg);
      break;

    case SWITCH:
      (*game)->last_cmd_exit = game_command_switch(*game, arg);
      break;

    case SAVE:
      (*game)->last_cmd_exit = game_command_save(*game, arg);
      break;

    case LOAD:
      aux                    = game_command_load(game, arg);
      (*game)->last_cmd_exit = aux;
      break;

    default:
      break;
  }

  return (*game)->last_cmd_exit;
}

/** game_is_over checks if gameover conditions have been reached
 */
BOOL game_is_over(const Game *game) {
  if (!game || player_get_health(game->p) <= 0 || enemy_get_health(game->e) <= 0) return TRUE;

  return FALSE;
}

/** game_get_last_command gets the last command used
 */
T_Command game_get_last_command(const Game *game) {
  /*Error control*/
  if (!game) return NO_CMD;

  return game->last_cmd;
}

/** game_print_data prints data of the current game state to the console
 */
STATUS game_print_data(const Game *game) {
  int i;

  /*Error control*/
  if (!game) return ERROR;

  printf("\n\n-------------\n\n");

  /*The data of each space is printed*/
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  /*The locations of the player and the object are printed*/
  printf("=> Player location: %d\n", (int)player_get_location(game->p));

  /*Object info is printed*/
  for (i = 0; i < game->num_obj; i++) {
    object_print((game->objects)[i]);
  }

  /*Last description is printed*/
  printf("=> Last Description: %s", game_get_last_description((Game *)game));

  return OK;
}

/** game_get_object_location gets the location of the object
 */
Id game_get_object_location(const Game *game, const Object *object) {
  int i;
  Id  id;

  if (!game) return NO_ID;

  if ((id = object_get_id(object)) == NO_ID) return NO_ID;

  for (i = 0; i < MAX_SPACES && (game->spaces)[i] != NULL; i++) {
    if (space_has_object((game->spaces)[i], id)) return space_get_id((game->spaces)[i]);
  }

  return NO_ID;
}

/** game_add_object adds a new object to the game
 */
STATUS game_add_object(Game *game, Object *object) {
  if (!game || !object) return ERROR;
  if (game->num_obj == MAX_OBJ) return ERROR;

  game->objects[(game->num_obj)++] = object;

  return OK;
}

/** game_get_player gets the player of the game
 */
Player *game_get_player(Game *game) {
  if (!game) return NULL;
  return game->p;
}

/** game_get_enemy gets the enemy of the game
 */
Enemy *game_get_enemy(Game *game) {
  if (!game) return NULL;
  return game->e;
}

/** game_get_number_of_objects gets the number of objects of the game
 */
int game_get_number_of_objects(const Game *game) {
  if (!game) return -1;
  return game->num_obj;
}

/** game_get_object_from_position gets an object of the game from its position
 */
Object *game_get_object_from_position(Game *game, int position) {
  if (!game || position < 0) return NULL;
  if (position > game->num_obj) return NULL;
  return game->objects[position];
}

/** game_get_last_command_exit gets the status of the last command
 */
STATUS game_get_last_command_exit(Game *game) {
  if (!game) return ERROR;
  return game->last_cmd_exit;
}

/** game_get_connection_status gets the status of a link in the game
 */
STATUS game_get_connection_status(Game *game, Id space, DIRECTION dir) {
  int i;
  /* error checks */
  if (!game || !space || dir == -1) return ERROR;

  for (i = 0; i < MAX_LINKS; i++) {
    if (link_get_origin(game->links[i]) == space) {
      if (link_get_direction(game->links[i]) == dir) {
        return link_get_status(game->links[i]);
      }
    }
  }
  return ERROR;
}

/** game_get_connection gets the destination id from a link in the game
 */
Id game_get_connection(Game *game, Id space, DIRECTION dir) {
  int i;
  /* error checks */
  if (!game || !space || dir == -1) return NO_ID;

  for (i = 0; i < MAX_LINKS; i++) {
    if (link_get_origin(game->links[i]) == space && link_get_direction(game->links[i]) == dir) {
      return link_get_dest(game->links[i]);
    }
  }
  return NO_ID;
}

/** game_add_space adds a space to the game session
 */
STATUS game_add_link(Game *game, Link *link) {
  int i = 0;

  if (!link || !game) return ERROR;

  while (i < MAX_LINKS && game->links[i] != NULL) {
    i++;
  }

  if (i >= MAX_LINKS) return ERROR;

  game->links[i] = link;

  (game->num_link)++;

  return OK;
}

/** game_set_last_description sets the last description of a game
 */

STATUS game_set_last_description(Game *game, char *des) {
  if (!game || !des || strlen(des) >= WORD_SIZE) return ERROR;

  strcpy(game->last_des, des);
  return OK;
}

/** game_get_last_description gets the last description of a game
 */

char *game_get_last_description(Game *game) {
  if (!game) return NULL;

  return game->last_des;
}

/** game_get_last_dialogue gets the last dialogue of a game
 */
char *game_get_last_dialogue(Game *game) {
  if (!game) return NULL;

  return game->last_dialogue;
}

/** game_set_last_dialogue sets the last dialogue of a game
 */
STATUS game_set_last_dialogue(Game *game, char *dialogue) {
  if (!game || !dialogue || strlen(dialogue) >= WORD_SIZE) return ERROR;
  strcpy(game->last_dialogue, dialogue);
  return OK;
}

/** game_get_object_from_id gets an object from its id
 */
Object *game_get_object_from_id(const Game *g, const Id id) {
  int i;

  if (!g || id == NO_ID) return NULL;

  for (i = 0; i < g->num_obj; i++) {
    if (object_get_id((g->objects)[i]) == id) return (g->objects)[i];
  }

  return NULL;
}

/** game_get_space_id_at gets the id of a space from its index
 */
Id game_get_space_id_at(const Game *game, const int position) {
  if (position < 0 || position >= MAX_SPACES || !game) return NO_ID;

  return space_get_id(game->spaces[position]);
}

/** game_create initializes a game session
 */
STATUS game_create(Game **game) {
  int i;

  if (!game) return ERROR;

  if (!(*game = malloc(sizeof(Game)))) return ERROR;

  /*All space pointers are NULL by default*/
  for (i = 0; i < MAX_SPACES; i++) {
    (*game)->spaces[i] = NULL;
  }

  /*All links pointers are NULL by default*/
  for (i = 0; i < MAX_LINKS; i++) {
    (*game)->links[i] = NULL;
  }

  /*Player is initialized*/
  if (!((*game)->p = player_create())) return ERROR;

  /*Enemy is initialized*/
  if (!((*game)->e = enemy_create())) {
    player_destroy((*game)->p);
    return ERROR;
  }

  /*Object list empty by default*/
  (*game)->num_obj = 0;

  /*Link list is also empty*/
  (*game)->num_link = 0;

  /*As the new game session is empty, there is no last_cmd*/
  (*game)->last_cmd = NO_CMD;

  (*game)->last_cmd_exit = OK;

  strcpy((*game)->last_des, "");
  strcpy((*game)->last_dialogue, "");

  return OK;
}

/** game_get_all_spaces gets the space array from the game struct
 */
const Space **game_get_all_spaces(const Game *game) {
  if (!game) return NULL;

  return (const Space **)game->spaces;
}

/** game_get_all_objects gets the object array from the game struct
 */
const Object **game_get_all_objects(const Game *game) {
  if (!game) return NULL;

  return (const Object **)game->objects;
}

/** game_get_num_links gets the number of links
 */
int game_get_num_links(const Game *game) {
  if (!game) return -1;

  return game->num_link;
}

/** game_get_all_links gets the link array from the game struct
 */
const Link **game_get_all_links(const Game *game) {
  if (!game) return NULL;

  return (const Link **)game->links;
}

/** game_no_enemy destroys the enemy struct and sets its pointer to NULL
 */
STATUS game_no_enemy(Game *game) {
  if (!game) return ERROR;

  if (game->e != NULL) {
    enemy_destroy(game->e);
    game->e = NULL;
  }

  return OK;
}

/* game_get_link_from_id gets a link from its id number*/
Link *game_get_link_from_id(Game *game, Id link) {
  int i;
  if (!game || link == NO_ID) return NULL;
  for (i = 0; i < MAX_LINKS; i++) {
    if (link == link_get_id(game->links[i])) return game->links[i];
  }
  return NULL;
}

/*  PRIVATE FUNCTIONS IMPLEMENTATION*/

/** game_command_unknown executes the instructions for the UNKNOWN command
 */
void game_command_unknown(Game *game) {
  dialogue_message(game, UNKNOWN_C, NULL, NULL);
}

/** game_command_exit executes the instructions for the EXIT command
 */
void game_command_exit(Game *game) {
  dialogue_message(game, EXIT_C, NULL, NULL);
}

/** game_command_north moves the player to the space located in the NORTH direction of the current space
 */
STATUS game_command_north(Game *game) {
  Id space_id = NO_ID;

  /*The player's location is found*/
  /*Error control*/
  if (!game || (space_id = player_get_location(game->p)) == NO_ID) return ERROR;

  /*If the connection exists, the location of the player changes*/
  if (game_get_connection_status(game, space_id, N) == OK) {
    player_set_location(game->p, game_get_connection(game, space_id, N));
    dialogue_message(game, MOVED, "NORTH", space_get_name(game_get_space(game, player_get_location(game->p))));
    return OK;
  }

  dialogue_message(game, NO_LINK, "NORTH", NULL);
  return ERROR;
}

/** game_command_south moves the player to the space located in the SOUTH direction of the current space
 */

STATUS game_command_south(Game *game) {
  Id space_id = NO_ID;

  /*The player's location is found*/
  /*Error control*/
  if (!game || (space_id = player_get_location(game->p)) == NO_ID) return ERROR;

  /*If the connection exists, the location of the player changes*/
  if (game_get_connection_status(game, space_id, S) == OK) {
    player_set_location(game->p, game_get_connection(game, space_id, S));
    dialogue_message(game, MOVED, "SOUTH", space_get_name(game_get_space(game, player_get_location(game->p))));
    return OK;
  }

  dialogue_message(game, NO_LINK, "SOUTH", NULL);
  return ERROR;
}

/** game_command_east moves the player to the space located in the EAST direction of the current space
 */

STATUS game_command_east(Game *game) {
  Id space_id = NO_ID;

  /*The player's location is found*/
  /*Error control*/
  if (!game || (space_id = player_get_location(game->p)) == NO_ID) return ERROR;

  /*If the connection exists, the location of the player changes*/

  if (game_get_connection_status(game, space_id, E) == OK) {
    player_set_location(game->p, game_get_connection(game, space_id, E));
    dialogue_message(game, MOVED, "EAST", space_get_name(game_get_space(game, player_get_location(game->p))));
    return OK;
  }

  dialogue_message(game, NO_LINK, "EAST", NULL);
  return ERROR;
}

/** game_command_west moves the player to the space located in the WEST direction of the current space
 */
STATUS game_command_west(Game *game) {
  Id space_id = NO_ID;

  /*The player's location is found*/
  /*Error control*/
  if (!game || (space_id = player_get_location(game->p)) == NO_ID) return ERROR;

  /*If the connection exists, the location of the player changes*/
  if (game_get_connection_status(game, space_id, W) == OK) {
    player_set_location(game->p, game_get_connection(game, space_id, W));
    dialogue_message(game, MOVED, "WEST", space_get_name(game_get_space(game, player_get_location(game->p))));
    return OK;
  }

  dialogue_message(game, NO_LINK, "WEST", NULL);
  return ERROR;
}

/** game_command_up moves the player to the space located in the UP direction of the current space
 */
STATUS game_command_up(Game *game) {
  Id space_id = NO_ID;

  /*The player's location is found*/
  /*Error control*/
  if (!game || (space_id = player_get_location(game->p)) == NO_ID) return ERROR;

  /*If the connection exists, the location of the player changes*/
  if (game_get_connection_status(game, space_id, U) == OK) {
    player_set_location(game->p, game_get_connection(game, space_id, U));
    dialogue_message(game, MOVED, "UP", space_get_name(game_get_space(game, player_get_location(game->p))));
    return OK;
  }

  dialogue_message(game, NO_LINK, "UP", NULL);
  return ERROR;
}

/** game_command_down moves the player to the space located in the DOWN direction of the current space
 */
STATUS game_command_down(Game *game) {
  Id space_id = NO_ID;

  /*The player's location is found*/
  /*Error control*/
  if (!game || (space_id = player_get_location(game->p)) == NO_ID) return ERROR;

  /*If the connection exists, the location of the player changes*/
  if (game_get_connection_status(game, space_id, D) == OK) {
    player_set_location(game->p, game_get_connection(game, space_id, D));
    dialogue_message(game, MOVED, "DOWN", space_get_name(game_get_space(game, player_get_location(game->p))));
    return OK;
  }

  dialogue_message(game, NO_LINK, "DOWN", NULL);
  return ERROR;
}

/** game_command_take executes instructions for the TAKE command
 */
STATUS game_command_take(Game *game, const char *arg) {
  Space  *current_room;
  Object *obj;
  Id      target;

  if (!game || !arg) return ERROR;

  if (strcmp(arg, "") == 0) {
    dialogue_message(game, NO_OBJ, "take", NULL);
    return ERROR;
  }

  if (!(current_room = game_get_space(game, player_get_location(game->p)))) return ERROR;

  obj = game_get_object_from_name(game, arg);

  target = object_get_id(obj);

  if (!(space_has_object(current_room, target)) || object_get_hidden(game_get_object_from_name(game, arg))) {
    dialogue_message(game, NOT_IN_ROOM, arg, NULL);
    return ERROR;
  }

  if (!inventory_has_object(player_get_inventory(game_get_player(game)), object_get_dependency(obj)) && object_get_dependency(obj) != NO_ID) {
    dialogue_message(game, DEPENDS_ON, arg, object_get_name(game_get_object_from_id(game, object_get_dependency(obj))));
    return ERROR;
  }

  if (!object_get_movable(game_get_object_from_name(game, arg))) {
    dialogue_message(game, NOT_MOVABLE, arg, NULL);
    return ERROR;
  }
  if (player_add_item(game->p, target) == ERROR) {
    dialogue_message(game, FULL_INVENTORY, arg, NULL);
    return ERROR;
  }

  player_add_stat(game->p, object_get_stats(obj));

  space_del_object(current_room, target);
  dialogue_message(game, TAKEN, arg, NULL);

  return OK;
}

/** game_command_drop executes the instructions for the DROP command
 */
STATUS game_command_drop(Game *game, const char *arg) {
  int     i = 0;
  Space  *current_room;
  Object *obj;
  Id      target;

  if (!game || !arg) return ERROR;

  if (strcmp(arg, "") == 0) {
    dialogue_message(game, NO_OBJ, "drop", NULL);
    return ERROR;
  }

  if (!(current_room = game_get_space(game, player_get_location(game->p)))) return ERROR;

  obj = game_get_object_from_name(game, arg);

  target = object_get_id(obj);

  if (player_del_item(game->p, target) == ERROR) {
    dialogue_message(game, NOT_IN_INVENTORY, arg, NULL);
    return ERROR;
  }

  if (space_add_object(current_room, target) == ERROR) {
    player_add_item(game->p, target);
    dialogue_message(game, FULL_SPACE, arg, NULL);
    return ERROR;
  }

  for (i = 0; i < game_get_number_of_objects(game); i++) {
    if (object_get_dependency(game_get_object_from_position(game, i)) == target && inventory_has_object(player_get_inventory(game->p), target)) {
      if (player_del_item(game->p, object_get_id(game_get_object_from_position(game, i))) == ERROR) return ERROR;

      if (space_add_object(current_room, object_get_id(game_get_object_from_position(game, i))) == ERROR) return ERROR;

      break;
    }
  }

  player_subs_stat(game->p, object_get_stats(obj));

  dialogue_message(game, DROPPED, arg, NULL);
  return OK;
}

/** game_command_switch executes the instructions for the SWITCH command
 */

STATUS game_command_switch(Game *game, const char *arg) {
  Object *obj = NULL;

  if (!game || !arg) return ERROR;

  if (strcmp(arg, "") == 0) {
    dialogue_message(game, NO_OBJ, "switch", NULL);
    return ERROR;
  }

  if (!(obj = game_get_object_from_name(game, arg))) {
    dialogue_message(game, NOT_IN_INVENTORY, arg, NULL);
    return ERROR;
  }

  if (!object_get_illuminate(obj)) {
    dialogue_message(game, CANT_ILLUMINATE, arg, NULL);
    return ERROR;
  }

  if ((!object_get_turnedon(obj)) == TRUE)
    dialogue_message(game, SWITCHED, arg, "ON");
  else
    dialogue_message(game, SWITCHED, arg, "OFF");

  return object_set_turnedon(obj, !object_get_turnedon(obj));
}

/** game_command_move executes the instructions for the MOVE command
 */
STATUS game_command_move(Game *game, const char *arg) {
  if (!game || !arg) return ERROR;

  if (strcmp(arg, "") == 0) {
    dialogue_message(game, NO_DIR, NULL, NULL);
    return ERROR;
  }

  if (strcasecmp(arg, "n") == 0 || strcasecmp(arg, "north") == 0) return game_command_north(game);
  if (strcasecmp(arg, "s") == 0 || strcasecmp(arg, "south") == 0) return game_command_south(game);
  if (strcasecmp(arg, "e") == 0 || strcasecmp(arg, "east") == 0) return game_command_east(game);
  if (strcasecmp(arg, "w") == 0 || strcasecmp(arg, "west") == 0) return game_command_west(game);
  if (strcasecmp(arg, "u") == 0 || strcasecmp(arg, "up") == 0) return game_command_up(game);
  if (strcasecmp(arg, "d") == 0 || strcasecmp(arg, "down") == 0) return game_command_down(game);

  dialogue_message(game, WRONG_DIR, arg, NULL);
  return ERROR;
}

/** game_command_attack executes the instructions for the ATTACK command
 */
STATUS game_command_attack(Game *game) {
  const int max_roll = 20;
  int       threshold, atk, def;
  time_t    t;
  int       roll, player_health, enemy_health, player_loc, enemy_loc;

  if (!game || (player_loc = player_get_location(game->p)) == NO_ID || (enemy_loc = enemy_get_location(game->e)) == NO_ID) return ERROR;

  if (player_loc != enemy_loc) {
    dialogue_message(game, NO_ENEMY, NULL, NULL);
    return ERROR;
  }

  player_health = player_get_health(game->p);
  atk           = player_get_atk(game->p);
  def           = player_get_def(game->p);
  enemy_health  = enemy_get_health(game->e);
  threshold     = enemy_get_strength(game->e);

  srand((unsigned)time(&t));
  roll = (rand() % max_roll) + atk;

  if (roll <= threshold) {
    if ((threshold -= def) <= 1)
      player_set_health(game->p, player_health - 1);
    else
      player_set_health(game->p, player_health - threshold);

    dialogue_message(game, PLAYER_HURT, NULL, NULL);
  } else {
    enemy_set_health(game->e, enemy_health - 1);
    dialogue_message(game, ENEMY_HURT, enemy_get_name(game_get_enemy(game)), NULL);
    if (enemy_get_health(game->e) <= 0) {
      dialogue_message(game, ENEMY_DESTROYED, enemy_get_name(game_get_enemy(game)), NULL);
      enemy_destroy(game->e);
      game->e = NULL;
    }
  }

  return OK;
}

/** game_command_inspect executes the instructions for the INSPECT command
 */

STATUS game_command_inspect(Game *game, const char *arg) {
  int        i;
  char       aux[WORD_SIZE] = "";
  Space     *s              = NULL;
  const Set *set_objs       = NULL;
  BOOL       light          = FALSE;

  if (!game || !arg) return ERROR;

  s        = game_get_space(game, player_get_location(game->p));
  set_objs = inventory_get_objs(player_get_inventory(game_get_player(game)));
  light    = space_get_light(s);

  if (light == FALSE) {
    for (i = 0; i < set_get_size(set_objs); i++) {
      if (object_get_turnedon(game_get_object_from_id(game, set_get_ids(set_objs)[i])) == TRUE) break;
    }

    if (i == set_get_size(set_objs)) {
      dialogue_message(game, NO_LIGHT, space_get_name(s), NULL);
      return ERROR;
    }
  }

  if (!strcmp(arg, "s") || !strcmp(arg, "space")) {
    for (i = 0; i < game->num_obj; i++) {
      if (space_has_object(s, object_get_id(game->objects[i]))) {
        object_set_hidden(game->objects[i], FALSE);
      }
    }

    strcpy(aux, space_get_name(s));
    strcat(aux, ": ");
    strcat(aux, space_get_ldescription(s));

    dialogue_message(game, SPACE, space_get_name(s), NULL);
    return game_set_last_description(game, aux);
  }

  for (i = 0; i < game->num_obj; i++) {
    if (!strcmp(arg, object_get_name(game->objects[i])) && object_get_hidden(game->objects[i]) == FALSE) {
      if (inventory_has_object((Inventory *)player_get_inventory(game->p), object_get_id(game->objects[i]))) {
        strcpy(aux, object_get_name(game->objects[i]));
        strcat(aux, ": ");
        strcat(aux, object_get_desc(game->objects[i]));

        dialogue_message(game, OBJECT_INVENTORY, arg, NULL);

        return game_set_last_description(game, aux);
      }
      if (space_has_object(game_get_space(game, player_get_location(game->p)), object_get_id(game->objects[i])) && object_get_hidden(game->objects[i]) == FALSE) {
        strcpy(aux, object_get_name(game->objects[i]));
        strcat(aux, ": ");
        strcat(aux, object_get_desc(game->objects[i]));

        dialogue_message(game, OBJECT_SPACE, arg, NULL);

        return game_set_last_description(game, aux);
      }
    }
  }

  return dialogue_message(game, CANT_INSPECT, arg, NULL);
}

/** game_command_open opens a link with an object from the inventory
 */
STATUS game_command_open(Game *game, char *arg) {
  Player *p;
  Object *target;
  Id      loc;
  char   *link_name, *obj_name, *tmp;
  int     i, j;

  if (!game || !arg) return ERROR;

  p   = game_get_player(game);
  loc = player_get_location(p);

  if (!(link_name = strtok(arg, " "))) {
    dialogue_message(game, STRUCTURE, NULL, NULL);
    return ERROR;
  }

  if (!(tmp = strtok(NULL, " "))) {
    dialogue_message(game, LINK_NAME, NULL, NULL);
    return ERROR;
  }

  if (strcmp(tmp, "with") != 0) {
    dialogue_message(game, STRUCTURE, NULL, NULL);
    return ERROR;
  }

  if (!(obj_name = strtok(NULL, " "))) {
    dialogue_message(game, OBJ_NAME, NULL, NULL);
    return ERROR;
  }

  target = game_get_object_from_name(game, obj_name);
  if (!inventory_has_object(player_get_inventory(p), object_get_id(target))) {
    dialogue_message(game, NO_OBJ, "use", NULL);
    return ERROR;
  }

  for (i = 0; i < game->num_link; i++) {
    if (link_get_origin((game->links)[i]) != loc) continue;

    if (strcasecmp(link_name, link_get_name((game->links)[i])) == 0 && object_get_open(target) == link_get_id((game->links)[i])) {
      for (j = 0; j < game->num_obj; j++) {
        if ((game->objects)[j] == target) {
          inventory_del_object((Inventory *)player_get_inventory(p), object_get_id(target));
          (game->objects)[j] = (game->objects)[--(game->num_obj)];
          object_destroy(target);
          break;
        }
      }
      dialogue_message(game, OPENED, link_name, obj_name);
      return link_set_status((game->links)[i], OK);
    }
  }

  dialogue_message(game, NOT_OPENED, link_name, obj_name);
  return ERROR;
}

/** game_command_save saves the game to a file
 */
STATUS game_command_save(Game *game, char *arg) {
  FILE *f;

  if (!game || !arg || arg[0] == '\0') {
    dialogue_message(game, WRONG_FILE, arg, NULL);
    return ERROR;
  }

  if (!(f = fopen(arg, "w"))) {
    dialogue_message(game, WRONG_FILE, arg, NULL);
    return ERROR;
  }

  game_management_save_spaces(game, f);
  game_management_save_player(game, f);
  game_management_save_objects(game, f);
  game_management_save_enemies(game, f);
  game_management_save_links(game, f);

  fclose(f);

  dialogue_message(game, SAVED, arg, NULL);

  return OK;
}

/** game_command_load loads a game session from a file
 */
STATUS game_command_load(Game **game, char *arg) {
  Game *res;

  if (!game || !arg || arg[0] == '\0') {
    dialogue_message(*game, WRONG_FILE, arg, NULL);
    return ERROR;
  }

  if (game_create_from_file(&res, arg) == ERROR) {
    game_destroy(res);
    dialogue_message(*game, WRONG_FILE, arg, NULL);
    return ERROR;
  }

  game_destroy(*game);
  *game = res;

  dialogue_message(*game, LOADED, arg, NULL);

  (*game)->last_cmd = LOAD;

  return OK;
}

/** game_get_object_from_name gets an object from its name
 */
Object *game_get_object_from_name(const Game *g, const char *name) {
  int i;

  if (!g || !name) return NULL;

  for (i = 0; i < g->num_obj; i++) {
    if (strcmp(name, object_get_name((g->objects)[i])) == 0) return (g->objects)[i];
  }

  return NULL;
}

/** space_get_obj_desc prints the visualization of the objects within a space to
 * a variable
 */
STATUS game_get_space_obj_desc(Game *game, const Space *space, char *res) {
  int  i = 0, j = 0;
  BOOL plus          = FALSE;
  char temp[OBJ_LEN] = "";

  if (!space || !res || !game) return ERROR;

  /*Default value in case there is an issue*/
  sprintf(res, "|               |");

  if (game->num_obj == 0) return OK;

  for (; i < game->num_obj; i++) {
    if (!space_has_object(space, object_get_id(game->objects[i]))) {
      continue;
    }

    if (strlen(temp) + strlen(object_get_name(game->objects[i])) <= (OBJ_LEN - 2) && object_get_hidden(game->objects[i]) == FALSE) {
      strcat(temp, object_get_name(game->objects[i]));
      strcat(temp, " ");
    } else {
      break;
    }

    j = i;
  }

  while (strlen(temp) < OBJ_LEN - 1) {
    strcat(temp, " ");
  }

  for (j++; j < game->num_obj; j++) {
    if (space_has_object(space, object_get_id(game->objects[j])) && object_get_hidden(game->objects[i]) == FALSE) {
      plus = TRUE;
      break;
    }
  }

  sprintf(res, "|%s %s|", temp, plus ? "+" : " ");

  return OK;
}
