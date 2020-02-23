#include "heap_sort.h"

void swap(int*, int*);
void sort(int*, int, int);

int* heap_sort(int* temp, int size)
{
	int heap_size = size-1;
	int *ret = (int*)malloc(size*sizeof(int));

	memcpy(ret, temp, size*sizeof(int));

	for(int n = heap_size/2; n >= 0; n--)
		sort(ret, n, size);

	for(int i = 0; i <= size-2; i++, heap_size--)
	{
		sort(ret, 0, heap_size);
		swap(ret, ret+heap_size);
	}

	return ret;
}

void sort(int *ret, int n, int size)
{
	int left = n*2+1;
	int right = n*2+2;
	int largest = n;

	if( left <= size && *(ret+largest) <= *(ret+left) )
			largest = left;
	if( right <= size && *(ret+largest) <= *(ret+right) )
			largest = right;
	
	if(largest != n)
	{
		swap(ret+largest, ret+n);
		sort(ret, largest, size);
	}
}

void swap(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
