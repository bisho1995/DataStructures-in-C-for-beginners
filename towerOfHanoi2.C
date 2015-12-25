/*
 * C program for Tower of Hanoi using Recursion
 */
#include <stdio.h>
#include<stdlib.h>

void towers(int, int [], int [], int []);

int from[6],to[6],temp[6];

void push(int ar[],int data)
{
    ar[top++]=data;
}

int pop()
{
    return ar[top--];
}

int main()
{
    int num;
    system("color 0a");
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    //printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num-1, 1, 3, 2);
    return 0;
}
void towers(int num, int from[], int to[], int temp[])
{
    if (num == 0)
    {
        //printf("\n Move disk %d from peg %d to peg %d", num, from, to);
        push(to,pop(from));

        return;
    }
    towers(num - 1, from, temp, to);
    //printf("\n Move disk %d from peg %d to peg %d", num, from, to);
    push(to,pop(from));
    towers(num - 1, temp, to, from);
}
