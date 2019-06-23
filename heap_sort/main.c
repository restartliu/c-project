#include "heap_sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *args[])
{
    srand((unsigned)time(0));
    int number[10000] = {0};

    for(int j = 0; j < 10000; j++)
    {
        number[j] = rand()%10000;
    }

    int *source = heap_sort(number, 10000);

    for(int i = 0; i < 10000; i++)
    {
        printf("%d\n", *(source+i));
    }

    return 0;
}
