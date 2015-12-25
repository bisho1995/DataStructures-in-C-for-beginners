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
    ptr->next=ptr;
    if(top==NULL)
        top=ptr;
    else
    {
        tmp=top;
        while(tmp->next!=top)tmp=tmp->next;
        tmp->next=ptr;
        ptr->next=top;
    }

}

void addFront(int data)
{
    node *tmp;
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=ptr;
    if(top==NULL)addRear(data);
    else
        {
            ptr->next=top;
            top=ptr;
            tmp=top;
            if(top->next->next==top->next)top->next->next=top;
            else
            {
                tmp=tmp->next;

                while(tmp->next!=top->next )
                    tmp=tmp->next;
                tmp->next=top;
            }
        }
}

int removeFront()
{
    node * tmp;
    int data=-9999;
    if(top==NULL)return data;
    else{
            if(top->next==top)
            {
                printf(" top->next is top \n");
                data=top->data;
                top=NULL;
                return data;
            }
        data=top->data;
        //top=top->next;
        tmp=top;
        while(tmp->next!=top)tmp=tmp->next;
        tmp->next=top->next;
        top=top->next;
    }
    return data;
}

int removeRear()
{
    int data;
    node * tmp;
    if(top==NULL)return -9999;
    tmp=top;
    if(tmp->next==top)
    {
        data=top->data;
        top=NULL;
        return data;
    }
    else
    {
        while(tmp->next->next!=top)
        {
            tmp=tmp->next;
        }
        data=tmp->next->data;
        tmp->next=top;
    }
    return data;
}
void search(int data)
{
    int found=0;
    node * tmp=top;
    while(tmp->next!=top)
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
    while(ptr->next!=top)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }
    printf(" %d \n",ptr->data);

}


int main()
{
    system("color 0a");
    int ch,data;
    do
    {
        printf("Enter choice : \n1. Add at rear\n2.Add at front\n3.Remove from rear\n4.Remove from Front\n5.Display\n6.search for an item\n0. to exit\n");
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

        }
    }while(ch!=0);
    return 0;
}
