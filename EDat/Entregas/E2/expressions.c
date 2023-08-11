
#include "expressions.h"
#include "stack.h"
#include "types.h"
#include <ctype.h> // for isdigit()
#include <stdio.h>
#include <stdlib.h>

#define OPERATORS "+-*/%"

// is char c an operator?
Bool isOperator(char c) {
  char *oper = OPERATORS;
  char *pc;

  // exclude the char '\0' as operator
  if (c == '\0')
    return FALSE;

  // search for c in operators
  pc = strchr(oper, c);

  if (!pc)
    return FALSE;
  return TRUE;
}

// is char c an operand?
// accepts anything that is not an operator
Bool isOperand(char c) {
  Bool b;
  b = (isOperator(c) == TRUE) ? FALSE : TRUE;
  return b;
}

// is char c a digit
Bool isIntOperand(char c) { return isdigit(c) ? TRUE : FALSE; }

// evaluate expresion with operator oper
int evaluate(int arg1, int arg2, char oper) {
  int p = 0;

  switch (oper) {
  case '+':
    p = arg1 + arg2;
    break;
  case '-':
    p = arg1 - arg2;
    break;
  case '*':
    p = arg1 * arg2;
    break;
  case '/':
    p = arg1 / arg2;
    break;
  default:
    printf("Invalid operator");
  }

  return p;
}
/******************************************/

// START YOUR CODE

// return TRUE if string str has well-balanced parenthesis

Bool balancedParens(char *str){
  Stack *stack;
  char *aux;
  int i;
  Bool bool = TRUE;

  /* error checks */
  if (!str) return FALSE;

  /* create a new stack */
  stack = stack_init();
  if (!stack) return FALSE;

  /* push '(' to the stack and pops them when finding a ')' */
  for (i=0; (str[i] != '\0'); i++){
    if (str[i] == '(') if (!stack_push(stack, char_init(str[i]))){
      bool = FALSE;
      break;
    }
    if (str[i] == ')'){
      if (stack_isEmpty(stack)){
        bool = FALSE;
        break;
      }
      else{
        aux = stack_pop(stack);
        if (!aux){
          bool = FALSE;
          break;
        }
        char_free(aux);
      }
    }
  }

  /* check if the stack is empty */
  if (!stack_isEmpty(stack)) bool = FALSE;

  /* free the memory allocated */
  while (!stack_isEmpty(stack)) char_free(stack_pop(stack));
  stack_free(stack);

  return bool;
}

// evaluate the postfix expression in expr
// return OK or ERROR
// if no error, *result contains the result of evaluating the expression

Status evalPostfix(char *expr, int *result){
  Stack *stack;
  int i, j, size, *arg1, *arg2;
  int *re;
  Status st = OK;

  /* error checks */
  if (!expr || !result) return ERROR;
  
  /* create a new stack */
  stack = stack_init();
  if (!stack) return ERROR;

  /* take the number of operands*/
  for (i=0, size=0; expr[i] != '\0'; i++)
    if (isIntOperand(expr[i]))
      size++;

  /* allocate memory for the results of the operations */
  re = (int*) malloc(size*sizeof(int));
  if (!re){
    stack_free(stack);
    return ERROR;
  }

  /* make the operations in the stack */
  for (i=0, j=0, size=1; expr[i] != '\0'; i++){
    if (isOperator(expr[i]) && stack_size(stack) < 2){
      st = ERROR;
      break;
    }
    if (isOperand(expr[i]) && !isIntOperand(expr[i])){
      st = ERROR;
      break;
    }
    if (isIntOperand(expr[i])) if (!stack_push(stack, int_init(expr[i] - '0'))){
      st = ERROR;
      break;
    }
    if (isOperator(expr[i])){
      arg2 = stack_pop(stack);
      arg1 = stack_pop(stack);
      if (!arg1 || !arg2){
        st = ERROR;
        break;
      }
      re[j] = evaluate(*arg1, *arg2, expr[i]);
      if (!stack_push(stack, int_init(re[j]))){
        st = ERROR;
        break;
      }
      int_free(arg1);
      int_free(arg2);
      j++;
    }
  }

  /* check the size of the stack */
  if (stack_size(stack) != 1) st = ERROR;

  /* take the result */
  if (st) *result = *(int*)stack_top(stack);
  if (!result) st = ERROR;

  /* free the memory allocated */
  while (!stack_isEmpty(stack)) int_free(stack_pop(stack));
  stack_free(stack);
  free(re);

  return st;
}
// END CODE