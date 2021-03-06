/*
	红黑树的性质：
	1.所有节点都是红色或者黑色
	2.根节点为黑色
	3.所有的null叶子节点都是黑色
	4.如果该节点是红色的，那么该叶子节点一定都是黑色
	5.所有的null节点到根节点的路径上的黑色节点数量一定是相同的
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RBtree.h"

void rbtree_insert_fixup(rbtree_root *, rbtree *);
void rbtree_delete_fixup(rbtree_root *, rbtree *, rbtree *);
void left_rotate(rbtree_root *, rbtree *);
void right_rotate(rbtree_root *, rbtree *);
void preorder(rbtree *);
void inorder(rbtree *);

/*-------------------------------------------------------------------*/
rbtree_root *RBtree_init()
{
	rbtree_root *root = (rbtree_root *)malloc(sizeof(rbtree_root));
	root->headnode = NULL;
	return root;
}

void RBtree_insert(rbtree_root *root, int num)
{
	rbtree *p = root->headnode;
	rbtree *pp = NULL;

	while (p != NULL)
	{
		pp = p;
		if (num < p->number)
			p = p->left;
		else if (num >= p->number)
			p = p->right;
	}

	p = (rbtree *)malloc(sizeof(rbtree));

	if (pp != NULL)
	{
		if (num < pp->number)
			pp->left = p;
		else
			pp->right = p;

		p->color = RED;
	}
	else
	{
		root->headnode = p;
		p->color = BLACK;
	}

	p->number = num;
	p->parent = pp;

	rbtree_insert_fixup(root, p);
}

void rbtree_insert_fixup(rbtree_root *root, rbtree *node)
{
	rbtree *parent = NULL;
	rbtree *gparent = NULL;

	if (root->headnode == node)
		return;

	while (node->parent && node->parent->color == RED)
	{
		parent = node->parent;
		gparent = parent->parent;

		if (parent == gparent->left) //左更改
		{
			rbtree *uncle = gparent->right;
			if (uncle && uncle->color == RED) //gparent右节点存在且和parent颜色皆为红色时将gparent颜色下沉
			{
				uncle->color = parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
				continue;
			}
			if (parent->right == node) //<型更改变左直
			{
				left_rotate(root, parent);
				rbtree *temp = parent;
				parent = node;
				node = temp;
			}

			parent->color = BLACK; //左直更改
			gparent->color = RED;
			right_rotate(root, gparent);
		}
		else //左更改镜像
		{
			rbtree *uncle = gparent->left;
			if (uncle && uncle->color == RED)
			{
				uncle->color = parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
				continue;
			}
			if (parent->left == node)
			{
				right_rotate(root, parent);
				rbtree *temp = parent;
				parent = node;
				node = temp;
			}

			parent->color = BLACK;
			gparent->color = RED;
			left_rotate(root, gparent);
		}
	}
	root->headnode->color = BLACK;
}

/*-------------------------------------------------------------------*/
void RBtree_delete(rbtree_root *root, int element)
{
	rbtree *child, *parent, *node;
	int color;

	if (!(node = search_node(root, element)))
	{
		printf("Node is not exist!\n");
		return;
	}

	if (node->left && node->right)//当被删除节点有两个子节点时
	{
		rbtree *replace = node;

		replace = replace->right;
		while (replace->left)
			replace = replace->left;

		color = replace->color;
		parent = replace->parent;
		child = replace->right;

		if (parent == node)
			parent = replace;
		else
		{
			if (child)
				child->parent = parent;
			parent->left = child;
			replace->right = node->right;
			node->right->parent = replace;
		}

		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = replace;
			else
				node->parent->right = replace;
		}
		else
			root->headnode = replace;

		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;
	}
	else//当删除的节点只有一个叶子节点或者无叶子节点时
	{
		if (node->left)
			child = node->left;
		else
			child = node->right;

		parent = node->parent;
		color = node->color;

		if (child)
		{
			child->parent = parent;
		}

		if (parent)
		{
			if (parent->left == node)
				parent->left = child;
			else
				parent->right = child;
		}
		else
			root->headnode = child;
	}

	if (color == BLACK)
		rbtree_delete_fixup(root, child, parent);
	free(node);
}

void rbtree_delete_fixup(rbtree_root *root, rbtree *node, rbtree *parent)
{
	if (root->headnode == node)
		return;

	while ((!node || node->color == BLACK) && node != root->headnode)
	{
	}
}

/*-------------------------------------------------------------------*/
rbtree *search_node(rbtree_root *root, int num)
{
	rbtree *instead = root->headnode;

	if (!instead && !root)
	{
		printf("NULL!");
		return NULL;
	}

	do
	{
		if (num < instead->number)
			instead = instead->left;
		else if (num > instead->number)
			instead = instead->right;
		else if (num == instead->number)
			return instead;
	} while (instead);

	return NULL;
}

/*-------------------------------------------------------------------*/
void preorder(rbtree *node)
{
	if (node != NULL)
	{
		printf("%d:%d  ", node->number, node->color);
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(rbtree *node)
{
	if (node != NULL)
	{
		inorder(node->left);
		printf("%d:%d  ", node->number, node->color);
		inorder(node->right);
	}
}

void RBtree_traversal(rbtree_root *root)
{
	if (root)
	{
		inorder(root->headnode);
		printf("\n");
	}
	else
		printf("DATA NOT FOUND!\n");
}

/*-------------------------------------------------------------------*/
void left_rotate(rbtree_root *root, rbtree *node)
{
	rbtree *child = node->right;

	node->right = child->left;
	if (node->right)
		child->left->parent = node;

	child->parent = node->parent;

	if (node->parent == NULL)
	{
		root->headnode = child;
	}
	else
	{
		if (node->parent->left == node)
			node->parent->left = child;
		else
			node->parent->right = child;
	}

	child->left = node;
	node->parent = child;
}

void right_rotate(rbtree_root *root, rbtree *node)
{
	rbtree *child = node->left;

	node->left = child->right;
	if (node->left)
		child->right->parent = node;

	child->parent = node->parent;

	if (node->parent == NULL)
	{
		root->headnode = child;
	}
	else
	{
		if (node->parent->right == node)
			node->parent->right = child;
		else
			node->parent->left = child;
	}

	child->right = node;
	node->parent = child;
}
