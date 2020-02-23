#include "reverseLinkList.h"

typedef struct test
{
    int number;
    struct test* next;
}TEST;

TEST* constructLinkList()
{
    TEST* headnode = NULL;
    TEST* temp = NULL;
    for (int i = 10; i >= 0; i--)
    {
        temp = (TEST*)malloc(sizeof(TEST));
        temp->number = i;
        temp->next = headnode;
        headnode = temp;
    }
    return headnode;
}

void print(TEST* headnode)
{
    TEST* temp = headnode;
    while (temp)
    {
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
}

TEST* reverse(TEST* headnode)
{
    TEST* swap = NULL;
    TEST* newnode = headnode->next;
    headnode->next = NULL;
    while (newnode)
    {
        swap = headnode;
        headnode = newnode;
        newnode = newnode->next;
        headnode->next = swap;
    }
    return headnode;
}

TEST* reverse2(TEST* headnode, TEST* newnode)
{
    if (!headnode)
        return newnode;

    TEST* temp = headnode->next;
    headnode->next = newnode;
    return reverse2(temp, headnode);
}

int main(int argc, char const* argv[])
{
    TEST* headnode = constructLinkList();

    print(headnode);
    headnode = reverse(headnode);
    print(headnode);
    headnode = reverse2(headnode, NULL);
    print(headnode);

    return 0;
}
