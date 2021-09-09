#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[10] = "abcd", b[4] = "efg";

    // strcat(a, b);
    // strcpy(a,"sdfsdfs");
    int n=strcmp(a,b);
    printf("%d",n);
    return 0;
}