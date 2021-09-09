/**
* Author:   hellochen
* DateTime: 2021.05.12-20:33:08
* Description: 定义一个含有30个整型元素的数组，按顺序分别赋予从2开始的偶数，然* 后按顺序每五个数求出一个平均值放在另一数组中，并输出
*/

#include <stdio.h>

int main(void)
{
    int a[30];
    float b[6], sum = 0;

    for (int i = 0; i < 30; i++)
    {
        a[i] = 2 * (i + 1);
        sum += a[i];
        if (i % 5 == 4)
        {
            b[i / 5] = sum / 5;
            sum = 0;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%.2f ", b[i]);
    }

    return 0;
}