#include<stdio.h>
#include<stdlib.h>

int main()
{
    int ar[7]={9,2,4,10,1,8,40},i,j,tmp=0;
    for(i=0;i<7;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n\n\nAfter sorting\n\n");
    for(i=0;i<7-1;i++)
    {
        for(j=0;j<7-1-i;j++)
        {
            if(ar[j]>ar[j+1])
            {
                tmp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=tmp;
            }
        }
    }
    for(i=0;i<7;i++)
    {
        printf("%d ",ar[i]);
    }
}
