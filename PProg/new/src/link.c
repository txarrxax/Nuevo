/**
 * @brief It implements the link module
 *
 * @file link.c
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 17-3-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <link.h>

/**
 * @brief Link
 *
 * This struct stores all the information of a link.
 */
struct _Link {
  Id        id;                  /*!< Id number of the link, unique */
  char      name[WORD_SIZE + 1]; /*!< Name of the link */
  Id        origin;              /*!< Id of the space of origin */
  Id        dest;                /*!< Id of the space of destination */
  DIRECTION dir;                 /*!< Direction of the link */
  STATUS    status;              /*!< State of the link (open or close)*/
};

/* link_create creates a new link, allocating memory and initializing its values
 */
Link *link_create(const Id id) {
  Link *link = NULL;
  /* error checks */
  if (id == NO_ID) return NULL;

  /* allocata memory */
  link = (Link *)malloc(sizeof(Link));
  if (!link) return NULL;

  /* set initial values */
  strcpy(link->name, "");
  link->origin = NO_ID;
  link->dest   = NO_ID;
  link->dir    = U;
  link->status = ERROR;
  link->id     = id;

  return link;
}

/* link_destroy destroys a link, freeing the allocated memory */
STATUS link_destroy(Link *link) {
  /* error checks */
  if (!link) return ERROR;

  /* free the allocated memory */
  free(link);
  return OK;
}

/* link_get_id gets the id of a link */
Id link_get_id(const Link *link) {
  /* error checks */
  if (!link) return NO_ID;

  return link->id;
}

/* link_get_name gets the name of a link */
const char *link_get_name(const Link *link) {
  /* error checks */
  if (!link) return NULL;

  return link->name;
}

/* link_get_origin gets the id of the space of origin of a link */
Id link_get_origin(const Link *link) {
  /* error checks */
  if (!link) return NO_ID;

  return link->origin;
}

/* link_get_dest gets the id of the space of destination of a link */
Id link_get_dest(const Link *link) {
  /* error checks */
  if (!link) return NO_ID;

  return link->dest;
}

/* link_get_direction gets the direction of a link */
DIRECTION link_get_direction(const Link *link) {
  /* error checks */
  if (!link) return U;

  return link->dir;
}

/* link_get_status gets the status of a link */
STATUS link_get_status(const Link *link) {
  /* error checks */
  if (!link) return ERROR;

  return link->status;
}

/* link_set_name sets the name of a link */
STATUS link_set_name(Link *link, const char *name) {
  /* error checks */
  if (!link || !name) return ERROR;

  /* set the name */
  strcpy(link->name, name);
  return OK;
}

/* link_set_origin sets the id of the space of origin of a link */
STATUS link_set_origin(Link *link, const Id origin) {
  /* error checks */
  if (!link || origin == NO_ID) return ERROR;

  /* set the id of origin */
  link->origin = origin;
  return OK;
}

/* link_set_dest sets the id of the space of destination of a link */
STATUS link_set_dest(Link *link, const Id dest) {
  /* error checks */
  if (!link || !dest) return ERROR;

  /* set the id of destination */
  link->dest = dest;
  return OK;
}

/* link_set_direction sets the direction of a link */
STATUS link_set_direction(Link *link, const DIRECTION dir) {
  /* error checks */
  if (!link || dir == X) return ERROR;

  /* set the direction */
  link->dir = dir;
  return OK;
}

/* link_set_status sets the status of a link */
STATUS link_set_status(Link *link, const STATUS st) {
  /* error checks */
  if (!link) return ERROR;

  /* set the status */
  link->status = st;
  return OK;
}

/* link_print prints the information of a link */
STATUS link_print(const Link *link) {
  Id idaux = NO_ID;
  /* error checks */
  if (!link) return ERROR;

  /* 1. Print the id and the name of the link */
  fprintf(stdout, "--> Link (Id: %ld; Name: %s)\n", link->id, link->name);

  /* 2. Print the origin and destination spaces */
  idaux = link_get_origin(link);
  if (idaux != NO_ID) fprintf(stdout, "---> Space of origin: %ld\n", idaux);
  idaux = link_get_dest(link);
  if (idaux != NO_ID) fprintf(stdout, "---> Space of destination: %ld\n", idaux);

  /*3. Print the direction and status of the link */
  fprintf(stdout, "---> Direction: %d\n", link->dir);
  fprintf(stdout, "---> Status: %d\n", link->status);

  return OK;
}
