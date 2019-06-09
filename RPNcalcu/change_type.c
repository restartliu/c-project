#include"change_type.h"

int strtoi(char *fch_addr)
{
	int number = 0;
	int temp = 0;

	for( ; *(fch_addr+temp) != '\0'; temp++);

	for( ; temp > 0; fch_addr++)
	{
		temp--;
		number = number + ( ((int)(*fch_addr)-48)*pow(10, temp) );
	}
	return number;
}
