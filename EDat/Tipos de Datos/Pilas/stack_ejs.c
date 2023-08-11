#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_ejs.h"

/* balancedExpression determines if an expression is balenced or not */
Bool balancedExpression (char *str){
    Stack *s = NULL;
    Status st = OK;
    int i;

    /* initialize a stack */
    s = stack_new();
    if (!s) return FALSE;

    /* iterate over the expression */
    for (i=0; str[i] != '\0', st != ERROR; i++){
        /* if there is a '(' push it to the stack */
        if (str[i] == '(')
            st = stack_push(s, str[i]);
        /*if there is a ')' pop a '(' from the stack */
        else if (str[i] == ')')
            if (!stack_pop(s))
                st = ERROR;
    }

    /* check if at the end the stack is empty */
    if (st && !stack_isEmpty)
        st = ERROR;
    
    /* free the stack */
    stack_free(s);

    if (st) return TRUE;
    
    return FALSE;
}