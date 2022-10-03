#include <stdio.h>
void add(int a, int b, int *ptr);

int main(void)
{
    int a = 10, b = 10;
    int *p = &a;
    add(a, b, p);
    printf("%d %p", *p, p);

    return 0;
}

void add(int a, int b, int *ptr)
{
    *ptr = a + b;
}