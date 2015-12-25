#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};


typedef struct Node node;
node * front,*rear;

void add(int data)
{
    node * ptr;
    node * tmp=(node *)malloc(sizeof(node));
    tmp->data=data;
    tmp->next=NULL;

    if(front==NULL && rear==NULL)
    {
        front=rear=tmp;
    }
    else
    {
        rear->next=tmp;
        rear=tmp;
    }
}

void remove()
{
    if(front==NULL)printf("\n\nThe stack is empty .\nNothing to print\n\n");
    else
        {
            front=front->next;
        }
    if(front==NULL)rear=NULL;
}


void display()
{
    node * ptr=front;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n\n");
}


int main()
{
    int ch,data;
    do
    {
        printf("Enter \n1.Add Element\n2.Remove Element\n3.Display\n0.Exit  ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("\nEnter Data : ");
            scanf("%d",&data);
            add(data);
            break;
        case 2:remove();
            break;
        case 3:display();
            break;
        case 0:
            break;

        }
    }while(ch!=0);


    return 0;
}
