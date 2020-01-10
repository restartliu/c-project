typedef struct RBTREE
{
		unsigned char color;
		int number;
		struct RBTREE *left;
		struct RBTREE *right;
		struct RBTREE *parent;
}rbtree;

typedef struct RBTREE_ROOT
{
		rbtree *headnode;
}rbtree_root;

#define RED 1
#define BLACK 0

rbtree_root* RBtree_init();
void    RBtree_insert(rbtree_root *root, int num);
void 	RBtree_delete(rbtree_root *root, rbtree *node);
void	RBtree_preorder(rbtree_root *root);
rbtree* search_node(rbtree_root *root, int num);
