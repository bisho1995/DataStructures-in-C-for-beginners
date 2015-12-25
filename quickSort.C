#include<stdio.h>
#include<conio.h>
int partition(int A[10],int p,int r)
{
    int x,i,j,tmp;
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
    tmp=A[r];
    A[r]=A[i];
    A[i]=tmp;
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
    int A[10]={5,8,7,5,1,9,20,4,7,3},i;
    for(i=0;i<10;i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\n\n\nFinal Array\n\n\n");
    qsort(A,0,9);
    for(i=0;i<10;i++)
    {
        printf(" %d ",A[i]);
    }

    return 0;
}
