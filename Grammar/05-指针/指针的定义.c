#include <stdio.h>

int main(void)
{
    int a = 1, b = 2;
    int *p = &a;
    p = &b;
    printf("%d",*p);
    return 0;
}