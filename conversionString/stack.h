#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack          //linked list
{
	 double receive;
	 struct stack* next;
}STACK;

typedef struct stackInfo
{
	STACK* head;
}STACKINFO;

STACKINFO* stackinit();
void push(STACKINFO*, double);
double pop(STACKINFO*);
STACK* reverse(STACK*, STACK*);
void printTest(STACKINFO* headnode);