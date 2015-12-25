#include<stdio.h>
#include<conio.h>
int ar[5];
int front=-1,rear=-1;

void push(int data)
{
    int tmp=(rear+1)%5;
    if(rear==-1 && front==-1)
            {
                ar[++rear]=data;
                front++;
            }

    else if(!(tmp==front))
    {
        rear=tmp;
        ar[rear]=data;
    }


if(tmp==front)printf("\n O v E R F L O W \n");
}

int pop()
{
    int data;
    if(front==-1)
    {
        data=-9999;
    }
    else
    {
        data=ar[front];
        front=(front+1)%5;
        if(front>rear)
        {
            front=rear=-1;
        }
    }
    return data;
}
void main()
{
    int ch,data;
    do
    {

    printf("Enter choice (1. push 2. pop 3. exit) : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("Enter data : ");
               scanf("%d",&data);
               push(data);
               break;
        case 2: printf("Data is %d\n",pop());
                break;
    }
    }while(ch!=3);
}
