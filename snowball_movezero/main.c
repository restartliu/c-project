#include"snowball.h"
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int number[] = {1,2,0,3,0,4,5,0,6,0,7,8,0,9};
    snowball(number, sizeof(number)/sizeof(number[0]));
    for (int i = 0; i < sizeof(number)/sizeof(number[0]); i++)
    {
        printf("%d ", number[i]);
    }
    
    return 0;
}
