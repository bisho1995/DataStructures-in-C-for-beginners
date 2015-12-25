#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    int p;
    struct Node *next;
};

typedef struct Node node;

node *front,*rear;

void add(int data,int p)
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp->data=data;
    tmp->p=p;
    tmp->next=NULL;

    if(front==NULL || rear==NULL)
    {
        front=tmp;
        rear=tmp;
    }
    else
        {
            if(p<rear->p)
            {
                tmp->next=rear;
                rear=tmp;
            }
            else
                {
                    node *ptr=rear;
            while(ptr->next!=NULL && p>ptr->next->p)
            {
                ptr=ptr->next;
            }
            if(ptr==front)
            {
                front->next=tmp;
            }
            else
                {
                    node *tmp2=ptr->next;
                    ptr->next=tmp;
                    tmp->next=tmp2;
                }
            }
        }
}

void print()
{
    node *ptr=rear;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    add(5,6);
    add(1,2);
    add(10,4);
    add(4,4);
    print();
    return 0;
}
