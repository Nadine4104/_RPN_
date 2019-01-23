#include <stdio.h>
#include <malloc.h>

#include "stack.h"

Stack* stack_init(int len) {
    Stack* stack = malloc(sizeof(Stack)); //Getting memory for stack metadata...
    stack->index = 0;
    stack->max_size = len;
    stack->data = calloc(len, sizeof(int)); //Getting memory for stack data
    return stack;
}

void stack_put(Stack* stack, int arg){
    if (!stack_is_full(stack)){
      stack->data[stack->index] = arg;
      stack->index = stack->index+1;
    }
}

int stack_get(Stack* stack){
    int ret = 0;
    if (!stack_is_empty(stack)){ 
      stack->index = stack->index-1; 
      ret = stack->data[stack->index];
    }
    return ret; 
}

int stack_is_empty(Stack* stack){
    return stack->index <= 0;
}

int stack_is_full(Stack* stack){
    return stack->index >= stack->max_size;
}

int stack_size(Stack* stack){
    return stack->index;
}
