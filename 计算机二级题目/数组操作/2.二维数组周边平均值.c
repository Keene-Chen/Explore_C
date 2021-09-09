/**
* Author:   hellochen
* DateTime: 2021.03.22-18:16:00
* Description: 请编写函数fun,函数的功能是:求出数组周边元素的平均值并作为函数值返回给主函数中的s
*/

#include <stdio.h>
#define N 3
double fun(int a[][N]);

int main(void)
{
    int a[][N] = {1, 2, 3,
                  4, 5, 6,
                  7, 8, 9};

    printf("%f\n", fun(a));

    return 0;
}

double fun(int a[][N])
{
    int count = 0;
    double sum = 0;

    for (int i = 0; i < N; i++) // 遍历二维数组

        for (int j = 0; j < N; j++)

            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) // 当数组下标为0或者为N-1时就是周边元素
            {
                sum += a[i][j];
                count++;
            }

    return sum / count;
}