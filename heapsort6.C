#include<stdio.h>
void heapify(int ar[],int no)
{
    int i,c,root,tmp;
    for(i=1;i<=no;i++)
    {
        c=i;
        do
        {
            root=(c-1)/2; //root of the concerned child
            if(ar[root]<ar[c])
            { //swaps
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
    int ar[5]={5,8,7,0,15},i,a[5];
    for(i=0;i<=4;i++)
    {
        heapify(ar,4-i);
        a[i]=ar[0];
        ar[0]=ar[4-i];
    }
    printf("\nThe sorted array is :-");
    print(a,4);
   return 0;
}
