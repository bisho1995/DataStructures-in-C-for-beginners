#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<conio.h>


int ar[1024],top=-1;

void push(int data)
{
    ar[++top]=data;
}

int pop()
{
    return ar[top--];
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("\n%d",ar[i]);
    }
}


int main()
{
    char ch;
    int k,a,b;
    printf("Enter the expression : ");
    while((ch=getchar())!='\n')
    {
         if(isdigit(ch))
        {
            k=(int)ch-'0';
            push(k);
        }
        else
        {
            switch(ch)
            {
            case '+':
                a=pop();
                b=pop();
                push(a+b);
                break;
            case '-':
                a=pop();
                b=pop();
                push(a-b);
                break;

            case '*':
                a=pop();
                b=pop();
                push(a*b);
                break;

            case '/':
                a=pop();
                b=pop();
                push(a/b);
                break;

            case '^':
                a=pop();
                b=pop();
                push(pow(a,b));
                break;

            }
        }
    }
    printf("\n\nThe data is %d",pop());
    return 0;
}
