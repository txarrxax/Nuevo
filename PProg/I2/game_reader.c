/** 
 * @brief It implements the game_reader interface and all the associated calls
 * for each command
 * 
 * @file game_reader.c
 * @author Alberto Tarrasa
 * @version 1.0 
 * @date 07-02-2023 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "game_reader.h"


/**
    game_reader_load_spaces loads the spaces from a file
*/
STATUS game_reader_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  int i;
  char **desc = NULL;

  if (!filename) 
    return ERROR;

  file = fopen(filename, "r");
  if (!file)
    return ERROR;

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      desc = (char **)malloc(HEIGHT*sizeof(char*));
      if (!desc){
        fclose(file);
        return ERROR;
      }

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
      for (i=0; i<HEIGHT; i++){
        toks = strtok(NULL, "|");
        desc[i] = toks;
      }

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s|%s|%s|%s|%s\n", id, name, north, east, south, west, desc[0], desc[1], desc[2], desc[3], desc[4]);
#endif
      space = space_create(id);
      if (space) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);

        for (i=0; i<HEIGHT; i++)
          space_set_gDesc(space, desc[i]);
          
        game_add_space(game, space);


        free(desc);
      }
    }
  }

  if (ferror(file))
    status = ERROR;

  fclose(file);

  return status;
}

/**
    game_reader_load_objects loads the objects from a file
*/
STATUS game_reader_load_objects(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object *object = NULL;
  STATUS status = OK;

  if (!filename) 
    return ERROR;

  file = fopen(filename, "r");
  if (!file)
    return ERROR;

  while (fgets(line, WORD_SIZE, file)) {

    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      
#ifdef DEBUG
    printf("Leido: %ld|%s|%ld\n", id, name, location);
#endif
    }
  object = object_create(id);
      if (object) {
        object_set_name(object, name);
        game_add_object(game, object);
        space_add_object(game_get_space(game, location), id);
        game_set_object_location(game, id, location);        
        }
  }

  fclose(file);

  return status;
}