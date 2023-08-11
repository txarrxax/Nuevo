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
#include "game.h"
#include "game_reader.h"

#include <unistd.h>
/**
   Private functions
*/

void game_command_unknown(Game *game);
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);

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

  game->player = player_create(0);
  game->object = object_create(123);
  game->player->location = NO_ID;
  game->object->location = NO_ID;
  game->last_cmd = NO_CMD;

  return OK;
}

/**
    game_create_from_file sets the object and the player in
    the first location
*/
STATUS game_create_from_file(Game *game, char *filename) {
  if (game_create(game) == ERROR)
    return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

/**
    game_destroy destroys the game and the sapces in it
*/
STATUS game_destroy(Game *game) {
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    space_destroy(game->spaces[i]);

  player_destroy(game->player);
  object_destroy(game->object);

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
    game_get_object_location takes the object's location
*/
Id game_get_object_location(Game *game) {
  return game->object->location;
}

/**
    game_update selects the next command taken for the game
*/
STATUS game_update(Game *game, T_Command cmd) {
  game->last_cmd = cmd;
  
  switch (cmd) {
    case UNKNOWN:
      game_command_unknown(game);
      break;

    case EXIT:
      game_command_exit(game);
      break;

    case NEXT:
      game_command_next(game);
      break;

    case BACK:
      game_command_back(game);
      break;
    
    case TAKE:
      game_command_take(game);
      break;
    
    case DROP:
      game_command_drop(game);
      break;

    default:
      break;
  }

  return OK;
}

/**
    game_get_last_command takes the last commando used
*/
T_Command game_get_last_command(Game *game) {
  return game->last_cmd;
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

  printf("=> Object location: %d\n", (int)game->object->location);
  printf("=> Player location: %d\n", (int)game->player->location);
}

/**
    game_is_over decides if the game has ended
*/
BOOL game_is_over(Game *game) {
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

/**
    game_get_space_id_at gets the id number of a given space's location
*/
Id game_get_space_id_at(Game *game, int position) {
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
    game_set_object_location sets the object's location
*/
STATUS game_set_object_location(Game *game, Id id) {
  if (id == NO_ID)
    return ERROR;
  
  game->object->location = id;
  space_set_object(game_get_space(game, id), TRUE);
  return OK;
}


/**
   Calls implementation for each action 
*/
void game_command_unknown(Game *game) {
}

void game_command_exit(Game *game) {
}

void game_command_next(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
    return;

  current_id = space_get_south(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
    if(game->player->player_object)
      game_set_object_location(game, current_id);
  }
  
  return;
}

void game_command_back(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
    return;

  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
    if(game->player->player_object)
      game_set_object_location(game, current_id);
  }
  
  return;
}

void game_command_take(Game *game){
  Id object_loc = game_get_object_location(game);
  Id player_loc;
  if ((player_get_object(game->player)) != NULL){
    return;
  }
  player_loc = game_get_player_location(game);
  if (player_loc == object_loc){
    if ((!player_set_object(game->player, game->object)))
      return;
    if (!(game_set_object_location(game, game_get_player_location(game))))
      return;
  }
  return;
}

void game_command_drop(Game *game){
  if ((player_get_object(game->player)) == game->object){
    player_set_object(game->player, NULL);
    game_set_object_location(game, game_get_player_location(game));
  }
  return;
}
