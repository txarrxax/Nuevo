#include <stdio.h>
#include <stdlib.h>

#include "stack_ejs.h"

int main (int argc, char *argv[]){
    int (*f)(int, char *[]);
    // uncomment the appropiate function
    // f = main_balancedExpression;
    // f = main_decimal2base;
    // f = main_stackInvert;
    // f = main_stack_deepCopy;
    //f = main_evalPostFix;
    // f = main_string_invert;
    // f = main_reverseWords;

return f(argc, argv);
}

int main_balancedExpression (int argc, char *argv[]){
    Bool bol;
    char str[] = "( (a+b)*(c+d) )";

    bol = balancedExpression(str);
    if (bol)
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

int main_decimal2base (int argc, char *argv[]){
    char *exp = NULL;
    int number = 9;
    int base = 2;

    exp = decimal2base(number, base);

    if (exp){
        fprintf(stdout, "Number: %d, conversion: %s\n", number, exp);
        free(exp);
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}