#include"stack.h"

STACKINFO* stackinit()
{
	STACKINFO* temp = (STACKINFO*)malloc(sizeof(STACKINFO));
	temp->head = NULL;
	return temp;
}

void push(STACKINFO *stackhead, double receive)
{
	STACK* temp = (STACK*)malloc(sizeof(STACK));
	temp->receive = receive;
	temp->next = stackhead->head;
	stackhead->head = temp;
}

double pop(STACKINFO *stackhead)
{
	double temp = stackhead->head->receive;
	stackhead->head = stackhead->head->next;
	return temp;
}

STACK* reverse(STACK* headnode, STACK* newnode)
{
	if (!headnode)
		return newnode;

	STACK* temp = headnode->next;
	headnode->next = newnode;
	return reverse(temp, headnode);
}

void printTest(STACKINFO* headnode)
{
	STACK* temp = headnode->head;
	while (temp)
	{
		printf("%c\n", (char)temp->receive);
		temp = temp->next;
	}
}