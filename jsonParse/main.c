#include"jsonParse.h"

int main(int argc, char const *argv[])
{
    char *buffer = read_in("test.json");
    JSON_HANDLE *handle = make_tree(buffer);
    print_json(handle, 0);
    return 0;
}
