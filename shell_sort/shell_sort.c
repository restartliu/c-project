#include"shell_sort.h"

void shell_sort(int *number, int size)
{
    for (int i = size/2; i >= 1; i /= 2)
        for (int j = 0; j+i < size; j++)
            if(number[j]>number[j+i])
                sort(number, j, i);
}

void sort(int *number, int mid, int length)
{
    if(number[mid]>number[mid+length])
    {
        swap(&number[mid], &number[mid+length]);
        if (mid-length>=0)
            sort(number, mid-length, length);
    }
}

void swap(int *first, int *second)
{
    int p = *first;
    *first = *second;
    *second = p;
}
