#include <stdio.h>
#include "RBtree.h"

#define CHECK_INSERT 1    // "插入"动作的检测开关(0，关闭；1，打开)
#define CHECK_DELETE 0    // "删除"动作的检测开关(0，关闭；1，打开)
#define LENGTH(a) ( (sizeof(a)) / (sizeof(a[0])) )

void main()
{
		int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
		int i, ilen=LENGTH(a);

		rbtree_root *root=RBtree_init();

		printf("== 原始数据: ");
		for(i=0; i<ilen; i++)
				printf("%d ", a[i]);
		printf("\n");

		for(i=0; i<ilen; i++)
		{
				RBtree_insert(root, a[i]);
				printf("== 添加节点: %d\n", a[i]);
				printf("\n");
		}

		printf("== 前序遍历: ");
		RBtree_traversal(root);
		RBtree_delete(root, 20);
		RBtree_traversal(root);
#if CHECK_DELETE
		rbtree *temp = NULL;
		for(i=0; i<1; i++)
		{
				temp = search_node(root, 1);
				RBtree_delete(root, temp);

				printf("== 删除节点: %d\n", a[i]);
				if (root)
				{
						printf("== 树的详细信息: \n");
						RBtree_preorder(root);
						printf("\n");
				}
		}
#endif
}
