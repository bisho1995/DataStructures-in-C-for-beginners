#include<stdio.h>
#include<conio.h>

struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node node;

node *head;

void push(int data)
{
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		head->data=data;
		head->next=NULL;
	}
	else
	{
		node *tmp=(node *)malloc(sizeof(node));
		tmp->data=data;
		tmp->next=NULL;
		node *ptr=(node *)malloc(sizeof(node));
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=tmp;
		//ptr->next->next=NULL;
	}
	printf("\n PUSH DONE\n");
}
void print()
{
	node *ptr=(node *)malloc(sizeof(node));
	printf("\n \n");
	ptr=head;
	while(ptr!=NULL)
	{
		printf(" %d ",ptr->data);
		ptr=ptr->next;
	}
	//printf(" %d ",ptr->data);
}

void deleteMe(int pos)
{
    int i=0;
    node *ptr=head;

    while(i<pos-1)
    {
        ptr=ptr->next;
        i++;
    }
    printf("\n ptr ka data %d  ptr->next ka data %d",ptr->data,ptr->next->data);
    ptr->next=ptr->next->next;
    //free(ptr->next);
}

void main()
{
	push(2);
	push(5);
	push(18);
	push(44);


	print();
	deleteMe(2);
	print();
}
