#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node * top;


void push(int data)
{
    node * tmp=(node *)malloc(sizeof(node));
    tmp->data=data;
    tmp->next=NULL;

    if(top==NULL)
    {
        top=tmp;
    }
    else
        {
            tmp->next=top;
            top=tmp;
        }
}
int pop()
{
    int data=-99999;
    if(top==NULL)
    {
        printf("Stack Underflow");
    }
    else
        {
            data=top->data;
            top=top->next;
        }
    return data;
}

void display()
{
    node * ptr=top;
    while(ptr!=NULL)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
        push(1);
        push(8);
        push(6);
        push(3);
        push(0);
        push(5);
        display();
        printf("\n");
        pop();
        pop();
        display();
}







