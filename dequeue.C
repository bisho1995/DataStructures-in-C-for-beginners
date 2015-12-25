#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node *front,*rear;

void addAtBeg(int data)
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp->data=data;
    tmp->next=NULL;

    if(front==NULL || rear==NULL)
    {
        front=tmp;
        rear=tmp;
    }
    else
        {
            front->next=tmp;
            front=tmp;
        }
}

void addAtEnd(int data)
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp->data=data;
    tmp->next=NULL;

    if(front==NULL || rear==NULL)
    {
        front=tmp;
        rear=tmp;
    }
    else
        {
            tmp->next=rear;
            rear=tmp;
        }
}
void delAtRear()
{
    if(rear==NULL)
    {
        printf("Queue Empty");
    }
    else
        {
            rear=rear->next;
        }
}

void delAtFront()
{
    node *tmp;
    if(front==NULL)
    {
        printf("Queue Empty");
    }
    else
        {
            if(front==rear)
            {
                front=NULL;
                rear=NULL;
            }
            else if(rear->next==front)
            {
                front=rear;
                rear->next=NULL;
            }
            else
                {
                    tmp=rear;
                    while(tmp->next!=front)
                    {
                        tmp=tmp->next;
                    }
                    front=tmp;
                    front->next=NULL;
                }
        }
}

void print()
{
    node *tmp=rear;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
}

int main()
{
    addAtEnd(4);
    addAtEnd(1);
    addAtBeg(7);
    addAtBeg(9);
    delAtFront();
    delAtFront();
    delAtFront();
    delAtFront();
    delAtFront();
    print();
    return 0;
}
