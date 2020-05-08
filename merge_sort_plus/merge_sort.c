#include"merge_sort.h"

void merge_sort(int *args, int size)
{
    int *temp_array = (int*)malloc(size*sizeof(int));
    int *temp_array2 = (int*)malloc(size*sizeof(int));
    int *p = NULL;
    memcpy(temp_array2, args, size*sizeof(int));

    for (int i = 2; i<size || size-i/2>0; i *= 2)
    {
        sort(temp_array, temp_array2, size, i);
        p = temp_array; temp_array = temp_array2; temp_array2 = p;
    }
    memcpy(args, temp_array2, size*sizeof(int));
}

void sort(int *temp_array, int *temp_array2, int size, int n)
{
    int left1 = 0;
    int left2 = n/2;
    int temp = 0;
    
    for (int i = 0; i < size; i+=n, left1=0, left2=n/2)
    {
        while (left1 < n/2 && left2 < n && left2+i < size)
            temp_array[temp++] = temp_array2[i+left1]<temp_array2[i+left2]?temp_array2[i+left1++]:temp_array2[i+left2++];

        while (left1 < n/2 && left1+i < size)
            temp_array[temp++] = temp_array2[i+left1++];
        
        while (left2 < n && left2+i < size)
            temp_array[temp++] = temp_array2[i+left2++];
    }
}
