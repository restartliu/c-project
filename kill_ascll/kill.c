#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *args[])
{
	char sign = 0;
	FILE *file1 = fopen(args[1], "r");
	FILE *file2 = fopen(args[2], "wb+");

	char ch = 0;
	while( fread(&ch, sizeof(char), 1, file1) )
	{
		if(ch == '>')
			sign = ch;

		else if(ch == '<')
			sign = 0;

		else if(ch == '&')
		{
			fread(&ch, sizeof(char), 1, file1);
			fread(&ch, sizeof(char), 1, file1);
			fread(&ch, sizeof(char), 1, file1);
			fread(&ch, sizeof(char), 1, file1);
			fread(&ch, sizeof(char), 1, file1);
			ch = '\t';
			fwrite(&ch, sizeof(char), 1, file2);
		}

		else if( ch == ' ' );

		else if( (ch < 0 || sign != 0) && ch != '<' && ch != '>')
			fwrite(&ch, sizeof(char), 1, file2);
	}

	return 0;
}
