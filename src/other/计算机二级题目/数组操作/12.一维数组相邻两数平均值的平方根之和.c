#include <stdio.h>
#include <math.h>
int main(void)
{
    double a[] = {12.0, 34.0, 4.0, 23.0, 34.0, 45.0, 18.0, 3.0, 11.0};
    double sum = 0;
    for (int i = 0; i < 8; i++)
    {
        sum = sum + sqrt((a[i] + a[i + 1]) / 2);
    }
    printf("%f", sum);

    return 0;
}