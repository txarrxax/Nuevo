#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

typedef struct _Node Node;

/**
 * @brief It creates and initializes a new node
 * 
 * @return a new node, initialized
*/
Node *node_new();

typedef struct _List List;

/**
 * @brief It creates and initializes a new list
 * 
 * @return a new list, initialized
*/
List *list_new();

/**
 * @brief It frees the memory allocated for a list
 * 
 * @param l a pointer to a list
 * @return no return
*/
void *list_free(List *l);

/**
 * @brief It checks if a list is empty
 * 
 * @param l a pointer to a list
 * @return TRUE if the list is empty, FALSE if not
*/
Bool list_isEmpty(const List *l);

/**
 * @brief It pushes an element to the first position of a list
 * 
 * @param l a pointer to a list
 * @param e a pointer to an element
 * @return OK if everything goes well, ERROR if not
*/
Status list_pushFront(List *l, const void *e);

/**
 * @brief It pushes an element to the last position of a list
 * 
 * @param l a pointer to a list
 * @param e a pointer to an element
 * @return OK if everything goes well, ERROR if not
*/
Status list_pushBack(List *l, const void *e);

/**
 * @brief It pops the element in the first position of a list
 * 
 * @param l a pointer to a list
 * @return the element poped from the list
*/
void *list_popFront(List *l);

/**
 * @brief It pops the element in the last position of a list
 * 
 * @param l a pointer to a list
 * @return the element poped from the list
*/
void *list_popBack(List *l);




#endif