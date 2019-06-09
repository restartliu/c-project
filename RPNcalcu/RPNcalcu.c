#include"stack.h"

char* deal_with(stack_head*, stack_head*, char*);
int change_int(char*);
int count(int, int, int);

int main()
{
	char count_string[128] = {'\0'};
	stack_head *number, *signal;

	init(&number);
	init(&signal);

	scanf("%s", count_string);
	
	char *temp = count_string;
	do
	{
		temp = deal_with(number, signal, temp);
		temp++;
	}while( signal->stack_tail != NULL );

	print(number);

	return 0;
}

char* deal_with(stack_head *number, stack_head *signal, char *temp)
{
	if(*temp == '\0')
	{
		push( number, count(pop(signal), pop(number), pop(number)) );
	}
	else if( *temp == ')' && signal->stack_tail->receive != '(' )
	{
		push( number, count(pop(signal), pop(number), pop(number)) );
		temp--;
	}
	else if( *temp == ')' && signal->stack_tail->receive == '(' )
	{
		pop(signal);
	}
	else
	{
		char number_array[16] = {1,'\0'};
		while( *(temp) >=48 && *(temp) <= 57 )
		{
			number_array[number_array[0]] = *temp;
			number_array[0]++;
			temp++;
		}
		if(number_array[0] > 1)
		{
			push( number, change_int(number_array) );
		}
	
		if( (*temp=='+' || *temp=='-' || *temp=='*' || '/' ) && ((signal->stack_tail == NULL) || (signal->stack_tail->receive == '(')) )
		{
			push( signal, (int)(*temp) );
		}
		else if( *temp=='+' || *temp=='-' )
		{
			push( number, count(pop(signal), pop(number), pop(number)) );
			push( signal, (int)(*temp) );
		}
		else if( (*temp=='*' || *temp=='/') && (signal->stack_tail->receive != '*' && signal->stack_tail->receive != '/') )
		{
			push( signal, (int)(*temp) );
		}
		else if( *temp=='*' || *temp=='/' )
		{
			push( number, count(pop(signal), pop(number), pop(number)) );
			push( signal, (int)(*temp) );
		}
		else if(*temp == '(')
		{
			push( signal, (int)(*temp) );
		}
		else if(*temp == ')')
		{
			temp--;
		}
	}

	return temp;
}

int change_int(char *number_array)
{
	if( *number_array == 2 )
	{
		return (int)( *(number_array+1)-48);
	}
}

int count(int signal, int left, int right)
{
	char _signal = (char)signal;
	switch(_signal)
	{
		case '+':return (left+right);
		case '-':return (left-right);
		case '*':return (left*right);
		case '/':return (left/right);
	}
}
