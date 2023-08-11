/** 
 * @brief It implements the game interface and all the associated calls
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 3.0 
 * @date 26-01-2023 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "game_reader.h"

#include <unistd.h>
/**
   Private functions
*/

void game_command_unknown(Game *game);
void game_command_exit(Game *game);
STATUS game_command_next(Game *game);
STATUS game_command_back(Game *game);
STATUS game_command_left(Game *game);
STATUS game_command_right(Game *game);

/**
    Game interface implementation
*/

/** 
    game_create creats a new game, deleting the information
    saved in the memory
*/
STATUS game_create(Game *game) {
  int i;

  for (i = 0; i < MAX_SPACES; i++)
    game->spaces[i] = NULL;

  for (i=0; i<MAX_OBJECTS; i++)
    game->objects[i] = NULL;
  
  game->player = player_create(0);
  game->enemy = enemy_create(1);
  game->player->location = NO_ID;
  game->enemy->location = NO_ID;
  game->last_cmd = NO_CMD;
  game->st_last_cmd = ERROR;

  return OK;
}

/**
    game_create_from_file sets the object and the player in
    the first location
*/
STATUS game_create_from_file(Game *game, char *filename) {
  /* erroc checks */
  if (game_create(game) == ERROR)
    return ERROR;

  /* load spaces */
  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  /* load objects */
  if (game_reader_load_objects(game, filename) == ERROR)
    return ERROR;

  /* the player and the enemy are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_enemy_location(game, game_get_space_id_at(game, 0));

  return OK;
}

/**
    game_destroy destroys the game and the sapces in it
*/
STATUS game_destroy(Game *game) {
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    space_destroy(game->spaces[i]);

  for (i=0; i< MAX_OBJECTS && game->objects[i] != NULL; i++)
    object_destroy(game->objects[i]);

  player_destroy(game->player);
  enemy_destroy(game->enemy);

  return OK;
}

/**
    game_get_space selects an specific space from the current game
*/
Space *game_get_space(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID)
    return NULL;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i]))
      return game->spaces[i];
  }

  return NULL;
}

/**
    game_get_player_location takes the player's location
*/
Id game_get_player_location(Game *game) {
  return game->player->location;
}

/**
    game_get_enemy_location takes the player's location
*/
Id game_get_enemy_location(Game *game) {
  return game->enemy->location;
}

/**
    game_get_object_location takes the object's location
*/
Id game_get_object_location(Game *game, Id object) {
  int i;

  /* error checks */
  if(!game || object == NO_ID)
    return NO_ID;

  for(i=0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
    if (object == game->objects[i]->id)
      return game->objects[i]->location;

  return NO_ID;
}

/**
    game_get_object gets an objects from its id
*/
Object *game_get_object(Game *game, Id object) {
  int i;

  /* error checks */
  if(!game || object == NO_ID)
    return NULL;
  
  for(i=0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
    if (object == game->objects[i]->id)
      return game->objects[i];

  return NULL;
}

/**
    game_update selects the next command taken for the game
*/
STATUS game_update(Game *game, T_Command cmd) {
  game->last_cmd = cmd;
  game->st_last_cmd = ERROR;
  
  switch (cmd) {
    case UNKNOWN:
      game_command_unknown(game);
      break;

    case EXIT:
      game_command_exit(game);
      break;

    case NEXT:
      game->st_last_cmd = game_command_next(game);
      break;

    case BACK:
      game->st_last_cmd = game_command_back(game);
      break;
    
    case LEFT:
      game->st_last_cmd = game_command_left(game);
      break;
    
    case RIGHT:
      game->st_last_cmd = game_command_right(game);
      break;
    
    case TAKE:
      game->st_last_cmd = game_command_take(game);
      break;
    
    case DROP:
      game->st_last_cmd = game_command_drop(game);
      break;
    
    case ATTACK:
      game->st_last_cmd = game_command_attack(game);
      break;

    default:
      break;
  }

  return OK;
}

/**
    game_get_last_command takes the last command used
*/
T_Command game_get_last_command(Game *game) {
  return game->last_cmd;
}

/**
    game_get_last_commandSt takes the status of the las command used
*/
STATUS game_get_last_commandSt(Game *game){
  return game->st_last_cmd;
}

/**
    game_print_data prints the information about the spaces, the object's location and the player's location
*/
void game_print_data(Game *game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    space_print(game->spaces[i]);

  printf("=> Objects: \n");
  for (i=0; i< MAX_OBJECTS && game->objects[i] != NULL; i++)
    object_print(game->objects[i]);

  printf("=> Player location: %d\n", (int)game->player->location);
  printf("=> Player health: %d\n", (int)game->player->health);
  printf("=> Enemy location: %d\n", (int)game->enemy->location);
  printf("=> Enemy health: %d\n", (int)game->enemy->health);
}

/**
    game_is_over decides if the game has ended
*/
BOOL game_is_over(Game *game) {
  if (player_get_health(game->player) == 0)
    return TRUE;
  return FALSE;
}

/**
    game_add_space creates a new space for the game
*/
STATUS game_add_space(Game *game, Space *space) {
  int i = 0;

  if (!space)
    return ERROR;

  while (i < MAX_SPACES && game->spaces[i] != NULL)
    i++;

  if (i >= MAX_SPACES)
    return ERROR;

  game->spaces[i] = space;

  return OK;
}

/*
 * game_add_object creates a new object for the game
 */
STATUS game_add_object(Game *game, Object *object) {
  int i =0;

  /* error checks */
  if (!object)
    return ERROR;

  for(i=0; game->objects[i] != NULL; i++);

  if (i<MAX_OBJECTS){
    game->objects[i] = object;
    return OK;
  }

  return ERROR;
}

/**
    game_get_space_id_at gets the id number of a given space's location
*/
Id game_get_space_id_at(Game *game, int position) {
  /* error checks */
  if (position < 0 || position >= MAX_SPACES)
    return NO_ID;

  return space_get_id(game->spaces[position]);
}

/**
    game_set_player_location sets the player's location
*/
STATUS game_set_player_location(Game *game, Id id) {
  if (id == NO_ID)
    return ERROR;

  game->player->location = id;

  return OK;
}

/**
    game_set_enemy_location sets the player's location
*/
STATUS game_set_enemy_location(Game *game, Id id) {
  if (id == NO_ID)
    return ERROR;

  game->enemy->location = id;

  return OK;
}

/**
    game_set_object_location sets the object's location
*/
STATUS game_set_object_location(Game *game, Id object, Id location) {
  int i=0;
  if (object == NO_ID || location == NO_ID)
    return ERROR;

  for (i=0; i<MAX_OBJECTS; i++){
    if (object == game->objects[i]->id){
      object_set_location(game->objects[i], location);
      return OK;
    }
  }
  return ERROR;
}

/**
    game_command_take makes the player take an object
*/
STATUS game_command_take(Game *game){
  Id obj_id = -1;
  Id object_loc, player_loc;
  Object *object;

  scanf(" O%ld", &obj_id);
  if (obj_id < 0)
    return ERROR;

  object = game_get_object(game, obj_id);
  if (player_get_object(game->player) != NULL)
    return ERROR;

  object_loc = game_get_object_location(game, obj_id);
  player_loc = game_get_player_location(game);
  if (player_loc != object_loc)
    return ERROR;
  
  player_set_object(game->player, object);
  game_set_object_location(game, obj_id, player_loc);
  if (!(game_set_object_location(game, obj_id, player_loc)))
    return ERROR;
  if (!space_destroy_object(game_get_space(game, player_loc), obj_id))
    return ERROR;

  return OK;
}

/**
    game_command_drop makes the player drop the object
*/
STATUS game_command_drop(Game *game){
  Id player_loc = game_get_player_location(game);
  Id object_id = object_get_id(player_get_object(game->player));

  if (player_loc == NO_ID || object_id == NO_ID)
    return ERROR;
  if (!player_get_object(game->player))
    return ERROR;

  game_set_object_location(game, object_id, game_get_player_location(game));
  space_add_object(game_get_space(game, player_loc), object_id);
  player_set_object(game->player, NULL);

  return OK;
}

/**
    game_command_attack lets the player attack the enemy
*/
STATUS game_command_attack(Game *game){
  int att;
  Id space_id = NO_ID, enemy_id = NO_ID;

  space_id = game_get_player_location(game);
  enemy_id = game_get_enemy_location(game);
  if (space_id == NO_ID || enemy_id == NO_ID)
    return ERROR;

  if (space_id != enemy_id || enemy_get_health(game->enemy) <= 0)
    return ERROR;

  srand(time(NULL));
    att = rand()%10;
    if (att <= 4) player_set_health(game->player, player_get_health(game->player) -1);
    if (att >= 5) enemy_set_health(game->enemy, enemy_get_health(game->enemy) -1);
  
  return OK;
}

/**
   Calls implementation for each action 
*/
void game_command_unknown(Game *game) {
}

void game_command_exit(Game *game) {
}

STATUS game_command_next(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  current_id = space_get_south(game_get_space(game, space_id));

  if (space_id == NO_ID || current_id == NO_ID)
    return ERROR;

  
  game_set_player_location(game, current_id);
  if(game->player->player_object)
    game_set_object_location(game, object_get_id(player_get_object(game->player)), current_id);
  
  return OK;
}

STATUS game_command_back(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  current_id = space_get_north(game_get_space(game, space_id));

  if (space_id == NO_ID || current_id == NO_ID)
    return ERROR;

  game_set_player_location(game, current_id);
  if(game->player->player_object)
    game_set_object_location(game, object_get_id(player_get_object(game->player)), current_id);
  
  return OK;
}

STATUS game_command_left(Game *game){
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  current_id = space_get_west(game_get_space(game, space_id));

  if (space_id == NO_ID || current_id == NO_ID)
    return ERROR;

  game_set_player_location(game, current_id);
  if(game->player->player_object)
    game_set_object_location(game, object_get_id(player_get_object(game->player)), current_id);
  
  return OK;
}

STATUS game_command_right(Game *game){
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  current_id = space_get_east(game_get_space(game, space_id));

  if (space_id == NO_ID|| current_id == NO_ID)
    return ERROR;
  
  game_set_player_location(game, current_id);
  if(game->player->player_object)
    game_set_object_location(game, object_get_id(player_get_object(game->player)), current_id);
  
  return OK;
}