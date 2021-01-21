#include<stdio.h>
#include<unistd.h>
#include"stack.h"

#define MAX 100000000

typedef struct testddd
{
    void *p;
    int age;
}TEST;

void *new_test_node(void *things, int size)
{
    void *temp = malloc(size);
    memcpy(temp, things, sizeof(things));
    return temp;
}

int main(int argc, char const *argv[])
{
    char things[] = "life is a fucking movie";
    
    Stack *handle = NULL;
    for (int i = 0; i >= 0; i++)
    {
        handle = stack_init();
        stack_push(handle, &i, sizeof(i));
        free_stack(&handle);
    }

    printf("\n%d\n", handle==NULL);

    // TEST *test = NULL;
    // for (int i = 0; i>=0 ; i++)
    // {
    //     test = (TEST*)malloc(sizeof(TEST));
    //     test->age = 10;
    //     test->p = new_test_node(things, sizeof(things));
    //     //printf("%s", test->p);
    //     free(test->p);
    //     free(test);
    //     test = NULL;
    // }

    while(1);

    return 0;
}

