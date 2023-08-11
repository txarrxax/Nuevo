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

/**
   Private functions
*/

/**
  * @brief It loads the spaces from a file
  * @author Profesores PPROG
  *
  * @param game a pointer to the current game
  * @param filename an array with the name of the file
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_load_spaces(Game *game, char *filename);

/**
  * @brief It adds a new space to the current game
  * @author Profesores PPROG
  *
  * @param game a pointer to the current game
  * @param space a pointer to the new space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_add_space(Game *game, Space *space);

/**
  * @brief It gets the id number of a given space's location
  * @author Profesores PPROG
  *
  * @param game a pointer to the current game
  * @param position an integer with the position of the space
  * @return the space id, if everything goes well or NO_ID if there was some mistake
  */
Id game_get_space_id_at(Game *game, int position);

/**
  * @brief It sets the player's location
  * @author Profesores PPROG
  *
  * @param game a pointer to the current game
  * @param id number of the player location
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_set_player_location(Game *game, Id id);

/**
  * @brief It sets the object's location
  * @author Profesores PPROG
  *
  * @param game a pointer to the current game
  * @param id number of the object location
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_set_object_location(Game *game, Id id);


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

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->player_location = NO_ID;
  game->object_location = NO_ID;
  game->last_cmd = NO_CMD;

  return OK;
}

/**
    game_create_from_file sets the object and the player in
    the first location
*/
STATUS game_create_from_file(Game *game, char *filename) {
  if (game_create(game) == ERROR) {
    return ERROR;
  }

  if (game_load_spaces(game, filename) == ERROR) {
    return ERROR;
  }

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

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_destroy(game->spaces[i]);
  }

  return OK;
}

/**
    game_add_space creates a new space for the game
*/
STATUS game_add_space(Game *game, Space *space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL) {
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

/**
    game_get_space_id_at gets the id number of a given space's location
*/
Id game_get_space_id_at(Game *game, int position) {
  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/**
    game_get_space selects an specific space from the current game
*/
Space *game_get_space(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])) {
      return game->spaces[i];
    }
  }

  return NULL;
}

/**
    game_set_player_location sets the player's location
*/
STATUS game_set_player_location(Game *game, Id id) {
  if (id == NO_ID) {
    return ERROR;
  }

  game->player_location = id;

  return OK;
}

/**
    game_set_object_location sets the object's location
*/
STATUS game_set_object_location(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return ERROR;
  }
  
  game->object_location = id;
  space_set_object(game_get_space(game, id), TRUE);
}


/**
    game_get_player_location takes the player's location
*/
Id game_get_player_location(Game *game) {
  return game->player_location;
}

/**
    game_get_object_location takes the object's location
*/
Id game_get_object_location(Game *game) {
  return game->object_location;
}

/**
    game_update selects the next commando taken for the game
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
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int)game->object_location);
  printf("=> Player location: %d\n", (int)game->player_location);
}

/**
    game_is_over decides if the game has ended
*/
BOOL game_is_over(Game *game) {
  return FALSE;
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
  if (space_id == NO_ID) {
    return;
  }

  current_id = space_get_south(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }
  
  return;
}

void game_command_back(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return;
  }

  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }
  
  return;
}

STATUS game_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}
