#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

typedef struct _Stack Stack;

/**
  * @brief It creates and initializes a new stack
  * 
  * @return a new stack, initialized
  */
Stack *stack_new();

/**
  * @brief It frees the memory allocated for the stack
  * 
  * @param s a pointer to the stack
  * @return no return
  */
void stack_free (Stack *s);

/**
  * @brief It checks whether the stack is empty or not
  * 
  * @param s a pointer to the satck
  * @return TRUE if the stack is empty, FALSE if not
  */
Bool stack_isEmpty (const Stack *s);

/**
  * @brief It introduces a new element to the stack
  * 
  * @param s a pointer to the stack
  * @param e a pointer to the new element
  * @return OK if everything goes well, ERROR if there was some mistake
  */
Status stack_push (Stack *s, const void *e);

/**
  * @brief It extracts the last element of the stack
  * 
  * @param s a pointer to the stack
  * @return no return
  */
void *stack_pop (Stack *s);

/**
  * @brief It takes the last element of the stack without removing it
  * 
  * @param s a pointer to the stack
  * @return no return
  */
void *stack_top (const Stack *s);

/**
  * @brief It takes the size of the stack
  * 
  * @param s a pointer to the stack
  * @return the size of the stack
  */
int stack_size (const Stack *s);

/**
  * @brief It prints the information of the stack
  * 
  * @param pf a pointer to a file
  * @param s a pointer to the stack
  * @param 
  * @return no return
  */
int stack_print (FILE *pf, const Stack *s, int(*ele_print)(FILE *, void *));

#endif