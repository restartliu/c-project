#include "merge_sort.h"

void sort(int*, int*, int, int);

int* merge_sort(int *arr, int size)
{
	int *temp = (int*)malloc(size*sizeof(int));
	int *ret = (int*)malloc(size*sizeof(int));
	int *p = NULL;

	memcpy(ret, arr, size*sizeof(int));

	for(int i = 1; i < size; i *= 2)
	{
		sort(ret, temp, size, i);

		p = ret; ret = temp; temp = p;
	}

	return ret;
}

void sort(int *ret, int *temp, int size, int n)
{
	int left1 = 0;
	int left2 = 0;
	int right = size+1;

	for(int i = 0; i < size; i += 2*n, left1 = 0, left2 = 0, right = size+1)
	{
		if( i+n < size && i+2*n > size )
			right = size - (i+n);
		else if(i+n >= size)
			continue;

		while( !(left1 == n || left2 == n || left2 == right) )
		{
			if( *(ret+i+left1) <= *(ret+i+n+left2) )
				*(temp++) = *(ret+i+(left1++));
			else
				*(temp++) = *(ret+i+n+(left2++));
		}
		
		while( left1 != n )
			*(temp++) = *(ret+i+(left1++));
	
		while( left2 != n && left2 != right )
			*(temp++) = *(ret+i+n+(left2++));
	}
}
