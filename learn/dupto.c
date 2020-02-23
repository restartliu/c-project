#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = open("ps.out", O_WRONLY|O_CREAT|O_TRUNC, 0644);

	dup2(fd, STDOUT_FILENO);

	//execlp("ps", "ps", "-aux", NULL);

	printf("Hello world!");

	return 0;
}
