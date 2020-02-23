#include "heap_sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100000

int main(int argc, char *args[])
{
    srand((unsigned)time(0));
    int number[MAX] = {0};

    for(int j = 0; j < MAX; j++)
    {
        number[j] = rand()%MAX;
    }

    int *source = heap_sort(number, MAX);

    for(int i = 0; i < MAX; i++)
    {
        printf("%d\n", *(source+i));
    }

    return 0;
}
