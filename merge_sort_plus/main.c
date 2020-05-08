#include "merge_sort.h"
#include <stdio.h>
#include <time.h>

#define MAX 100

int main(int argc, char *args[])
{
    srand((unsigned)time(0));
    int number[MAX] = {'\0'};

    for(int j = 0; j < MAX; j++)
    {
        number[j] = 1+rand()%MAX;
        printf("%d ", number[j]);
    }

    merge_sort(number, MAX);

    printf("\n");

    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", number[i]);
    }

    return 0;
}