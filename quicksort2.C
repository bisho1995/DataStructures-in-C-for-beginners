#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int partition(int A[10],int p,int r)
{
    int tmp,i,x,j;
    x=A[r];
    i=p-1;
    for(j=p;j<=r;j++)
    {
        if(A[j]<x)
        {
            i++;
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    i++;
    tmp=A[i];
    A[i]=A[r];
    A[r]=tmp;
    return i;
}

void qsort(int A[10],int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(A,p,r);
        qsort(A,p,q-1);
        qsort(A,q+1,r);
    }
}
int main()
{
    int A[10]={8,7,0,20,60,5,3,7,45,1},i;
    for(i=0;i<=9;i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\n\nFinal array\n\n");
    qsort(A,0,9);
    for(i=0;i<=9;i++)
    {
        printf(" %d ",A[i]);
    }
    return 0;
}
