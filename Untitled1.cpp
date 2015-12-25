#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char s[1000000],*r;
    int l,i,tests,f;
    scanf("%d",&tests);
    
    while(tests-->0)
    {
        f=1;
    scanf("%s",s);
    l=strlen(s);
        
    r=strrev(s);
    for(i=1;i<l;i++)
        {
        if(abs((int)s[i]-(int)s[i-1])!=abs((int)r[i]-(int)r[i-1]))
           {f=0;}
        }
        if(f==1)
            {
            printf("FUNNY\n");
        }
        else
            printf("Not Funny\n");
  }
    return 0;
}

