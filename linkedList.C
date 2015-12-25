#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Node {int data; struct Node * next;} node;

node * top;

void addRear(int data)
{
    node *tmp;
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=NULL;
    if(top==NULL)
        top=ptr;
    else
    {
        tmp=top;
        while(tmp->next!=NULL)tmp=tmp->next;
        tmp->next=ptr;
    }

}

void addFront(int data)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=NULL;
    if(top==NULL)addRear(data);
    else
        {
            ptr->next=top;
            top=ptr;
        }
}

int removeFront()
{
    int data=-9999;
    if(top==NULL)return data;
    else{
        data=top->data;
        top=top->next;
    }
    return data;
}

int removeRear()
{
    int data;
    node * tmp;
    tmp=top;
    if(tmp->next==NULL)data=-9999;
    else
    {
        while(tmp->next->next!=NULL)
        {
            tmp=tmp->next;
        }
        data=tmp->next->data;
        tmp->next=NULL;
    }
    return data;
}
void search(int data)
{
    int found=0;
    node * tmp=top;
    while(tmp->next!=NULL)
    {
        if(tmp->data==data)found=1;
        tmp=tmp->next;
    }
    if(found==1)printf("\n Found\n");
    else printf("\nNot Found\n");
}

void display()
{
    node * ptr=top;
    while(ptr->next!=NULL)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }
    printf(" %d \n",ptr->data);

}

void reverse(node * head)
{
    if(head==NULL)return;
    else if(head->next==NULL)
    {
        top=NULL;
        top=head;
        return;
    }
    else
    {
        reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return;
    }
}

int main()
{
    system("color 0a");
    int ch,data;
    do
    {
        printf("Enter choice : \n1. Add at rear\n2.Add at front\n3.Remove from rear\n4.Remove from Front\n5.Display\n6.search for an item\n0. to exit\n7.reverse the single linked list\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("Enter data :");
            scanf("%d",&data);
            addRear(data);
            break;
        case 2:
            printf("Enter data :");
            scanf("%d",&data);
            addFront(data);
            break;
        case 3:removeRear();
            break;
        case 4:removeFront();
            break;
        case 5:display();
            break;
        case 6:
            printf("Enter data to search :");
            scanf("%d",&data);
            search(data);
            break;
        case 7:
            reverse(top);
            break;

        }
    }while(ch!=0);
    return 0;
}
