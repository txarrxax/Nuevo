#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack.h"

int addBinary (char *strin){
    int i, sum=0, *elem;
    Stack *s = NULL;
    Status st = OK;

    /*check arguments*/
    if (!strin) return -1;

    /*create a new stack*/
    s = stack_new();
    if (!s) return -1;

    /*iterate over the char of the string*/
    for (i=0; i<strlen(strin) && st == OK; i++){
        if (strin[i] == '0' || strin[i] == '1' || strin[i] == '+')
            st = stack_push(s, strin[i]);
        else st = ERROR;
    }

    /*convert binary to decimal and add*/
    i=0;
    while (!stack_isEmpty(s) && st == OK){
        elem = stack_pop(s) - '0';
        if (elem == 1 || elem == 0){
            sum += (*elem)*pow(2, i);
            i++;
        }
        else if (elem == '+'-'0' && stack_isEmpty(s))
            st = ERROR;
        else if (elem == '+'-'0')
            i=0;
        else
            st = ERROR;
    }

    /*check results*/
    if (!stack_isEmpty(s)){
        while(!stack_isEmpty(s))
            stack_pop(s);
        st = ERROR;
    }

    stack_free(s);
    if (st == OK) return sum;
    else return -1;
}

int main(){
    char str[64] = {"101+1100+1"};

    printf("%d", addBinary(str));

    return 0;
}