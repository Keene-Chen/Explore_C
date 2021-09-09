#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[20]={'a','b','c'};
    char a[]= "hello";
    char b[]= "hello";

   /*  strcat(a,b);
    strcpy(str,b); */
    printf("%d\n",strcmp(b,a));
    printf("%s\n",strcpy(b,str));
    printf("%s\n",strcat(a,b));
    return 0;
}