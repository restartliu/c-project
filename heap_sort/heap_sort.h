typedef struct TREE{
        int number;
        struct TREE *left;
        struct TREE *right;
}tree;
typedef struct HEAD{          //the node witch stored the infomation of binary tree
        int deep;             //depth of binary tree
        int leave;            //number of nodes in the last layer of binary tree
        int index;            //index of number
        int *number;          //numbers to be sorted
        tree *head;           //head node of binary tree
}headnode;

int* heap_sort( int*  /*first address of the integer array*/, int  /*number of numbers*/ );