#include <stdio.h>

int main(void)
{
    int m, n, a, b, temp;
    scanf("%d %d", &a, &b);
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    m = a * b;
    n = a % b;
    while (n != 0)
    {
        a = b;
        b = n;
        n = a % b;
    }
    printf("最小公倍数%d,最大公约数%d", b, m / b);
}