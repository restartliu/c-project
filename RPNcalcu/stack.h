#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STACK_BODY          //struct of circular linked list
{
	int receive;
	struct STACK_BODY *next;
	struct STACK_BODY *previous;
}stack_body;

typedef struct STACK_HEAD
{
	stack_body *stack_head;
	stack_body *stack_tail;
}stack_head;

void init(stack_head**);
void push(stack_head*, int);
int pop(stack_head*);
void print(stack_head*);
