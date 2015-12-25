#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    int ar[5]={3,10,0,8,1},i,p,tmp;
     printf("The unsorted array is :-\n");
    for(i=0;i<5;i++)
    {
        printf("%d   ",ar[i]);
    }
    for(i=1;i<=4;i++)
    {
        p=i;

        while(ar[p]<ar[p-1]&&p>0)
        {
            tmp=ar[p];
            ar[p]=ar[p-1];
            ar[p-1]=tmp;
            p--;
        }
    }

    printf("\nThe sorted array is :-\n");
    for(i=0;i<5;i++)
    {
        printf("%d   ",ar[i]);
    }

}
