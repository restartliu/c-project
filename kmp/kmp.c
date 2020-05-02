#include"kmp.h"

int main_kmp(char *main_str, char *pattern_str)
{
	int *next_array = (int*)calloc(sizeof(int), (strlen(pattern_str)+1));
	next(pattern_str, next_array);
	//print_next(sizeof(pattern_str), next_array);
	
	int imain = 1;
	int ipattern = 1;
	while (imain<=strlen(main_str)&&ipattern<=strlen(pattern_str))
	{
		if (ipattern==0||main_str[imain-1] == pattern_str[ipattern-1])
		{
			imain++;
			ipattern++;
		}
		else
			ipattern = next_array[ipattern];
	}

	if (ipattern>strlen(pattern_str))
		return imain-ipattern+1;

	return -1;
}

void next(char *pattern_str, int *next_array)//next_array数组从1开始
{
	int strindex = 1;
	int cmplen = 0;
	next_array[1] = 0;

	while (strindex < strlen(pattern_str))
	{
		if (cmplen==0 || pattern_str[strindex-1]==pattern_str[cmplen-1])
		{
			strindex++;
			cmplen++;

			if (pattern_str[strindex-1]!=pattern_str[cmplen-1])
               next_array[strindex]=cmplen;
            else
                next_array[strindex]=next_array[cmplen];
		}
		else
			cmplen = next_array[cmplen];
	}
}

void print_next(int number, int *next_array)
{
	for (int i = 0; i < number; i++)
	{
		printf("%d   ", next_array[i] );
	}
	printf("\n");
}
