#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

typedef struct Node node;
node *front,*rear;

void add(int data)
{
    node * ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=NULL;
    if(front==NULL || rear==NULL)
    {
        front=ptr;
        rear=ptr;
    }
    else
        {
            rear->next=ptr;
            rear=ptr;
        }
}

int remove()
{
    int data=-9999;
    if(front==NULL)
    {
        printf("\nQueue underflow");
    }
    else
        {
            data=front->data;
            front=front->next;
        }
    return data;
}

void display()
{
    node *ptr=front;
    while(ptr!=NULL)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    add(2);
    add(5);
    add(7);
    add(9);
    display();
    printf("\n");
    remove();
    remove();
    display();
}
