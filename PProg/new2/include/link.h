/**
 * @brief It defines the link interface
 *
 * @file link.h
 * @author Alberto Tarrasa
 * @version 1.0
 * @date 17-3-2023
 * @copyright GNU Public License
 */

#ifndef LINK_H
#define LINK_H

#include <types.h>

/**
 * @brief This struct stores all the information for links
 */
typedef struct _Link Link;

/**
 * @brief Max number of links a game session can store
 */
#define MAX_LINKS 200

/**
 * @brief It creates a new link, allocating memory and initializing its values
 * @author Alberto Tarrasa
 *
 * @param id the identification number for the new link
 * @return a new link, initialized
 */
Link *link_create(const Id id);

/**
 * @brief It destroys a link, freeing the allocated memory
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_destroy(Link *link);

/**
 * @brief It gets the id of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @return the id number of the link
 */
Id link_get_id(const Link *link);

/**
 * @brief It gets the name of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @return an array with the name of the link
 */
const char *link_get_name(const Link *link);

/**
 * @brief It gets the id of the space of origin of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @return the id number of the space of origin of the link
 */
Id link_get_origin(const Link *link);

/**
 * @brief It gets the id of the space of destination of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @return the id number of the space of destination of the link
 */
Id link_get_dest(const Link *link);

/**
 * @brief It gets the direction of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @return the direction of the link
 */
DIRECTION link_get_direction(const Link *link);

/**
 * @brief It gets the status of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @return the status of the link
 */
STATUS link_get_status(const Link *link);

/**
 * @brief It sets the name of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @param name an array with the new name of the link
 * @return OK if everything goes well, ERROR if not
 */
STATUS link_set_name(Link *link, const char *name);

/**
 * @brief It sets the id of the space of origin of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @param origin the id number of the space of origin of the link
 * @return OK if everything goes well, ERROR if not
 */
STATUS link_set_origin(Link *link, const Id origin);

/**
 * @brief It sets the id of the space of destination of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @param dest the id number of the space of destination of the link
 * @return OK if everything goes well, ERROR if not
 */
STATUS link_set_dest(Link *link, const Id dest);

/**
 * @brief It sets the direction of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @param dir the direction of the link
 * @return OK if everything goes well, ERROR if not
 */
STATUS link_set_direction(Link *link, const DIRECTION dir);

/**
 * @brief It sets the status of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @param st the status of the link
 * @return OK if everything goes well, ERROR if not
 */
STATUS link_set_status(Link *link, const STATUS st);

/**
 * @brief It prints the information of a link
 * @author Alberto Tarrasa
 *
 * @param link a pointer to a link
 * @return OK if everything goes well, ERROR if not
 */
STATUS link_print(const Link *link);

#endif