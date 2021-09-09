/**
* Author:   hellochen
* DateTime: 2021.03.22-18:15:01
* Description: 下列程序定义了NxN的二维数组,并在主函数中自动赋值。该函数的功能是使数组右上半三角元素中的值乘以m。
*/

#include <stdio.h>
#define N 3

int main(void)
{
    int a[][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%-2d ", a[i][j]);
        }
        printf("\n");
    }
    printf("----------\n");

    for (j = 0; j < N; j++)
    {
        for (i = 0; i <= j; i++)
        {
            a[i][j] *= 2;               // 满足条件的元素每一个乘以2
            printf("%-2d ", a[i][j]);
        }
        printf("\n");
    }

    printf("----------\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%-2d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}