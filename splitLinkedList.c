#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
       int data;
       struct Node * next;
};

typedef struct Node node ;
node * top;
void push(int data)
{
     node * ptr=(node *)malloc(sizeof(node));
     ptr->next=NULL;
     ptr->data=data;
     node *tmp;
     tmp=top;
     if(top==NULL)top=ptr;
     else
     {
         while(tmp->next!=NULL)tmp=tmp->next;
         tmp->next=ptr;
     }
}

int pop()
{
    int data;
    node * tmp=top;
    if(top==NULL)data=-9999;
    else if(top->next==NULL)
       {
        data=top->data;
        top=NULL;
       }
     else
     {
         while(tmp->next->next!=NULL)tmp=tmp->next;
         data=tmp->next->data;
         tmp->next=NULL;
     }
}

void display()
{
 node * tmp=top;
 printf("\nData is : ");
 while(tmp->next!=NULL)

 {
                       printf(" %d ",tmp->data);
                       tmp=tmp->next;
 }
 printf("%d\n",tmp->data);
}

void split()
{
     int n=0,i=0;
     node *top1,*temp;
     node * tmp=top;
     while(tmp->next!=NULL)
     {
         n++;
         tmp=tmp->next;
     }
     tmp=top;
     while(tmp->next!=NULL)
     {
        tmp=tmp->next;
        i++;
        if(i==n/2)break;
     }
     top1=tmp->next;
     temp=tmp;
     tmp=top1;
     while(tmp->next!=NULL)
     {
        tmp=tmp->next;
     }
     tmp->next=top;
     top=top1;
     temp->next=NULL;
}

int main()
{
     int ch,data;
     do
     {
         printf("1.PUSH  \n2.POP  \n3. DISPLAY \n4.Split  \n0. EXIT  \n\nEnter choice : ");
         scanf("%d",&ch);
         switch(ch)
         {
                   case 1:printf("\nEnter data : ");
                          scanf("%d",&data);
                          push(data);
                        break;
                   case 2:
                        pop();
                        break;
                   case 3:display();
                        break;
                   case 4:
                        split();
                        break;

         }
     }while(ch!=0);
     return 0;
}
