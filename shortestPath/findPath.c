#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	float col = 0;
	int total = 0;
	int *array = NULL;

	printf("Input the column of triangle: ");
	scanf("%f", &col);
	total = (int)((col+1)*(col/2));
	array = (int*)malloc( total*sizeof(int) );
	
	printf("Input numbers in order and end up with '0': \n");
	for(int ax = 0; ax < total; ax++)
		scanf("%d\n", (array+ax));
	
	printf("Finish!\n");

	int index = total-1;
	for(int ax = (int)col; ax > 0; ax--)
	{
		for(int bx = 0; bx < ax-1; bx++)
		{
			*(array+index-ax-bx) = *(array+index-bx) > *(array+index-bx-1) ? *(array+index-bx)+*(array+index-ax-bx) : *(array+index-bx-1)+*(array+index-ax-bx);
		}
		index -= ax;
	}
	printf("%d\n", *array);
	
	return 0;
}
