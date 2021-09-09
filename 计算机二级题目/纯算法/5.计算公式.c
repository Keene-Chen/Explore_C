/**
* Author:   hellochen
* DateTime: 2021.03.26-15:59:40
* Description: 计算公式：S=1+(1+√2)+(1+√2+√3)+.....+(1+√2+√3+....+√n),n=20 S=534.188884
*/

#include <stdio.h>
#include <math.h>
int main(void)
{
    double sum = 1, t=1;
    for (int i = 2; i <= 20; i++)
    {
        t += sqrt(i);
        sum += t;
    }

    printf("%f\n", sum);
    return 0;
}