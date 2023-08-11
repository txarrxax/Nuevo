#ifndef SET_H
#define SET_H

#include "types.h"
#include <stdlib.h>

typedef struct _Set {
    Id *ids;
    int n_ids;
}Set;

/**
  * @brief It creates a new set with memory for one id
  * @author Miguel Angel Sacristan
  * 
  * @return a new empty set
  */
Set *set_create ();

/**
  * @brief It destroys a set
  * @author Miguel Angel Sacristan
  * 
  * @param set the set to delete
  * @return no return
  */
void set_destroy(Set *set);

/**
  * @brief It adds a new id to the set
  * @author Miguel Angel Sacristan
  * 
  * @param set the set where the id is going to be added
  * @param new_id the identification number
  * @return OK if the id was added to the set, else ERROR
  */
STATUS set_addId (Set *set, Id new_id);

/**
  * @brief It deletes an id from the set
  * @author Miguel Angel Sacristan
  * 
  * @param set the set where the id is
  * @param del_id the identification number
  * @return OK if the id was deleted from the set, else ERROR
  */
STATUS set_destroyId (Set *set, Id del_id);

/**
  * @brief It adds a deletes the last id added to the set
  * @author Miguel Angel Sacristan
  * 
  * @param set the set where the id is
  * @return OK if the last id was removed, else ERROR
  */
STATUS set_destroyLastId (Set *set);

/**
  * @brief It checks if the array of the set is full
  * @author Miguel Angel Sacristan
  * 
  * @param set the set where the array is
  * @return TRUE if the set is full, else FALSE
  */
BOOL set_isFull (Set *set);

/**
  * @brief It checks if there is an object in a set
  * @author Miguel Angel Sacristan
  * 
  * @param set the set where the id should be
  * @param id the identification number to check
  * @return TRUE if the id is in the set, else FALSE
  */
BOOL set_checkId(Set *set, Id id);

/**
  * @brief It gets the number of ids stored in a set
  * @author Miguel Angel Sacristan
  * 
  * @param set the set where the ids are
  * @return the number of ids in a set
  */
int set_getNumberOfElements(Set *set);

/**
  * @brief It prints the information of a set
  * @author Miguel Angel Sacristan
  * 
  * @param set the set to print
  * @return OK if the set was printed, else ERROR
  */
STATUS set_print (FILE *pf, Set *set);

#endif  