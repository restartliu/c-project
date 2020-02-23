#include "merge_sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 1000000

int main(int argc, char *args[])
{
    srand((unsigned)time(0));
    int number[MAX] = {3,5,4,17,7,2,10,8,16,1,6,32,9,14,13};

    for(int j = 0; j < MAX; j++)
    {
        number[j] = 1+rand()%MAX;
    }

    int *source = merge_sort(number, MAX);

    for(int i = 0; i < MAX; i++)
    {
        printf("%d\n", *(source+i));
    }

    return 0;
}
