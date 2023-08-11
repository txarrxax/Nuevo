#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define MAX_STACK 8

struct _Stack{
    void *data[MAX_STACK];
    int top;
};

/*<-------------------------------------------------->*/
/* PRIVATE FUNCTIONS */
/* _stack_isFull checks whether the stack is full or not */
Bool _stack_isFull (const Stack *s){
    if (!s) return TRUE;
    if (s->top == MAX_STACK-1) return TRUE;

    return FALSE;
}
/*<-------------------------------------------------->*/

/* stack_new creates and initializes a new stack */
Stack *stack_new(){
    Stack *s = NULL;
    int i;

    s = (Stack *) malloc(sizeof(Stack));
    if (!s) return NULL;
    
    for (i=0; i<MAX_STACK; i++)
        s->data[i] = NULL;

    s->top = -1;
    return s;
}

/* stack_free frees the memory allocated for the stack */
void stack_free (Stack *s){
    free(s);
}

/* stack_isEmpty checks whether the stack is empty or not */
Bool stack_isEmpty (const Stack *s){
    if (!s) return TRUE;
    if (s->top == -1) return TRUE;
    
    return FALSE;
}

/* stack_push introduces a new element to the satck */
Status stack_push (Stack *s, const void *e){
    if (!s || !e || _stack_isFull(s)) return ERROR;

    s->top++;
    s->data[s->top] = e;
    return OK;
}

/* stack_pop extracts the last elementof the stack */
void *stack_pop (Stack *s){
    void *e = NULL;

    if (!s || stack_isEmpty(s)) return NULL;

    e = s->data[s->top];
    s->data[s->top] = NULL;
    s->top--;

    return e;
}

/* stack_top takes the last element of the stack without removing it */
void *stack_top (const Stack *s){
    if (!s || stack_isEmpty(s)) return NULL;

    return s->data[s->top];
}

/* stack_size takes the size of the stack */
int stack_size (const Stack *s){
    return s->top + 1;
}

/* stack_print prints the information of the stack */
int stack_print (FILE *pf, const Stack *s, int(*ele_print)(FILE *, void *));
