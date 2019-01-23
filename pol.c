#include <stdio.h>
#include <string.h>

#include "stack.h"

#define MAXNUM 100
#define DEL ' '

int parse_op(Stack* stack, char op, char real_op, int argc){
  
  if (op==real_op){
    if (stack_size(stack)>=argc) return 1; //Success!
    printf("Parsing error: Not enough arguments in stack!\n");
  }
  return 0;//Not Sucess...
}


int main(int argc, char* args[]) {
  char* equation; 
  int i; 
  int acc = 0; 
  int acc_empty = 1; 
  if (argc>=2){ 
    equation = args[1];
  }
  else{
     printf("[USAGE]:\n\t./pol \"equation\"\n");
     printf("\tSeparate int operands and operations by space, allowed operations: +,-,*.\n");
     return 0;
  }

  Stack* stack = stack_init(strlen(equation)); 
  
  for (i=0; i<strlen(equation); i++){ 
    char c = equation[i];
    if ((c>='0') && (c<='9')){ 
      if (acc_empty){ 
        acc_empty = 0; 
        acc = c - '0'; 
      }
      else{ 
        acc = acc * 10 + c - '0';
      }
    }
    if (c==DEL){ 
      if(!acc_empty){ 
        if (stack_is_full(stack))
        {
          printf("Stack overflow!\n");
          return 0;
        }
	if (acc>MAXNUM){ 
	  printf("Arguments must not be greater than %d!\n", MAXNUM);	
	  return 0;
	}
        stack_put(stack, acc); 
        acc = 0;
        acc_empty = 1;
        
      }
    }
    if (parse_op(stack, c, '+', 2)){ 
      int a = stack_get(stack);
      int b = stack_get(stack);
      stack_put(stack, a+b);
    }
    if (parse_op(stack, c, '*', 2)){
      int a = stack_get(stack);
      int b = stack_get(stack);
      stack_put(stack, a*b);
    }
    if (parse_op(stack, c, '-', 2)){
      int a = stack_get(stack);
      int b = stack_get(stack);
      stack_put(stack, b - a);
    }
  }
  if ((!acc_empty) || (stack_size(stack)>1)){
    printf("Incorrect Equation, unused values left in a stack!\n");
    return 0;
  }
  if (!stack_is_empty(stack)){
    printf("Result of Equation \"%s\" is %d\n", equation, stack_get(stack));
    return 0;
  }

  printf("Incorrect Equation, Stack is empty.\n");
  return 0;
}
