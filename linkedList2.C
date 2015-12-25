#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node *top;

void add(int data,node **root)
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp->data=data;
    tmp->next=NULL;

    if(*root==NULL)
    {
        *root=tmp;
    }
    else
    {
        node *ptr=*root;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=tmp;
    }
}
void print(node *ptr)
{
    if(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        print(ptr->next);
    }
}
int main()
{
    add(4,&top);
    add(8,&top);
    print(top);
    return 0;
}
