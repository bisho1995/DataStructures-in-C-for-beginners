


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int big(int ar[],int size)
{
    int tmp=ar[0],i,length=0;
    for(i=0;i<size;i++)
    {
        if(ar[i]>tmp)
            tmp=ar[i];
    }
    return tmp;
}

void countSort(int ar[],int size,int exp)
{
    int count[10]={0},lsd,index,i,result[size];


    for(i=0;i<size;i++)
    {
        printf(" %d ",ar[i]);
    }
    printf("\n");


    for(i=0;i<size;i++)
    {
        lsd=(ar[i]/exp)%10;
        count[lsd]=count[lsd]++;
    }
    for(i=1;i<size;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=size-1;i>=0;i--)
    {
        lsd=(ar[i]/exp)%10;
        index=count[lsd]-1;
        result[index]=ar[i];
    }
    for(i=0;i<size;i++)
    {
        ar[i]=result[i];
    }
    for(i=0;i<size;i++)
    {
        printf(" %d ",result[i]);
    }
    printf("\n");

}

void radixSort(int ar[],int size)
{
    int m=big(ar,size);
    int i=0;
    for(i=1;m/i>0;i=i*10)
    {
        countSort(ar,size,i);
    }
}

int main()
{
    int ar[]={2,10,22,2,22,6,8,8},i;
    int size=sizeof(ar)/sizeof(ar[9]);
    radixSort(ar,size);
    for(i=0;i<size;i++)
    {
        printf(" %d ",ar[i]);
    }
}
