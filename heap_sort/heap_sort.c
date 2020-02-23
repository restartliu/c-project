#include "heap_sort.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void binary_tree_form(headnode*, tree*);
void sort(tree*);
void write_in(headnode*, tree*);
int swap(tree*, tree*);

int* heap_sort(int* number, int count)
{
    int deep = 0;
    while(count>>deep)
        deep++;

    headnode *head = (headnode*)malloc(sizeof(headnode));
    head->deep = deep-1;
    int leave = head->leave = count-pow(2, head->deep)+1;
    head->index = 0;
    
    head->number = number;
    
    tree *temp = (tree*)malloc(sizeof(tree));
    temp->left = NULL; 
    temp->right = NULL;
    
    head->head = temp;
    
    binary_tree_form(head, head->head);

    head->index = 0;
    sort(head->head);
    write_in(head, head->head);
    
    return head->number;
}

/*-------------------------------------------------------------*/
void binary_tree_form(headnode *head, tree *temp)
{
    temp->number = *(head->number+head->index);
    head->index++;

    if( temp->left==NULL && (head->deep)!=0 && !( (head->deep)==1 && (head->leave)==0 ) )
    {
        temp->left = (tree*)malloc(sizeof(tree));
        temp->left->left = NULL;
        temp->left->right = NULL;
        head->deep--;
        binary_tree_form(head, temp->left);
    }
    
    if( temp->left!=NULL && temp->right==NULL && (head->deep)!=0 && !( (head->deep)==1 && (head->leave)==0 ) )
    {
        temp->right = (tree*)malloc(sizeof(tree));
        temp->right->left = NULL;
        temp->right->right = NULL;
        head->deep--;
        binary_tree_form(head, temp->right);
    }
    
    if( (head->deep)==1 && (head->leave)<0 )
    {
        temp->left = NULL;
        temp->right = NULL;
        head->deep++;
        return;
    }
   
    if( (head->deep)==0 )
    {
        temp->left = NULL;
        temp->right = NULL;
        head->leave--;
        if(head->leave==0)
        {
            temp = NULL;
        }
        head->deep++;
        return;
    }
    
    head->deep++;
    return;
}


/*-------------------------------------------------------------*/
void write_in(headnode *head, tree* temp)
{
    if(temp->left!=NULL)
    {
        write_in(head, temp->left);
        temp->left = NULL;
        sort(head->head);
    }
    if(temp->right!=NULL)
    {
        write_in(head, temp->right);
        temp->right = NULL;
        sort(head->head);
    }

    *(head->number+head->index) = head->head->number;
    head->index++;
    swap(temp, head->head);
    return;
}

/*-------------------------------------------------------------*/
void sort(tree *temp)
{
    int ret = 0;
    if(temp->left!=NULL)
    {
        sort(temp->left);
    }
    if(temp->right!=NULL)
    {
        sort(temp->right);
    }

    if(temp->left==NULL && temp->right!=NULL)
    {
        ret = temp->number >= temp->right->number ? 0:swap(temp, temp->right);
    }
    else if(temp->right==NULL && temp->left!=NULL)
    {
        ret = temp->number >= temp->left->number ? 0:swap(temp, temp->left);
    }
    else if(temp->left!=NULL && temp->right!=NULL)
    {
        ret = temp->number >= temp->left->number ? (temp->number >= temp->right->number ? 0:swap(temp, temp->right)):(temp->left->number >= temp->right->number ? swap(temp, temp->left):swap(temp, temp->right));
    }

    if(ret==1)
    {
        sort(temp);
    }
    
    return;
}

/*-------------------------------------------------------------*/
int swap(tree* temp1, tree* temp2)
{
    int temp = 0;
    temp = temp1->number;
    temp1->number = temp2->number;
    temp2->number = temp;
    return 1;
}
