/**
* Author:   hellochen
* DateTime: 2021.03.25-19:41:40
* Description: 将一组的分中，去掉一个最高分和最低分，再求平均分并通过函数返回。
*/

#include <stdio.h>

double fun(double a[], int n);

int main(void)
{
    double a[] = {9.9, 8.5, 7.6, 8.5, 9.3, 9.5, 8.9, 7.8, 8.6, 8.4};
    printf("%f", fun(a, 10));
    return 0;
}

double fun(double a[], int n)
{
    double max, min, sum;
    max = min = a[0];

    for (int i = 0; i < n; i++)
    {
        sum += a[i]; // 算出数组中的总数，找到最大值和最小值后在减去
        if (max < a[i])
            max = a[i];
        if (min > a[i])
            min = a[i];
    }

    sum = sum - max - min;

    return sum / (n - 2);   // 平均数的等于去掉最大值和最小值后的个数
}