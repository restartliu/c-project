#include<stdio.h>

int addition(int a, int b)
{
    int sum = 0;
    while (b != 0)
    {
        sum = a^b;
        b = (a&b)<<1;
        a = sum;
    }
    return sum;
}

int substruction(int a, int b)
{
    return addition(a, addition(~b, 1));
}

int multiplication(int a, int b)
{
    int sum = a;
    int control = 1;

    do
    {
        sum = addition(sum, a);
        control = addition(control, 1);
    }while (control != b);
    
    return sum;
}

int division(int a, int b)
{
    int count = 0;
    while (a >= b)
    {
        a = addition(a, addition(~b, 1));
        count = addition(count, 1);
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int a, b;
    a = 20;
    b = 5;
    printf("%d\n", addition(a, b));
    printf("%d\n", substruction(a, b));
    printf("%d\n", multiplication(a, b));
    printf("%d\n", division(a, b));
    return 0;
}