#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    int pri;
    struct Node *next;
};

typedef struct Node node;

node * front,*rear;


void add(int data,int pri)
{
    node * tmp,* save;
    node * ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->pri=pri;
    ptr->next=NULL;
    if(rear==NULL)
    {
        front=rear=ptr;
    }
    else
    {
        tmp=front;
        if(pri<tmp->pri)
        {
            ptr->next=front;
            front=ptr;
        }
        else{
        while(tmp->next!=NULL)
        {
            if(tmp->pri>pri)break;
            save=tmp;
            tmp=tmp->next;
        }
        if(tmp->pri>pri)
        {   save->next=ptr;
            ptr->next=tmp;
        }
        else
            {
                tmp->next=ptr;
                rear=ptr;
            }
        }
    }
}

void print()
{
    node * tmp=front;
    printf("\n");
    while(tmp!=NULL)
    {
        printf(" %d ",tmp->data);
        tmp=tmp->next;
    }
}

int main()
{
    int ch,data,pri;
    do{
    printf("Enter choice : \n1.Add\n2.Print\n\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Enter data and priority : ");
        scanf("%d %d",&data,&pri);
        add(data,pri);
        break;
    case 2:
        print();
        break;
    }
    }while(ch!=0);
    return 0;
}
