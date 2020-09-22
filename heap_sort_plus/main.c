#include "heap_sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 100000000

int main(int argc, char *args[])
{
    srand((unsigned)time(0));
    int *number = (int*)malloc(MAX*sizeof(int));

    for(int j = 0; j < MAX; j++)
    {
        number[j] = 1+rand()%MAX;
        //printf("%d ", number[j]);
    }

    heap_sort(number, MAX);

    printf("\n");

    for(int i = 0; i < MAX; i++)
    {
        printf("%d \n", number[i]);
    }

    return 0;
}
