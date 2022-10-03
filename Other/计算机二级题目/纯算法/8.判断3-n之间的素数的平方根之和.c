/**
* Author:   hellochen
* DateTime: 2021.03.26-15:50:38
* Description: 判断3-n之间的素数的平方根之和
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    double sum = 0;
    int i, j;
    for (i = 3; i <= 100; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j == i)
        {
            sum += sqrt(i);
        }
    }
    printf("%f\n", sum);

    return 0;
}