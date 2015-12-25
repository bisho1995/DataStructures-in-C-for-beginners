#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
}
 node;

node *front,*rear;

void addRear(int data)
{
    node * ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    if(front==NULL)
    {
        front=ptr;
        rear=ptr;
    }
    else
    {
        rear->next=ptr;
        ptr->prev=rear;
        rear=ptr;
    }
}

void addFront(int data)
{
    node * ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    if(front==NULL)
    {
        front=ptr;
        rear=ptr;
    }
    else
    {
        ptr->next=front;
        front->prev=ptr;
        front=ptr;
    }
}

void removeFront()
{
    if(front==NULL)
        printf("The list is empty\n");
    else
    {
        printf(" %d ",front->data);
        front=front->next;
    }
    if(front==NULL)rear=NULL;
}
void removeRear()
{

    if(front==rear)front=rear=NULL;
    else if(rear==NULL);
    else
    {
        rear=rear->prev;
    }
}

void display()
{
    node * ptr=front;
    while(ptr!=NULL)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main()
{
    int ch,data;
    do
    {
        printf("1.Add at rear\n2.Add at front\n3.Remove from rear\n4.remove from front\n5.Display\n0.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("Enter data : ");
                scanf("%d",&data);
                addRear(data);
            break;
        case 2:printf("Enter data : ");
                scanf("%d",&data);
                addFront(data);
            break;
        case 3:removeRear();
            break;
        case 4:removeFront();
            break;
        case 5:display();
            break;
        case 0:printf("\nExitting\n");
            break;
        }
    }while(ch!=0);
    return 0;
}
