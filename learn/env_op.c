#include<stdio.h>
#include<stdlib.h>

void get();
void add();
void delete();

int main()
{
	int choice = 0;
	while(1)
	{
		printf("0.exit    1.get environment    2.add environment    3.delete environment\n");
		printf("Input : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0: return 0;
			case 1: get();      break;
			case 2: add();      break;
			case 3: delete();   break;
			default: printf("Irregular input!!!\n"); break;
		}
	}

	return 0;
}

void get()
{
	char *var = NULL;
	char name[128] = {'0'};

	printf("Input name:");
	scanf("%s", name);
	
	var = getenv(name);
	printf("%s = %s\n\n", name, var);
}

void add()
{
	char name[128] = {'\0'};
	char value[256] = {'\0'};

	printf("Input name:");
	scanf("%s", name);
	printf("Input path:");
	scanf("%s", value);
	
	if( setenv(name, value, 1) == 0 )
	{
		printf("Write in success!!!\n\n");
	}
	else
	{
		printf("Write in failed!!!\n\n");
	}
}

void delete()
{
	char name[128] = {'0'};

	printf("Input name:");
	scanf("%s", name);
	
	if( unsetenv(name) == 0 )
	{
		printf("Delete success!!!\n\n");
	}
	else
	{
		printf("Delete failed!!!\n\n");
	}
}
