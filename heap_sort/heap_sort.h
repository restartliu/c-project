typedef struct TREE{
        int number;
        struct TREE *left;
        struct TREE *right;
}tree;
typedef struct HEAD{
        int deep;
        int leave;
        int index;
        int *number;
        tree *head;
}headnode;

int* heap_sort(int*, int);
