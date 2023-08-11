/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Diego Fernández
 * @author Álvaro Grande
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <space.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space {
  Id    id;                      /*!< Id number of the space, unique */
  char  name[WORD_SIZE];         /*!< Name of the space */
  Set  *objects;                 /*!< Set of all objects in the room */
  char *gdesc[G_SLOTS];          /*!< Field for the descriptions of the space */
  char  description[WORD_SIZE];  /*!< Description of the space */
  BOOL  light;                   /*!< Illumination status of the space */
  char  ldescription[WORD_SIZE]; /*!< Field for the long description of the space */
};

/** space_create allocates memory for a new space
 *  and initializes its members
 */
Space *space_create(const Id id) {
  Space *new_space;
  int    i = 0;

  /* Error control */
  if (id == NO_ID) return NULL;

  if (!(new_space = malloc(sizeof(Space)))) return NULL;

  /* Initialization of an empty space*/
  if (!(new_space->objects = set_create())) {
    free(new_space);
    return NULL;
  }

  new_space->id              = id;
  new_space->name[0]         = '\0';
  new_space->description[0]  = '\0';
  new_space->light           = TRUE;
  new_space->ldescription[0] = '\0';

  for (i = 0; i < G_SLOTS; i++) {
    if (!(new_space->gdesc[i] = malloc(G_LENGTH * sizeof(char)))) {
      space_destroy(new_space);
      return NULL;
    }
    strcpy(new_space->gdesc[i], "        0");
  }

  return new_space;
}

/** space_destroy frees the previous memory allocation for a space
 */
STATUS space_destroy(Space *space) {
  int i = 0;
  if (!space) {
    return ERROR;
  }

  if (space->objects != NULL) set_destroy(space->objects);

  for (; i < G_SLOTS && space->gdesc[i] != NULL; i++) {
    free(space->gdesc[i]);
  }

  free(space);
  return OK;
}

/** It gets the id of a space
 */
Id space_get_id(const Space *space) {
  if (!space) return NO_ID;

  return space->id;
}

/** It sets the name of a space
 */
STATUS space_set_name(Space *space, const char *name) {
  if (!space || !name) return ERROR;

  if (!strcpy(space->name, name)) return ERROR;

  return OK;
}
/** It gets the name of a space
 */
const char *space_get_name(const Space *space) {
  if (!space) return NULL;

  return space->name;
}

/** space_add_object adds an object to the space
 */
STATUS space_add_object(Space *space, const Id obj_id) {
  if (!space) return ERROR;

  if (set_add(space->objects, obj_id) == ERROR) return ERROR;

  return OK;
}

/** space_del_object removes an object from a space
 */
STATUS space_del_object(Space *space, const Id obj_id) {
  if (!space) return ERROR;

  if (set_del(space->objects, obj_id) == ERROR) return ERROR;

  return OK;
}

/** space_has_object checks whether an object is in a given space or not
 */
BOOL space_has_object(const Space *space, const Id obj_id) {
  if (!space) return FALSE;

  return set_has_id(space->objects, obj_id);
}

/** space_set_gdesc sets the graphic description of a space
 */
STATUS space_set_gdesc(Space *space, char desc[G_SLOTS][WORD_SIZE]) {
  int i;

  /*Error control*/
  if (!space) return ERROR;

  for (i = 0; i < G_SLOTS; i++) {
    if (strlen(desc[i]) >= G_LENGTH) desc[i][G_LENGTH - 1] = '\0';
    strcpy(space->gdesc[i], desc[i]);
  }

  return OK;
}

/** space_get_gdesc gets the graphic description of a space
 */
const char **space_get_gdesc(const Space *space) {
  if (!space) return NULL;

  return (const char **)space->gdesc;
}

/** space_set_description sets the description of a space
 */
STATUS space_set_description(Space *space, char *description) {
  if (!space || !description) return ERROR;
  strcpy(space->description, description);
  return OK;
}

/** space_get_description gets the description of a space
 */
const char *space_get_description(const Space *space) {
  if (!space) return NULL;
  return space->description;
}

/** space_set_light sets the illumination status of a space
 */
STATUS space_set_light(Space *space, BOOL light) {
  if (!space || light < 0 || light > 1) return ERROR;
  space->light = light;
  return OK;
}

/** space_get_light gets the illumination status of a space
 */
BOOL space_get_light(const Space *space) {
  if (!space) return FALSE;
  return space->light;
}

STATUS space_set_ldescription(Space *space, char *new_ldes) {
  if (!space || !new_ldes) return ERROR;
  strcpy(space->ldescription, new_ldes);
  return OK;
}

const char *space_get_ldescription(const Space *space) {
  if (!space) return NULL;
  return space->ldescription;
}

/** It prints the space information
 */
STATUS space_print(Space *space) {
  const char **desc;
  int          i;

  /* Error Control */
  if (!space) return ERROR;

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  /* 2. Print the light of the space */
  if (space->light == TRUE) {
    fprintf(stdout, "Light: ON\n");
  } else {
    fprintf(stdout, "Light: OFF\n");
  }

  /* 3. Print the descriptions of the space */
  fprintf(stdout, "Short description: %s\n", space->description);
  fprintf(stdout, "Long description: %s\n", space->ldescription);

  /* 4. Print object set*/
  set_print(space->objects);

  /* 5. Print the graphic description of the space*/
  desc = space_get_gdesc(space);
  for (i = 0; i < G_SLOTS; i++) {
    fprintf(stdout, "%s\n", desc[i]);
  }

  return OK;
}
