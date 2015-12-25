#include<stdio.h>
#include<conio.h>

int ar[]={2,7,8,11,56};

void heapify(int no)
{
    int i,c,root,tmp;
    for(i=1;i<=no;i++)
    {
        c=i;
        do
        {
            root=(c-1)/2;
            if(ar[root]<ar[c])
            {
                tmp=ar[root];
                ar[root]=ar[c];
                ar[c]=tmp;
            }
            c=root;
        }while(c!=0);
    }
}
int main()
{
    int a[5],i;
    for(i=4;i>=0;i--)
    {
        heapify(i);
        a[4-i]=ar[0];
        ar[0]=ar[i];
    }
    for(i=0;i<=4;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
