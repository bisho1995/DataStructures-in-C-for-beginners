#include<stdio.h>

int heapify(int ar[],int no)
{
    int i,root,c,tmp;
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
void print(int ar[],int no)
{
    int i;
    for(i=0;i<=no;i++)
    {
        printf("%d ",ar[i]);
    }
}
int main()
{
    int ar[5]={5,7,1,6,4};
    heapify(ar,4);
    print(ar,4);
}
