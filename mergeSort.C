#include<stdio.h>
#include<stdlib.h>

void mergeArray(int ar[],int l,int m,int r)
{
    int nl,nr,i,j,k;
    nl=m-l+1;
    nr=r-m;
    int L[nl],R[nr];
    for(i=0;i<=nl;i++)
    {
        L[i]=ar[l+i];
    }
    for(i=0;i<=nr;i++)
    {
        R[i]=ar[m+1+i];
    }

    i=0;
    j=0;
    k=l;
    while(i<nl && j<nr)
    {
        if(L[i]<=R[j])
        {
            ar[k]=L[i];
            i++;
            k++;
        }
        if(R[j]<L[i])
        {
            ar[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<nl)
    {
        ar[k]=L[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        ar[k]=R[j];
        j++;
        k++;
    }
}


void mergeSort(int ar[],int l,int r)
{

    int m=0;
    if(l<r)
    {
        m=(l+r)/2;
        mergeSort(ar,l,m);
        mergeSort(ar,m+1,r);
        mergeArray(ar,l,m,r);
    }
}

int main()
{   int  ar[10]={5,7,1,6,70,2,8,0,12,3},i;
    for(i=0;i<9;i++)
    {
        printf("%d ",ar[i]);
    }
    mergeSort(ar,0,9);
    printf("\nsorted\n");
    for(i=0;i<=9;i++)
    {
        printf("%d ",ar[i]);
    }
    return 0;
}
