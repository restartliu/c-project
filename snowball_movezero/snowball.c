#include"snowball.h"

void snowball(int *number, int length)
{
    int j = 0;
    printf("%d\n", length);
    for (int i = 0; i < length; i++)
    {
        if (number[i]!=0)
        {
            if (number[j]==0)
            {
                number[j] = number[i];
                number[i] = 0;
            }
            j++;
        }
        
    }
    
}
