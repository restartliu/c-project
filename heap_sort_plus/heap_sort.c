#include"heap_sort.h"

void heap_sort(int *number, int size)
{
    int heap_size = size-1;

    for (int i = size/2-1; i >= 0; i--)
        modify_heap(number, i, size);

    while (heap_size)
    {
        swap(&number[0], &number[heap_size]);
        modify_heap(number, 0, heap_size--);
    }
}

void modify_heap(int *number, int count, int size)
{
    int left = count*2+1;
    int right = count*2+2;
    int smaller_index = count;
    
    if ( left<size && (smaller_index = number[left]<number[count]?left:count) );
    if ( right<size && (smaller_index = number[right]<number[smaller_index]?right:smaller_index) );
    if ( count!=smaller_index?swap(&number[count], &number[smaller_index]):0 )
        modify_heap(number, smaller_index, size);
}

int swap(int *left, int *right)
{
    int p = *left;
    *left = *right;
    *right = p;
    return 1;
}
