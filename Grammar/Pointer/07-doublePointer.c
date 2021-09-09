#include <stdio.h>

int main(void)
{
    char a = 65;
    char *p = NULL;
    char **q = NULL;

    p = &a;

    q = &p;

    printf("%c",**q);
    return 0;
}