#include "quick_sort.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>

#define MAX 100000000

int main(int argc, char *args[])
{
    srand((unsigned)time(0));
    int *number = (int*)malloc(MAX*sizeof(int));

    for(int j = 0; j < MAX; j++)
    {
        number[j] = 1+rand()%MAX;
    }

    quick_sort(number, 0, MAX);

    for(int i = 0; i < MAX; i++)
    {
        printf("%d\n", number[i]);
    }
    printf("\n");

    return 0;
}
