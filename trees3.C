#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left,*right;
};

typedef struct Node node;

node * root;

void add(int data,node **top)
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->data=data;

    if(*top==NULL)
    {
        *top=tmp;

    }
    else
    {
        if(data<(*top)->data)
        {
            add(data,&((*top)->left));
        }
        else
        {
            add(data,&(*top)->right);
        }
    }
}

void print(node *root)
{
    if(root!=NULL)
    {
        printf(" %d ",root->data);
        print(root->left);
        print(root->right);
    }
}

int main()
{
        add(10,&root);
        add(8,&root);
        print(root);
}
