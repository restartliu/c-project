#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Hello world!\n");

	pid_t pid = fork();

	printf("%d\n", pid);

	return 0;
}
