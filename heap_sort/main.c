#include "heap_sort.h"
#include <stdio.h>

int main(int argc, char *args[])
{
    int number[30] = {9,3,0,4,1,2,5,6,8,7,3,15,18,10,16,14,13,12,17,11,29,24,28,21,25,27,26,23,22,20};

    int *source = heap_sort(number, 30);

    for(int i = 0; i < 30; i++)
    {
        printf("%d\n", *(source+i));
    }

    return 0;
}
