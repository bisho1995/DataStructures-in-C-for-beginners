#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct Node
{
    int data;
    struct Node *l,*r;
};

typedef struct Node node;

node *root;

node * assign()
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=0;
    ptr->l=ptr->r=NULL;
    return ptr;
}

node * assign(int data)
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->l=ptr->r=NULL;
    return ptr;
}

void add(int data,node **root)
{
    node *ptr=assign(data);
    if((*root)==NULL)
    {
        (*root)=ptr;
    }
    else
    {
        if(data<(*root)->data)
        {
            add(data,&(*root)->l);
        }
        else
            add(data,&(*root)->r);
    }
}
void display(node *root)
{
    if(root==NULL) return;
    else
    {
        display(root->l);
        printf(" %d ",root->data);
        display(root->r);
    }

}
int main()
{
        add(2,&root);
        add(1,&root);
        add(3,&root);

        display(root);
}
