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

#include <game.h>
#include <game_reader.h>
#include <inventory.h>
#include <link.h>
#include <object.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

/**
 * @brief Default health assgined to the player at the start of a game session
 */
#define DEFAULT_HEALTH 3

/**
 * @brief Default health assgined to the enemy at the start of a game session
 */
#define ENEMY_HEALTH 3

/**
 * @brief Max number of characters 
*/
#define MAX_CHAR 64

/**
 * @brief Max number of character of an objects description
*/
#define OBJ_LEN 14

/**
 * @brief This struct contains a game session
 */
struct _Game
{

  Player *p;                 /*!< Pointer to player struct */
  Object *objects[MAX_OBJ];  /*!< Array of all objects in the game */
  int num_obj;               /*!< Number of objects */
  Space *spaces[MAX_SPACES]; /*!< Array in which the rooms are stored */
  Link *links[MAX_LINKS];    /*!< Array with the links between spaces */
  T_Command last_cmd;        /*!< Last command read from the prompt */
  STATUS last_cmd_exit;      /*!< Exit of the last command used*/
  Enemy *e;                  /*!< Pointer to enemy struct*/
  char last_des[WORD_SIZE];  /*!< Array with the last description asked*/
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
 * @brief It executes the instructions for the NEXT command
 * @author Profesores PPROG
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_next(Game *game);

/**
 * @brief It executes the instructions for the BACK command
 * @author Profesores PPROG
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_back(Game *game);

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
 * @brief It executes the instructions for the RIGHT command
 * @author Álvaro Grande
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_right(Game *game);

/**
 * @brief It executes the instructions for the LEFT command
 * @author Álvaro Grande
 *
 * @param game a pointer to the game session
 * @return OK if the command has been executed correctly, ERROR if not
 */
STATUS game_command_left(Game *game);

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
 * @brief Gets the id of a space given its index
 * @author Diego Fernández
 *
 * @param game a pointer to the game session
 * @param position index of the space
 * @return Id of the room, NO_ID if there was an issue
 */
Id game_get_space_id_at(const Game *game, const int position);

/**
   Public Functions
*/

/** game_create_from_file creates a new game session from a file
 */
STATUS game_create_from_file(Game **game, const char *filename)
{
  if (game_create(game) == ERROR || !filename)
    return ERROR;

  if (game_reader_load_spaces(*game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_objects(*game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_player(*game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_enemies(*game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_links(*game, filename) == ERROR)
    return ERROR;

  if (game_set_last_description(*game, "\0") == ERROR)
    return ERROR;

  return OK;
}

/** game_destroy deletes a game session
 */
STATUS game_destroy(Game *game)
{
  int i;

  /*Error control*/
  if (!game)
    return ERROR;

  /*Spaces (rooms) are deleted one by one*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }

  /*Objects are deleted one by one*/
  for (i = 0; i < game->num_obj; i++)
  {
    object_destroy((game->objects)[i]);
  }

  /*Links are deleted one by one*/
  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++)
    link_destroy(game->links[i]);

  /*Player is deleted*/
  player_destroy(game->p);

  /*Enemy is deleted*/
  enemy_destroy(game->e);

  free(game);

  return OK;
}

/** game_add_space adds a space to the game session
 */
STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  if (!space || !game)
    return ERROR;

  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
    return ERROR;

  game->spaces[i] = space;

  return OK;
}

/** game_get_space finds a space with the given id
 */
Space *game_get_space(const Game *game, const Id id)
{
  int i;

  /*Error control*/
  if (id == NO_ID || !game)
    return NULL;

  /*We loop through all spaces until we find one with the desired id
   * or until there are no more spaces*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    /*We return a pointer to the space with the matching id*/
    if (id == space_get_id(game->spaces[i]))
      return game->spaces[i];
  }

  /*If no space was found, NULL is returned*/
  return NULL;
}

/** game_update updates the state of the game given a command
 */
STATUS game_update(Game *game, const T_Command cmd, const char *arg)
{
  /*Error control*/
  if (!game || !arg)
    return ERROR;

  /*The last command is updated*/
  game->last_cmd = cmd;

  /*We execute the instructions given by the command*/
  switch (cmd)
  {

  case UNKNOWN:
    game_command_unknown(game);
    game->last_cmd_exit = ERROR;
    break;

  case EXIT:
    game_command_exit(game);
    game->last_cmd_exit = OK;
    break;

  case NEXT:
    game->last_cmd_exit = game_command_next(game);
    break;

  case BACK:
    game->last_cmd_exit = game_command_back(game);
    break;

  case TAKE:
    game->last_cmd_exit = game_command_take(game, arg);
    break;

  case DROP:
    game->last_cmd_exit = game_command_drop(game, arg);
    break;

  case RIGHT:
    game->last_cmd_exit = game_command_right(game);
    break;

  case LEFT:
    game->last_cmd_exit = game_command_left(game);
    break;

  case ATTACK:
    game->last_cmd_exit = game_command_attack(game);
    break;

  case INSPECT:
    game->last_cmd_exit = game_command_inspect(game, arg);
    break;

  case MOVE:
    game->last_cmd_exit = game_command_move(game, arg);
    break;

  default:
    break;
  }

  return game->last_cmd_exit;
}

/** game_is_over checks if gameover conditions have been reached
 */
BOOL game_is_over(const Game *game)
{
  if (!game || player_get_health(game->p) <= 0)
    return TRUE;

  return FALSE;
}

/** game_get_last_command gets the last command used
 */
T_Command game_get_last_command(const Game *game)
{
  /*Error control*/
  if (!game)
    return NO_CMD;

  return game->last_cmd;
}

/** game_print_data prints data of the current game state to the console
 */
STATUS game_print_data(const Game *game)
{
  int i;

  /*Error control*/
  if (!game)
    return ERROR;

  printf("\n\n-------------\n\n");

  /*The data of each space is printed*/
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  /*The locations of the player and the object are printed*/
  printf("=> Player location: %d\n", (int)player_get_location(game->p));

  /*Object info is printed*/
  for (i = 0; i < game->num_obj; i++)
  {
    object_print((game->objects)[i]);
  }

  /*Last description is printed*/
  printf("=> Last Description: %s", game_get_last_description((Game *)game));

  return OK;
}

/** game_get_object_location gets the location of the object
 */
Id game_get_object_location(const Game *game, const Object *object)
{
  int i;
  Id id;

  if (!game)
    return NO_ID;

  if ((id = object_get_id(object)) == NO_ID)
    return NO_ID;

  for (i = 0; i < MAX_SPACES && (game->spaces)[i] != NULL; i++)
  {
    if (space_has_object((game->spaces)[i], id))
      return space_get_id((game->spaces)[i]);
  }

  return NO_ID;
}

/** game_add_object adds a new object to the game
 */
STATUS game_add_object(Game *game, Object *object)
{
  if (!game || !object)
    return ERROR;
  if (game->num_obj == MAX_OBJ)
    return ERROR;

  game->objects[(game->num_obj)++] = object;

  return OK;
}

/** game_get_player gets the player of the game
 */
Player *game_get_player(Game *game)
{
  if (!game)
    return NULL;
  return game->p;
}

/** game_get_enemy gets the enemy of the game
 */
Enemy *game_get_enemy(Game *game)
{
  if (!game)
    return NULL;
  return game->e;
}

/** game_get_number_of_objects gets the number of objects of the game
 */
int game_get_number_of_objects(Game *game)
{
  if (!game)
    return -1;
  return game->num_obj;
}

/** game_get_object_from_position gets an object of the game from its position
 */
Object *game_get_object_from_position(Game *game, int position)
{
  if (!game || position < 0)
    return NULL;
  if (position > game->num_obj)
    return NULL;
  return game->objects[position];
}

/** game_get_last_command_exit gets the status of the last command
 */
STATUS game_get_last_command_exit(Game *game)
{
  if (!game)
    return ERROR;
  return game->last_cmd_exit;
}

/** game_get_connection_status gets the status of a link in the game
 */
STATUS game_get_connection_status(Game *game, Id space, DIRECTION dir) {
  int i;
  /* error checks */
  if (!game || !space || dir == -1)
    return ERROR;

  for (i = 0; i < MAX_LINKS; i++)
  {
    if (link_get_origin(game->links[i]) == space)
    {
      if (link_get_direction(game->links[i]) == dir)
      {
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
  if (!game || !space || dir == -1)
    return NO_ID;

  for (i = 0; i < MAX_LINKS; i++)
  {
    if (link_get_origin(game->links[i]) == space &&
        link_get_direction(game->links[i]) == dir)
    {
      return link_get_dest(game->links[i]);
    }
  }
  return NO_ID;
}

/** game_add_space adds a space to the game session
 */
STATUS game_add_link(Game *game, Link *link)
{
  int i = 0;

  if (!link || !game)
    return ERROR;

  while (i < MAX_LINKS && game->links[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_LINKS)
    return ERROR;

  game->links[i] = link;

  return OK;
}

/** game_set_last_description sets the last description of a game
 */
STATUS game_set_last_description(Game *game, char *des) {
  if (!game)
    return ERROR;
  strcpy(game->last_des, des);
  return OK;
}

/** game_get_last_description gets the last description of a game
 */
char *game_get_last_description(Game *game) {
  if (!game)
    return NULL;
  return game->last_des;
}

/** game_get_object_from_id gets an object from its id
 */
Object *game_get_object_from_id(const Game *g, const Id id)
{
  int i;

  if (!g || id == NO_ID)
    return NULL;

  for (i = 0; i < g->num_obj; i++)
  {
    if (object_get_id((g->objects)[i]) == id)
      return (g->objects)[i];
  }

  return NULL;
}

/*  PRIVATE FUNCTIONS IMPLEMENTATION*/

/** game_command_unknown executes the instructions for the UNKNOWN command
 */
void game_command_unknown(Game *game) {}

/** game_command_exit executes the instructions for the EXIT command
 */
void game_command_exit(Game *game) {}

/** game_command_next executes the instructions for the NEXT command
 */
STATUS game_command_next(Game *game)
{
  Id space_id = NO_ID;

  /*The player's location is found*/
  /*Error control*/
  if (!game || (space_id = player_get_location(game->p)) == NO_ID)
    return ERROR;

  /*If the connection exists, the location of the player changes*/
  if (game_get_connection_status(game, space_id, S) == OK)
  {
    player_set_location(game->p, game_get_connection(game, space_id, S));
    return OK;
  }
  return ERROR;
}

/** game_command_back executes the instructions for the BACK command
 */
STATUS game_command_back(Game *game)
{
  Id space_id = NO_ID;

  /*The player's location is found*/
  /*Error control*/
  if (!game || (space_id = player_get_location(game->p)) == NO_ID)
    return ERROR;

  /*If the connection exists, the location of the player changes*/
  if (game_get_connection_status(game, space_id, N) == OK)
  {
    player_set_location(game->p, game_get_connection(game, space_id, N));
    return OK;
  }
  return ERROR;
}

/** game_command_take executes instructions for the TAKE command
 */
STATUS game_command_take(Game *game, const char *arg)
{
  Space *current_room;
  Id target;

  if (!(current_room = game_get_space(game, player_get_location(game->p))))
    return ERROR;

  target = object_get_id(game_get_object_from_name(game, arg));

  if (!(space_has_object(current_room, target)))
    return ERROR;

  if (player_add_item(game->p, target) == ERROR)
    return ERROR;

  space_del_object(current_room, target);

  return OK;
}

/** game_command_drop executes the instructions for the DROP command
 */
STATUS game_command_drop(Game *game, const char *arg)
{
  Space *current_room;
  Id target;

  if (!(current_room = game_get_space(game, player_get_location(game->p))))
    return ERROR;

  target = object_get_id(game_get_object_from_name(game, arg));

  if (player_del_item(game->p, target) == ERROR)
    return ERROR;

  if (space_add_object(current_room, target) == ERROR)
  {
    player_add_item(game->p, target);
    return ERROR;
  }

  return OK;
}

/** game_command_right executes the instructions for the RIGHT command
 */
STATUS game_command_right(Game *game)
{
  Id space_id = NO_ID;

  /*The player's location is found*/
  /*Error control*/
  if (!game || (space_id = player_get_location(game->p)) == NO_ID)
    return ERROR;

  /*If the connection exists, the location of the player changes*/
  if (game_get_connection_status(game, space_id, E) == OK)
  {
    player_set_location(game->p, game_get_connection(game, space_id, E));
    return OK;
  }
  return ERROR;
}

/** game_command_left executes the instructions for the LEFT command
 */
STATUS game_command_left(Game *game)
{
  Id space_id = NO_ID;

  /*The player's location is found*/
  /*Error control*/
  if (!game || (space_id = player_get_location(game->p)) == NO_ID)
    return ERROR;

  /*If the connection exists, the location of the player changes*/
  if (game_get_connection_status(game, space_id, W) == OK)
  {
    player_set_location(game->p, game_get_connection(game, space_id, W));
    return OK;
  }
  return ERROR;
}

/** game_command_move executes the instructions for the MOVE command
 */
STATUS game_command_move(Game *game, const char *arg)
{
  if (strcasecmp(arg, "n") == 0 || strcasecmp(arg, "north") == 0)
    return game_command_back(game);
  if (strcasecmp(arg, "s") == 0 || strcasecmp(arg, "south") == 0)
    return game_command_next(game);
  if (strcasecmp(arg, "w") == 0 || strcasecmp(arg, "west") == 0)
    return game_command_left(game);
  if (strcasecmp(arg, "e") == 0 || strcasecmp(arg, "east") == 0)
    return game_command_right(game);

  return ERROR;
}

/** game_command_attack executes the instructions for the ATTACK command
 */
STATUS game_command_attack(Game *game)
{
  const int max_roll = 10, threshold = 4;
  time_t t;
  int roll, player_health, enemy_health, player_loc, enemy_loc;

  if (!game || (player_loc = player_get_location(game->p)) == NO_ID ||
      (enemy_loc = enemy_get_location(game->e)) == NO_ID)
    return ERROR;

  if (player_loc != enemy_loc)
    return ERROR;

  player_health = player_get_health(game->p);
  enemy_health = enemy_get_health(game->e);

  srand((unsigned)time(&t));
  roll = rand() % max_roll;

  if (roll <= threshold)
  {
    player_set_health(game->p, player_health - 1);
  }
  else
  {
    enemy_set_health(game->e, enemy_health - 1);
    if (enemy_get_health(game->e) <= 0)
    {
      enemy_destroy(game->e);
      game->e = NULL;
    }
  }

  return OK;
}

/** game_command_inspect executes the instructions for the INSPECT command
 */
STATUS game_command_inspect(Game *game, const char *arg) {
  int i;
  char aux[WORD_SIZE];
  Space *s = NULL;
  if (!game || !arg)
    return ERROR;

  strcpy(aux, "\0");

  if (!strcmp(arg, "s") || !strcmp(arg, "space"))
  {
    s = game_get_space(game, player_get_location(game->p));
    strcpy(aux, space_get_name(s));
    strcat(aux, ": ");
    strcat(aux, space_get_description(s));
    return game_set_last_description(game, aux);
  }

  for (i = 0; i < game->num_obj; i++)
  {
    if (!strcmp(arg, object_get_name(game->objects[i])))
    {
      if (inventory_has_object((Inventory *)player_get_inventory(game->p),
                              object_get_id(game->objects[i])))
      {
        strcpy(aux, object_get_name(game->objects[i]));
        strcat(aux, ": ");
        strcat(aux, object_get_desc(game->objects[i]));
        return game_set_last_description(game, aux);
      }
      if (space_has_object(game_get_space(game, player_get_location(game->p)),
                           object_get_id(game->objects[i])))
      {
        strcpy(aux, object_get_name(game->objects[i]));
        strcat(aux, ": ");
        strcat(aux, object_get_desc(game->objects[i]));
        return game_set_last_description(game, aux);
      }
    }
  }
  return ERROR;
}

/** game_get_object_from_name gets an object from its name
 */
Object *game_get_object_from_name(const Game *g, const char *name)
{
  int i;

  if (!g || !name)
    return NULL;

  for (i = 0; i < g->num_obj; i++)
  {
    if (strcmp(name, object_get_name((g->objects)[i])) == 0)
      return (g->objects)[i];
  }

  return NULL;
}

/** game_get_space_id_at gets the id of a space from its index
 */
Id game_get_space_id_at(const Game *game, const int position)
{
  if (position < 0 || position >= MAX_SPACES || !game)
    return NO_ID;

  return space_get_id(game->spaces[position]);
}

/** game_create initializes a game session
 */
STATUS game_create(Game **game)
{
  int i;

  if (!game)
    return ERROR;

  if (!(*game = malloc(sizeof(Game))))
    return ERROR;

  /*All space pointers are NULL by default*/
  for (i = 0; i < MAX_SPACES; i++)
  {
    (*game)->spaces[i] = NULL;
  }

  /*All links pointers are NULL by default*/
  for (i = 0; i < MAX_LINKS; i++)
  {
    (*game)->links[i] = NULL;
  }

  /*Player is initialized*/
  (*game)->p = player_create();

  /*Enemy is initialized*/
  (*game)->e = enemy_create();

  /*Object list empty by default*/
  for (i = 0; i < MAX_OBJ; i++)
  {
    ((*game)->objects)[i] = NULL;
  }
  (*game)->num_obj = 0;

  /*As the new game session is empty, there is no last_cmd*/
  (*game)->last_cmd = NO_CMD;

  (*game)->last_cmd_exit = OK;

  strcpy((*game)->last_des, "");

  return OK;
}

/** space_get_obj_desc prints the visualization of the objects within a space to
 * a variable
 */
STATUS game_get_space_obj_desc(Game *game, const Space *space, char *res)
{
  int i = 0, j = 0;
  BOOL plus = FALSE;
  char temp[OBJ_LEN] = "";

  if (!space || !res || !game)
    return ERROR;

  /*Default value in case there is an issue*/
  sprintf(res, "|               |");

  if (game->num_obj == 0)
    return OK;

  for (; i < game->num_obj; i++)
  {
    if (!space_has_object(space, object_get_id(game->objects[i])))
    {
      continue;
    }

    if (strlen(temp) + strlen(object_get_name(game->objects[i]) + 1) <= (OBJ_LEN - 1))
    {
      strcat(temp, object_get_name(game->objects[i]));
      strcat(temp, " ");
    }
    else
    {
      break;
    }

    j = i;
  }
  while (strlen(temp) < OBJ_LEN - 1)
  {
    strcat(temp, " ");
  }

  for (j++; j < game->num_obj; j++)
  {
    if (space_has_object(space, object_get_id(game->objects[j])))
    {
      plus = TRUE;
      break;
    }
  }

  sprintf(res, "|%s %s|", temp, plus ? "+" : " ");

  return OK;
}
