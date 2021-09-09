#include <stdio.h>

int main(void)
{
    int i, n;
    double s = 0.0;
    n = 10;

    for (i = 1; i <= n; i++)
        s += 1.0 / (i * (i + 1));
    printf("%f", s);
    return 0;
}