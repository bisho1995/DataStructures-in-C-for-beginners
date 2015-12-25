#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Node
{
    char * data;
    struct Node * next;
} node;

node * head;

void insert(char * data)
{
    node * tmp;
    node * ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=ptr;

    if(head==NULL)head=ptr;
    else
    {
        tmp=head;
        while(tmp->next!=head)
            tmp=tmp->next;
        tmp->next=ptr;
        ptr->next=head;
    }
}

void display()
{
    node * ptr=head;
    while(ptr->next!=head)
    {
        printf(" %s ",ptr->data);
        ptr=ptr->next;
    }
    printf(" %s \n",ptr->data);

}

void eliminate(int n)
{
    //printf("\n In eliminate");
    node * ptr=head;
    int i=0;
    while(i!=(n-1))
    {
        ptr=ptr->next;
        i++;
    }

    if(ptr->next==ptr)
    {
        printf(" \n\n %s Wins !!",ptr->next->data);
        ptr=NULL;
    }
    else
        {
            printf(" %s ",ptr->next->data);
            ptr->next=ptr->next->next;
            head=ptr->next;
            eliminate(n);
        }
}

int main()
{
    char s[1024];
    system("color 0a");
    do
    {
        printf("Enter name : ");
        scanf("%s",s);
        insert(s);
    }while(s!="abc\n");
    //insert("amit");

    display();

    eliminate(2);

    return 0;
}
