#include"stack.h"

static char phandle[] = "handle";

Stack *new_stack_node();
void  *new_stack_value(void *value, int type_size);
void   valid_handle(Stack *handle);

Stack *stack_init()
{
    Stack *head = new_stack_node();
    head->value = new_stack_value(phandle, sizeof(phandle));
    return head;
}

void stack_push(Stack *handle, void *value, int type_size)
{
    Stack *temp = new_stack_node();
    temp->type_size = type_size;
    temp->value = new_stack_value(value, type_size);
    valid_handle(handle);
    temp->next = handle->next;
    handle->next = temp;
}

void *stack_pop(Stack *handle)
{
    valid_handle(handle);
    Stack *temp = handle->next;
    void *temp_value = malloc(temp->type_size);
    memcpy(temp_value, temp->value, temp->type_size);
    handle->next = temp->next;
    free(temp);
    return temp_value;
}

Stack *new_stack_node()
{
    Stack *temp = (Stack*)malloc(sizeof(Stack));
    temp->next = NULL;
    temp->value = NULL;
    temp->type_size = 0;
    return temp;
}

void *new_stack_value(void *value, int type_size)
{
    void *temp = malloc(type_size);
    memcpy(temp, value, type_size);
    return temp;
}

void valid_handle(Stack *handle)
{
    assert(handle!=NULL && strcmp(handle->value, phandle)==0);
}

void print_stack(Stack *handle)
{
    Stack *temp = handle->next;
    do
    {
        printf("%d\n", *((int*)temp->value));
        temp = temp->next;
    }
    while (temp!=NULL);
}

void free_stack(Stack **handle)
{
    Stack *temp = NULL;
    while (*handle != NULL)
    {
        temp = (*handle)->next;
        free((*handle)->value);
        free(*handle);
        *handle = temp;
    }
}
