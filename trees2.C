#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * left,*right;
};

typedef struct Node node;

node * root;

void add(int data,node ** root)
{
    node * tmp=(node *)malloc(sizeof(node));
    tmp->data=data;
    tmp->right=NULL;
    tmp->left=NULL;

    if(*root==NULL)
    {
        *root=tmp;


    }

    else
    {
        if(data<(*root)->data)
            add(data,&(*root)->left);
        else add(data,&(*root)->right);
    }
}
void display(node * root)
{

    if(root->left==NULL);
    else
        display(root->left);
    printf("%d ",root->data);
    if(root->right==NULL);
    else
        {
            display(root->right);
        }
}

int height(node **root)
{
    int leftHeight,rightHeight;
    if(*root==NULL)return 0;
    else
        {
                leftHeight=1+height(&(*root)->left);
                rightHeight=1+height(&(*root)->right);

            if(leftHeight>rightHeight)
                return leftHeight;
            else
                return rightHeight;
        }

}

void balancingFactor(node **root)
{
    if((*root)==NULL);
    else
    {
        printf("\nThe balancing factor of node with value %d is %d",
               (*root)->data
               ,abs(height(&(*root)->right)-height(&(*root)->left)));
     balancingFactor(&(*root)->right);
     balancingFactor(&(*root)->left);
    }

}

void rightRotation(node ** root)
{
    node *x=(*root)->left;
    node *tr=x->right;
    x->right=*root;
    (*root)->left=tr;
    *root=x;
}
void leftRotation(node **root)
{
    node *x=(*root)->right;
    node *tr=x->left;
    x->left=*root;
    (*root)->right=tr;
    *root=x;
}
void deleteNodes(node ** root)
{
    if((*root)->right==NULL &&(*root)->left!=NULL)
    {
        (*root)->data=(*root)->left->data;
        (*root)->left=NULL;
    }
    else if((*root)->left==NULL &&(*root)->right!=NULL)
    {
        (*root)->data=(*root)->right->data;
        (*root)->right=NULL;
    }
    else
        {
            node * tmp=(*root)->right;
            while(tmp->left!=NULL)
            {
                tmp=tmp->left;
            }
            (*root)->data=tmp->data;
            tmp=NULL;
        }
}
int main()
{

    add(3,&root);
    add(2,&root);
    add(4,&root);
    add(1,&root);
    add(5,&root);
    add(7,&root);
    add(2,&root);
    printf("\nThe Elements are :- ");
    display(root);
    printf("\n\nHeight of the tree is %d",height(&root));
    balancingFactor(&root);
    rightRotation(&root);
    printf("\nThe Elements are :- ");
    display(root);
    leftRotation(&root);
    printf("\nThe Elements are :- ");
    display(root);
    deleteNodes(&root);
    printf("\nThe Elements are :- ");
    display(root);
    return 0;
}
