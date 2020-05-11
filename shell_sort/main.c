#include "shell_sort.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>

#define MAX 1000000

int main(int argc, char *args[])
{
    srand((unsigned)time(0));
    int number[MAX] = {'\0'};

    for(int j = 0; j < MAX; j++)
    {
        number[j] = 1+rand()%MAX;
    }

    shell_sort(number, MAX);

    /*for(int i = 0; i < MAX; i++)
    {
        printf("%d ", number[i]);
    }
    printf("\n");*/

    return 0;
}
