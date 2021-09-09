#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 30
int main(void)
{
    double num[N];
    num[0] = sqrt(4);
    num[1] = pow(2, 2);
    num[2] = log(10);
    num[3] = log10(1);
    num[4] = exp(1);
    num[5] = sin(180);
    num[6] = cos(180);
    num[7] = tan(180);
    num[8] = fabs(-180);
    num[9] = fmod(6, 2);
    num[10] = abs(-10);

    for (int i = 0; i < 11; i++)
    {
        printf("%d: %f\n", i, num[i]);
    }

    return 0;
}