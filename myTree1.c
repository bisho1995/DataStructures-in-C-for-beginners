#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *l,*r;
};

typedef struct Node node;

void insert(node **ptr,int data)
{
    if((*ptr)==NULL)
    {
        node *tmp=(node *)malloc(sizeof(node));
        tmp->data=data;
        tmp->l=tmp->r=NULL;
        (*ptr)=tmp;
    }
    else if(data< (*ptr)->data)
    {
        insert(&(*ptr)->l,data);
    }
    else
    {
        insert(&(*ptr)->r,data);
    }
}
void preOrder(node *ptr)
{
    if(ptr!=NULL)
    {
        printf(" %d ",ptr->data);
        inOrder(ptr->l);
        inOrder(ptr->r);
    }
}
void postOrder(node *ptr)
{
    if(ptr!=NULL)
    {
        postOrder(ptr->l);
        postOrder(ptr->r);
        printf(" %d ",ptr->data);
    }
}
void inOrder(node *ptr)
{
    if(ptr!=NULL)
    {
        inOrder(ptr->l);
        printf(" %d ",ptr->data);
        inOrder(ptr->r);
    }
}
void ascending(node *ptr)
{
    if(ptr!=NULL)
    {
        if(ptr->l!=NULL)
        {
             ascending(ptr->l);
        }
        printf( "%d ",ptr->data);
        preOrder(ptr->r);
    }
}
void main()
{
    node *root;
    root=NULL;
    system("color 0a");
    insert(&root,5);
    insert(&root,1);
    insert(&root,4);
    insert(&root,7);
    printf(" P R E O R D E R\n\n");
    preOrder(root);
    printf("\n\nI N O R D E R\n\n");
    inOrder(root);
    printf(" \n\n P O S T O R D E R\n\n");
    postOrder(root);
    printf("\n\n\n\n   A S C E N D I N G\n\n");
    ascending(root);
    free(root);
}
