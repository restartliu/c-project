#include"stack.h"

void init(stack_head **head)
{
	(*head) = (stack_head*)malloc(sizeof(stack_head));
	(*head)->stack_head = NULL;
	(*head)->stack_tail = NULL;
}

void push(stack_head *head, int receive)
{
	if(head->stack_head == NULL)
	{
		head->stack_head = (stack_body*)malloc(sizeof(stack_body));
		head->stack_tail = head->stack_head;
		head->stack_head->receive = receive;
		head->stack_head->next = NULL;
		head->stack_head->previous = head->stack_tail;
	}
	else
	{
		head->stack_tail->next = (stack_body*)malloc(sizeof(stack_body));
		head->stack_tail->next->receive = receive;
		head->stack_tail->next->next = NULL;
		head->stack_tail->next->previous = head->stack_tail;
		head->stack_tail = head->stack_tail->next;
	}
}

int pop(stack_head *head)
{
	int value;

	if(head->stack_tail == NULL)
	{
		return 0;
	}
	else if(head->stack_tail == head->stack_head)
	{
		value = head->stack_tail->receive;
		head->stack_head = NULL;
		head->stack_tail = NULL;
		return value;
	}
	else
	{
		value = head->stack_tail->receive;
		head->stack_tail = head->stack_tail->previous;
		head->stack_tail->next = NULL;
		return value;
	}
}

void print(stack_head *head)
{
	stack_body *temp = head->stack_head;
	while(temp != NULL)
	{
		printf("%d   ", temp->receive);

		temp = temp->next;
	}
	printf("\n");
}
