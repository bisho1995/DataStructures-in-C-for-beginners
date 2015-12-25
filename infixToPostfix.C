#include<stdio.h>
#include<conio.h>
#include<string.h>


char *ar[10];
int top=-1;

void push(char *data)
{
    ar[++top]=data;
}
char * pop()
{
    return ar[top--];
}
int isEmpty()
{

    if(top<0)return 1;
    else return 0;
}
int main()
{
    int i=0;
    char *s;
    char str[]="(,4,6,+,)";
    char d[]=",";
    char *token;


    token=strtok(str,d);
    while(token!=NULL)
    {
        s=token;
        push(s);
        printf("%s\n",s);
        token=strtok(NULL,d);
    }
    for(i=0;i<10;i++)
    {
        printf("%d",ar[i]);
    }

    return 0;
}
