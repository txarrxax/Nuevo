/**
 * @brief It implements the loading of spaces
 *
 * @file game_management.c
 * @author Álvaro Grande
 * @author Diego Fernández
 * @version 2.0
 * @date 14/2/2023
 * @copyright GNU Public License
 */

#include <game.h>
#include <game_management.h>
#include <link.h>
#include <object.h>
#include <space.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <types.h>

/**
 * @brief Max. number of arguments that can be read from .dat file
 */
#define MAX_ARGS 16

/**
 * @brief Number of arguments needed to create a space
 */
#define SPACE_ARGS 11

/**
 * @brief Number of arguments needed to create an object
 */
#define OBJ_ARGS 12

/**
 * @brief Number of arguments needed to create a player
 */
#define PLAYER_ARGS 6

/**
 * @brief Number of arguments needed to create an enemy
 */
#define ENEMY_ARGS 6

/**
 * @brief Number of arguments needed to create a link
 */
#define LINK_ARGS 7

/*Private function prototypes*/
/**
 * @brief It parses the input from anthill.dat so that it can be processed with
 * ease in other functions
 * @author Diego Fernández
 *
 * @param f input stream
 * @param arg_num pointer to which the function will write the number of
 * arguments read
 * @param args pointer to which the arguments read will be written
 * @return OK if successful, ERROR if there was an issue
 */
STATUS game_management_parse_line(FILE *f, int *arg_num, char args[MAX_ARGS][WORD_SIZE]);

/**game_management_load_spaces reads data of the space and creates it
 */
STATUS game_management_load_spaces(Game *game, const char *filename) {
  FILE  *file = NULL;
  char   args[MAX_ARGS][WORD_SIZE];
  int    arg_num;
  Id     id     = NO_ID;
  Space *space  = NULL;
  STATUS status = ERROR;
  BOOL   light;

  /*Error control*/
  if (!filename || !game) return ERROR;

  /*Error control*/
  if (!(file = fopen(filename, "r"))) return ERROR;

  /*The space data is read*/
  while (game_management_parse_line(file, &arg_num, args) == OK) {
    if (arg_num == SPACE_ARGS && strcmp("s", args[0]) == 0) {
      if ((id = atol(args[1])) == NO_ID) continue;
      light = atoi(args[9]);
      /*The space is created using the function space_create*/
      if ((space = space_create(id)) != NULL) {
        space_set_name(space, args[2]);
        space_set_gdesc(space, args + 3);
        space_set_description(space, args[8]);
        space_set_light(space, light);
        space_set_ldescription(space, args[10]);
        game_add_space(game, space);
        status = OK;
      }

#ifdef DEBUG
      printf("Leido: %ld|%s|%s\n", atol(args[1]), args[2], args[8]);
#endif
    }
  }

  /*Error control*/
  if (ferror(file)) status = ERROR;

  fclose(file);

  return status;
}

/**game_management_load_objects reads data of the objects and creates them
 */
STATUS game_management_load_objects(Game *game, const char *filename) {
  FILE   *file = NULL;
  char    args[MAX_ARGS][WORD_SIZE];
  int     arg_num;
  Id      id = NO_ID, init_pos = NO_ID;
  Object *object = NULL;
  STATUS  status = OK;

  /*Error control*/
  if (!filename || !game) return ERROR;

  if (!(file = fopen(filename, "r"))) return ERROR;

  /*The object data is read*/
  while (game_management_parse_line(file, &arg_num, args) == OK) {
    if (arg_num == OBJ_ARGS && strcmp("o", args[0]) == 0) {
      id       = atol(args[1]);
      init_pos = atol(args[3]);

      if (game_get_object_from_name(game, args[2]) != NULL || strcasecmp("s", args[2]) == 0 || strcasecmp("space", args[2]) == 0) {
        fclose(file);
        return ERROR;
      }

#ifdef DEBUG
      printf("Leido: %ld|%ld\n", id, init_pos);
#endif

      /*The object is created*/
      if (!(object = object_create())) {
        fclose(file);
        return ERROR;
      }

      object_set_id(object, id);
      object_set_name(object, args[2]);
      object_set_desc(object, args[4]);
      game_add_object(game, object);

      if (init_pos == NO_ID) {
        if (player_add_item(game_get_player(game), id) == ERROR) {
          fclose(file);
          return ERROR;
        }
        player_add_stat(game_get_player(game), atoi(args[11]));
      } else {
        if (space_add_object(game_get_space(game, init_pos), id) == ERROR) {
          fclose(file);
          return ERROR;
        }
      }

      /*New properties*/
      if (object_set_hidden(object, atoi(args[5])) == ERROR) {
        fclose(file);
        return ERROR;
      }

      if (object_set_movable(object, atoi(args[6])) == ERROR) {
        fclose(file);
        return ERROR;
      }

      if (object_set_dependency(object, atol(args[7])) == ERROR) {
        fclose(file);
        return ERROR;
      }

      if (object_set_open(object, atol(args[8])) == ERROR) {
        fclose(file);
        return ERROR;
      }

      if (object_set_illuminate(object, atoi(args[9])) == ERROR) {
        fclose(file);
        return ERROR;
      }

      if (object_set_turnedon(object, atoi(args[10])) == ERROR) {
        fclose(file);
        return ERROR;
      }

      if (object_set_stats(object, atoi(args[11])) == ERROR) {
        fclose(file);
        return ERROR;
      }
    }
  }

  /*Error control*/
  if (ferror(file)) status = ERROR;

  fclose(file);

  return status;
}

/** game_management_load_player creates a player from the data of a given file
 */
STATUS game_management_load_player(Game *game, const char *filename) {
  FILE   *file;
  char    args[MAX_ARGS][WORD_SIZE];
  int     arg_num, health, inv_cap;
  Id      id, loc;
  STATUS  status = ERROR;
  Player *p;

  if (!game || !filename || !(p = game_get_player(game))) return ERROR;

  if (!(file = fopen(filename, "r"))) return ERROR;

  while (game_management_parse_line(file, &arg_num, args) == OK) {
    if (arg_num == PLAYER_ARGS && strcmp("p", args[0]) == 0) {
      id      = atol(args[1]);
      loc     = atol(args[3]);
      health  = atoi(args[4]);
      inv_cap = atoi(args[5]);

#ifdef DEBUG
      printf("Leido: %ld|%ld|%d|%d\n", id, loc, health, inv_cap);
#endif

      if (id == NO_ID || loc == NO_ID || health <= 0) break;
      player_set_id(p, id);
      player_set_name(p, args[2]);
      player_set_location(p, loc);
      player_set_health(p, health);
      player_set_inv_cap(p, inv_cap);
      status = OK;
      break;
    }
  }

  if (ferror(file)) status = ERROR;

  fclose(file);

  return status;
}

/** game_management_load_enemies loads the enemies from a file
 */
STATUS game_management_load_enemies(Game *game, const char *filename) {
  FILE  *file;
  char   args[MAX_ARGS][WORD_SIZE];
  int    arg_num, health;
  Id     id, loc;
  BOOL   enemy_found = FALSE;
  Enemy *e;

  if (!game || !filename || !(e = game_get_enemy(game))) return ERROR;

  if (!(file = fopen(filename, "r"))) return ERROR;

  while (game_management_parse_line(file, &arg_num, args) == OK) {
    if (arg_num == ENEMY_ARGS && strcmp("e", args[0]) == 0) {
      id     = atol(args[1]);
      loc    = atol(args[3]);
      health = atoi(args[4]);

#ifdef DEBUG
      printf("Leido: %ld|%ld|%d\n", id, loc, health);
#endif

      if (id == NO_ID || loc == NO_ID || health <= 0) break;
      enemy_set_id(e, id);
      enemy_set_name(e, args[2]);
      enemy_set_location(e, loc);
      enemy_set_health(e, health);
      enemy_set_strength(e, atoi(args[5]));
      enemy_found = TRUE;
      break;
    }
  }

  if (ferror(file)) return ERROR;

  fclose(file);

  if (!enemy_found) game_no_enemy(game);

  return OK;
}

/**game_management_load_links reads data of the links and creates them
 */
STATUS game_management_load_links(Game *game, const char *filename) {
  FILE     *file = NULL;
  char      args[MAX_ARGS][WORD_SIZE];
  int       arg_num;
  Link     *link = NULL;
  Id        id = NO_ID, orig = NO_ID, dest = NO_ID;
  DIRECTION dir = X;
  STATUS    st  = ERROR;

  /* error control */
  if (!game || !filename) return ERROR;

  /* open the file */
  file = fopen(filename, "r");
  if (!file) return ERROR;

  /* read the file */
  while (game_management_parse_line(file, &arg_num, args) == OK) {
    if (arg_num == LINK_ARGS && strcmp("l", args[0]) == 0) {
      id   = atol(args[1]);
      orig = atol(args[3]);
      dest = atol(args[4]);
      dir  = atoi(args[5]);
      st   = atoi(args[6]);

#ifdef DEBUG
      printf("Leido: %ld|%ld|%ld|%d|%d\n", id, orig, dest, dir, st);
#endif
      /* create the link */
      if ((link = link_create(id)) != NULL) {
        link_set_name(link, args[2]);
        link_set_origin(link, orig);
        link_set_dest(link, dest);
        link_set_direction(link, dir);
        link_set_status(link, st);
        game_add_link(game, link);
      }
    }
  }

  /* error control*/
  if (ferror(file)) {
    fclose(file);
    return ERROR;
  }

  /* close the file */
  fclose(file);

  return OK;
}

/** game_management_save_spaces saves the space data to a file stream
 */
STATUS game_management_save_spaces(const Game *game, FILE *f) {
  int           i, j;
  const Space **data;
  const char  **gdesc;

  if (!(data = game_get_all_spaces(game)) || !f) return ERROR;

  for (i = 0; i < MAX_SPACES && (data)[i] != NULL; i++) {
    fprintf(f, "#s:%ld;%s;", space_get_id(data[i]), space_get_name(data[i]));
    gdesc = space_get_gdesc(data[i]);
    for (j = 0; j < G_SLOTS; j++) {
      fprintf(f, "%s;", gdesc[j]);
    }
    fprintf(f, "%s;%d;%s\n", space_get_description(data[i]), space_get_light(data[i]), space_get_ldescription(data[i]));
  }

  return OK;
}

/** game_management_save_player saves the state of the player in a file stream
 */
STATUS game_management_save_player(const Game *game, FILE *f) {
  Player *p;

  if (!game || !f) return ERROR;

  p = game_get_player((Game *)game);

  fprintf(f, "#p:%ld;%s;%ld;%d;%d\n", player_get_id(p), player_get_name(p), player_get_location(p), player_get_health(p), inventory_get_max_objs(player_get_inventory(p)));

  return OK;
}

/** game_management_save_objects saves the state of the objects in a file stream
 */
STATUS game_management_save_objects(const Game *game, FILE *f) {
  int            num_obj, i;
  const Object **data;

  if (!(data = game_get_all_objects(game)) || (num_obj = game_get_number_of_objects(game)) == -1 || !f) return ERROR;

  for (i = 0; i < num_obj; i++) {
    fprintf(f, "#o:%ld;%s;%ld;%s;%d;%d;%ld;%ld;%d;%d;%d\n", object_get_id(data[i]), object_get_name(data[i]), game_get_object_location(game, data[i]), object_get_desc(data[i]), object_get_hidden(data[i]), object_get_movable(data[i]), object_get_dependency(data[i]), object_get_open(data[i]), object_get_illuminate(data[i]), object_get_turnedon(data[i]), object_get_stats(data[i]));
  }

  return OK;
}

/** game_management_save_enemies saves the state of the enemies in a file stream
 */
STATUS game_management_save_enemies(const Game *game, FILE *f) {
  Enemy *e;

  if (!game || !f) return ERROR;

  e = game_get_enemy((Game *)game);

  if (e != NULL) fprintf(f, "#e:%ld;%s;%ld;%d;%d\n", enemy_get_id(e), enemy_get_name(e), enemy_get_location(e), enemy_get_health(e), enemy_get_strength(e));

  return OK;
}

/** game_management_save_links saves the state of the links in a file stream
 */
STATUS game_management_save_links(const Game *game, FILE *f) {
  int          i, num_links;
  const Link **data;

  if (!(data = game_get_all_links(game)) || (num_links = game_get_num_links(game)) == -1 || !f) return ERROR;

  for (i = 0; i < num_links; i++) {
    fprintf(f, "#l:%ld;%s;%ld;%ld;%d;%d\n", link_get_id(data[i]), link_get_name(data[i]), link_get_origin(data[i]), link_get_dest(data[i]), link_get_direction(data[i]), link_get_status(data[i]));
  }

  return OK;
}

/*Private function definitions*/
/** game_management_parse_line parses the input from a .dat file so that it can be
 * processed in other functions with ease
 */
STATUS game_management_parse_line(FILE *f, int *arg_num, char args[MAX_ARGS][WORD_SIZE]) {
  char  raw_input[WORD_SIZE];
  char *toks;
  int   i, len;

  if (!f || !arg_num) return ERROR;

  if (!fgets(raw_input, WORD_SIZE, f)) return ERROR;

  if (raw_input[0] != '#' || raw_input[2] != ':') return ERROR;

  *arg_num   = 1;
  args[0][0] = raw_input[1];
  args[0][1] = '\0';

  for (toks = strtok(raw_input + 3, ";"); toks != NULL && *arg_num < MAX_ARGS; toks = strtok(NULL, ";"), (*arg_num)++) {
    strcpy(args[*arg_num], toks);
  }
  len = strlen(args[(*arg_num) - 1]);
  for (i = 0; i < len; i++) {
    if (args[(*arg_num) - 1][i] == '\n' || args[(*arg_num) - 1][i] == '\r') args[(*arg_num) - 1][i] = '\0';
  }
  return OK;
}
