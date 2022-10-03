/**
* Author:   hellochen
* DateTime: 2021.03.24-16:17:00
* Description: 根据以下公式求P=m!/n!(m-n)!的值,结果由函数值带回。m与n为两个正整数且要求m>n
* 例如:m=12,n=8时,运行结果为495.00000
*/

#include <stdio.h>

float fun(int m, int n);

int main(void)
{
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);
    printf("%f", fun(m, n));
    return 0;
}

float fun(int m, int n)
{
    float p1 = 1, p2 = 1, p3 = 1;

    for (int i = 1; i <= m; i++)        // m的阶乘
        p1 *= i;
    for (int i = 1; i <= n; i++)        // n的阶乘
        p2 *= i;
    for (int i = 1; i <= (m - n); i++)  // (m-n)的阶乘
        p3 *= i;
    return p1 / (p2 * p3);
}