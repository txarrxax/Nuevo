#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

typedef struct _Queue Queue;

/**
  * @brief It creates and initializes a new queue
  * 
  * @return a new queue, initialized
  */
Queue *queue_new();

/**
  * @brief It frees the memory allocated for the queue
  * 
  * @param q a pointer to the queue
  * @return no return
  */
void queue_free (Queue *q);

/**
  * @brief It checks whether the queue is empty or not
  * 
  * @param q a pointer to the queue
  * @return TRUE if the queue is empty, FALSE if not
  */
Bool queue_isEmpty (const Queue *q);

/**
  * @brief It introduces a new element to the queue
  * 
  * @param q a pointer to the queue
  * @param e a pointer to the new element
  * @return OK if everything goes well, ERROR if there was some mistake
  */
Status queue_push (Queue *q, const void *e);

/**
  * @brief It extracts the last element of the queue
  * 
  * @param q a pointer to the queue
  * @return no return
  */
void *queue_pop (Queue *q);

/**
  * @brief It takes the first element of the queue without removing it
  * 
  * @param q a pointer to the queue
  * @return no return
  */
void *queue_getFront (const Queue *q);

/**
  * @brief It takes the last element of the queue without removing it
  * 
  * @param q a pointer to the queue
  * @return no return
  */
void *queue_getBack (const Queue *q);

#endif