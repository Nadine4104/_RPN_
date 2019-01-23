struct Stack {
    int index;
    int max_size;
    int* data;
};

typedef struct Stack Stack;


Stack* stack_init(int len);
void stack_put(Stack* stack, int arg);
int stack_get(Stack* stack);
int stack_is_empty(Stack* stack);
int stack_is_full(Stack* stack);
int stack_size(Stack* stack);
