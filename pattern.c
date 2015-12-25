/*
* * * * *
. * * * *
. . * * *
. . . * *
. . . . *
*/

/*
*****
****
***
**
*
*/

#include<stdio.h>
int main()
{
    int outer,inner;
    for(outer=1;outer<=5;outer++)
    {
        for(inner=1;inner<=5;inner++)
        {
            if(inner<=(outer-1))
                printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}
