#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<unistd.h>

typedef struct stack Stack;

struct stack
{
    int    type_size;
    void  *value;
    Stack *next;
};

Stack *stack_init();
void   stack_push(Stack *handle, void *value, int type_size);
void  *stack_pop(Stack *handle);
void   print_stack(Stack *handle);
void   free_stack(Stack **handle);