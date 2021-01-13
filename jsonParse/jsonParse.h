#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define TO    0
#define AFTER 1
#define FALSE 0
#define TRUE  1
#define STR   2
#define NUM   3
#define BOO   4
#define NUL   5
#define OBJ   6
#define ARR   7
#define HAN   8


#define IsObj(element) (element=='{')
#define IsArr(element) (element=='[')
#define IfJup(element) (element==' ' || element=='\n')
#define IfBac(element) (element=='}' || element==']')
#define HasSub(flag)   (flag==OBJ || flag==ARR || flag==HAN)

typedef struct json_node  JSON_NODE;
typedef struct json_node  JSON_HANDLE;
typedef union  node_value NODE_VALUE;
typedef char   NODE_KEY;
typedef int    Flag;

union node_value
{
    double     number;
    char      *boolean;
    char      *string;
    char      *null;
    JSON_NODE *node;
};

struct json_node
{
    Flag        type;
    NODE_KEY   *key;
    NODE_VALUE *value;
    JSON_NODE  *parent;
    JSON_NODE  *next;
};


static char *null_value  = "null";
static char *true_value  = "true";
static char *false_value = "false";
static char *handle_key  = "handle";

char        *read_in(char *file_path);
JSON_HANDLE *make_tree(char *buffer);
JSON_NODE   *make_node(char **buffer);
NODE_KEY    *get_key(char **buffer);
Flag         get_type(char **buffer);
NODE_VALUE  *get_value(Flag type, char **buffer);
JSON_NODE   *parse_object(char **buffer);
char        *parse_string(char **buffer);
JSON_NODE   *new_node();
NODE_VALUE  *new_node_value();
void         skip_white_space(char **buffer);
void         skip_to_or_after(char letter, char **buffer, int to_after);
void         print_json(JSON_HANDLE *handle, int time);