#include "heap_sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 50

int main(int argc, char *args[])
{
    srand((unsigned)time(0));
    int number[MAX] = {'\0'};

    for(int j = 0; j < MAX; j++)
    {
        number[j] = 1+rand()%MAX;
    }

    heap_sort(number, MAX);

    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", number[i]);
    }
    printf("\n");

    return 0;
}