#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

char* strtonum(char* src, int *count);

int main(int argc, char *argv[])
{
    char *src = argv[1];
    char result[1024] = {'\0'};
    STACKINFO* targetStack = stackinit();
    STACKINFO* operStack = stackinit();
    while (*src != '\0')
        push(targetStack, *(src++));
    
    int count = 0;
    int charCount = 0;
    char countString[10] = {'\0'};
    char tempString[1024] = {'\0'};
    while (targetStack->head)
    {
        if ((char)(targetStack->head->receive) == '[')
        {
            pop(targetStack);
            while ((char)(operStack->head->receive) != ']')
            {
                if (operStack->head->receive >= 48 && operStack->head->receive <= 57)
                    for (int i = 0; operStack->head->receive >= 48 && operStack->head->receive <= 57; i++)
                        countString[i] = (char)pop(operStack);
                else if((char)(operStack->head->receive) == '|' && pop(operStack))
                    sscanf(countString, "%d", &count);
                else if(operStack->head->receive >= 65 && operStack->head->receive <= 90)
                    for (int i = 0; operStack->head->receive >= 65 && operStack->head->receive <= 90; i++)
                        tempString[i] = (char)pop(operStack);
            }
            pop(operStack);
            for (charCount = 0; tempString[charCount]!='\0'; charCount++);
            for (int i = 0; i < count; i++)
                for (int j = charCount-1; j >= 0; j--)
                    push(operStack, tempString[j]);
            
            char countString[10] = {'\0'};
            char tempString[1024] = {'\0'};
        }
	    else if(targetStack->head)
            push(operStack, pop(targetStack));
    }
    for (int i = 0; operStack->head; i++)
        result[i] = (char)pop(operStack);

    printf("%s\n", result);
}