/** 
 * @brief It implements the space module
 * 
 * @file space.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "space.h"


/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space {
  Id id;                      /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1];   /*!< Name of the space */
  Id north;                   /*!< Id of the space at the north */
  Id south;                   /*!< Id of the space at the south */
  Id east;                    /*!< Id of the space at the east */
  Id west;                    /*!< Id of the space at the west */
  Set *objects;               /*!< Set with the objects in the space*/
  char gdesc[HEIGHT][LENGTH]; /*!< Array including the graphic description of the space*/
};

/** space_create allocates memory for a new space
  *  and initializes its members
  */
Space* space_create(Id id) {
  Space *newSpace = NULL;
  int i;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *) malloc(sizeof (Space));
  if (!newSpace)
    return NULL;

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;
  newSpace->objects = set_create();
  if (!newSpace->objects) 
    return NULL;
  for (i=0; i<HEIGHT; i++)
    strcpy(newSpace->gdesc[i], "");

  return newSpace;
}

/** space_destroy frees the previous memory allocation 
  *  for a space
  */
STATUS space_destroy(Space* space) {
  if (!space)
    return ERROR;

  set_destroy(space->objects);

  free(space);
  return OK;
}

/** It sets the name of a space
  */
STATUS space_set_name(Space* space, char* name) {
  if (!space || !name)
    return ERROR;

  if (!strcpy(space->name, name))
    return ERROR;

  return OK;
}

/** It sets the id of the space located at the north
  */
STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID)
    return ERROR;

  space->north = id;
  return OK;
}

/** It sets the id of the space located at the south
  */
STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID)
    return ERROR;

  space->south = id;
  return OK;
}

/** It sets the id of the space located at the east
  */
STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID)
    return ERROR;

  space->east = id;
  return OK;
}

/** It sets the id of the space located at the west
  */
STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID)
    return ERROR;

  space->west = id;
  return OK;
}


/** It gets the name of a space
  */
const char * space_get_name(Space* space) {
  if (!space)
    return NULL;

  return space->name;
}

/** It gets the id of the space located at the north
  */
Id space_get_north(Space* space) {
  if (!space)
    return NO_ID;

  return space->north;
}

/** It gets the id of the space located at the south
  */
Id space_get_south(Space* space) {
  if (!space)
    return NO_ID;

  return space->south;
}

/** It gets the id of the space located at the east
  */
Id space_get_east(Space* space) {
  if (!space)
    return NO_ID;

  return space->east;
}

/** It gets the id of the space located at the west
  */
Id space_get_west(Space* space) {
  if (!space)
    return NO_ID;

  return space->west;
}

/** It gets the id of a space
  */
Id space_get_id(Space* space) {
  if (!space)
    return NO_ID;

  return space->id;
}

/** It adds a new object to the space
  */
STATUS space_add_object(Space* space, Id id) {
  if (!space || id == NO_ID)
    return ERROR;
  return set_addId(space->objects, id);
}

/** It deletes an object from a space
 */
STATUS space_destroy_object(Space *space, Id object) {
  if (!space || object == NO_ID) 
    return ERROR;
  return set_destroyId(space->objects, object);
}

/* It gets the number of objects in a space
 */
int space_get_numberOfObjects(Space *space) {
  if (!space)
    return -1;
  return set_getNumberOfElements(space->objects);
}

/** It gets the objects of a space
  */
Set *space_get_objects(Space* space) {
  if (!space)
    return NULL;

  return space->objects;
}

/** It checks if an object is in a space
 */
BOOL space_checkObject (Space *space, Id id) {
  if (!space || !id)
    return FALSE;
  return set_checkId(space->objects, id);
}

/** It sets a graphic description to a space
*/
STATUS space_set_gDesc (Space *space, char *desc){
  int i;
  /* error checks */
  if (!space || !desc)
    return ERROR;

for (i=0; i<HEIGHT; i++){
  if (strcmp(space->gdesc[i], "") == 0){
    strcpy(space->gdesc[i], desc);
    break;
  }
}

  return OK;
}

/** It gets the graphic description of a space
*/
char **space_get_gDesc (Space *space){
  char **desc;
  int i;
  /* errorc checks */
  if (!space)
    return NULL;

  desc = (char**)malloc(HEIGHT*sizeof(char**));
  if (!desc) return NULL;
  for (i=0; i<HEIGHT; i++){
    desc[i] = (char*)malloc(LENGTH*sizeof(char*));
    strcpy(desc[i], space->gdesc[i]);
  }
    
  
  return desc;
}

/** It prints the space information
  */
STATUS space_print(Space* space) {
  Id idaux = NO_ID;
  int i;
  char **desc;

  desc = (char**)malloc(HEIGHT*sizeof(char*));
  for (i=0; i<HEIGHT; i++)
    desc[i] = (char*)malloc(LENGTH*sizeof(char));

  /* Error Control */
  if (!space)
    return ERROR;

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
 
  /* 2. For each direction, print its link */ 
  idaux = space_get_north(space);
  if (NO_ID != idaux)
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  else
    fprintf(stdout, "---> No north link.\n");

  idaux = space_get_south(space);
  if (NO_ID != idaux)
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  else
    fprintf(stdout, "---> No south link.\n");

  idaux = space_get_east(space);
  if (NO_ID != idaux)
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  else
    fprintf(stdout, "---> No east link.\n");

  idaux = space_get_west(space);
  if (NO_ID != idaux)
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  else
    fprintf(stdout, "---> No west link.\n");

  /* 3. Print if there is an object in the space or not */
  if ((set_getNumberOfElements(space->objects))==0)
    fprintf(stdout, "---> No objects in the space.\n");
  else {
    fprintf(stdout, "---> Objects in the space: ");
    set_print(stdout, space->objects);
    fprintf(stdout, "\n");
  }

  desc = space_get_gDesc(space);
  if (!desc)
    fprintf(stdout, "---> No graphic description.\n");
  else{
    for (i=0; i<HEIGHT; i++)
      fprintf(stdout, "%9s\n", desc[i]);
  }

  for (i=0; i<HEIGHT; i++)
    free(desc[i]);
  free(desc);
  
  return OK;
}