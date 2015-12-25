#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int ar[5],f=-1,r=-1,n=5;
int isFull()
{
    if((r==(f-1)) || (f==0 && r==(n-1)))
    {
        return 1; // 1 means array full
    }
    else
    {
        return 0;// 0 means array empty
    }
}

int isEmpty()
{
    if(f==-1&& r==-1)
        return 1;
    else
        return 0;
}
void print()
{
    int i=0;
    for(i=f;i!r;i=(i+1)%n)
    {
        printf("%d ",ar[i]);
    }
}

void add(int data)
{
    if(isFull()==0)
    {
        if(isEmpty()==1)
        {
            r=(r+1)%n;
            ar[r]=data;
            f++;
        }
        else
            {
                r=(r+1)%n;
                ar[r]=data;
            }
    }
    else printf("\nArray OverFlow\n");
}

void removeData()
{
    if(isEmpty()==1)
    {
        printf("Array underflow");
    }
    else
    {
        f=(f+1)%n;
        if((r+1)%5==f)
        {
            f=-1;
            r=-1;
        }

    }
}



int main()
{
    add(1);
    add(5);
    add(4);
    add(4);
    add(7);
    removeData();
    add(9);
    print();
    return 0;
}
