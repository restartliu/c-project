#include "jsonParse.h"

char *read_in(char *file_path)
{
    char *buffer = NULL;
    long file_length = 0;

    FILE *json_src = fopen(file_path, "r");

    fseek(json_src, 0, SEEK_END);
    file_length = ftell(json_src);
    fseek(json_src, 0, SEEK_SET);

    buffer = (char *)malloc(file_length);

    assert(buffer != NULL);
    assert(fread(buffer, file_length, 1, json_src) > 0);

    fclose(json_src);

    return buffer;
}

JSON_HANDLE *make_tree(char *json_buffer)
{
    char **buffer = &json_buffer;
    JSON_HANDLE *temp_head = new_node();
    temp_head->next = temp_head->parent = NULL;
    temp_head->type = HAN;
    temp_head->key = handle_key;

    skip_white_space(buffer);
    (*buffer)++;
    temp_head->value = get_value(temp_head->type, buffer);
    return temp_head;
}

JSON_NODE *make_node(char **buffer)
{
    JSON_NODE *temp_node = new_node();

    skip_white_space(buffer);
    temp_node->key = get_key(buffer);

    skip_to_or_after(':', buffer, AFTER);
    temp_node->type = get_type(buffer);
    (*buffer)++;
    temp_node->value = get_value(temp_node->type, buffer);

    skip_white_space(buffer);
    **buffer == ',' ? (*buffer)++ : 0;

    return temp_node;
}

NODE_KEY *get_key(char **buffer)
{
    (*buffer)++;
    return parse_string(buffer);
}

Flag get_type(char **buffer)
{
    skip_white_space(buffer);

    if (**buffer == '{')
    {
        return OBJ;
    }
    if (**buffer == '[')
    {
        return ARR;
    }
    if (**buffer == 34 )
    {
        return STR;
    }
    if (**buffer == 't' || **buffer == 'f')
    {
        return BOO;
    }
    if (**buffer == 'n')
    {
        return NUL;
    }
    if (**buffer > 47 && **buffer < 58)
    {
        return NUM;
    }
}

NODE_VALUE *get_value(Flag type, char **buffer)
{
    NODE_VALUE *temp = new_node_value();
    switch (type)
    {
    case HAN:
    case OBJ:
        temp->node = parse_object(buffer);
        break;
    case STR:
        temp->string = parse_string(buffer);
        break;
    default:
        break;
    }
    return temp;
}

JSON_NODE *parse_object(char **buffer)
{
    JSON_NODE *temp = NULL;
    JSON_NODE *temp_node = NULL;
    do
    {
        skip_white_space(buffer);
        if (temp_node==NULL)
        {
            temp = temp_node = make_node(buffer);
        }
        else
        {
            temp_node->next = make_node(buffer);
            temp_node = temp_node->next;
        }
    }
    while (!IfBac(**buffer));
    return temp;
}

char *parse_string(char **buffer)
{
    int count = 0;
    char *temp = *buffer;
    for (count = 0; *(temp++) != 34; count++);

    char *temp_string = (char *)malloc((count + 1) * sizeof(char));
    memcpy(temp_string, *buffer, count);
    temp_string[count] = '\0';
    *buffer = temp;
    return temp_string;
}

JSON_NODE *new_node()
{
    JSON_NODE *temp = (JSON_NODE *)malloc(sizeof(JSON_NODE));
    temp->next = temp->parent = NULL;
    temp->key = NULL;
    temp->value = NULL;
    return temp;
}

NODE_VALUE *new_node_value()
{
    NODE_VALUE *temp = (NODE_VALUE*)malloc(sizeof(NODE_VALUE));
    temp->node = NULL;
    return temp;
}

void skip_white_space(char **buffer)
{
    for(; IfJup(**buffer); (*buffer)++);
}

void skip_to_or_after(char letter, char **buffer, int to_after)
{
    for(; **buffer != letter; (*buffer)++);
    to_after == AFTER ? (*buffer)++ : 0;
}

void print_json(JSON_HANDLE *handle, int time)
{
    for(int i = 0; i < time; i++) printf("  ");
    if (HasSub(handle->type))
    {
        printf("%s:\n", handle->key);
        if ( handle->value!=NULL )
        {
            print_json(handle->value->node, time+1);
        }
    }
    else
    {
        printf("%s:%s\n", handle->key, handle->value->string);
    }
    if (handle->next != NULL)
    {
        print_json(handle->next, time);
    }

    return;
}
