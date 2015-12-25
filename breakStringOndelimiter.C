#include <string.h>
#include <stdio.h>

int main()
{
    char str[]="abc,def,ghi";
    char d[]=",";
    char *token;

    token=strtok(str,d);

    while(token!=NULL)
    {
        printf("%s\n",token);
        token=strtok(NULL,d);
    }

   return(0);
}
