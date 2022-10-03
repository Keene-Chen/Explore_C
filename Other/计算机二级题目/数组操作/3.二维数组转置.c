/**
* Author:   hellochen
* DateTime: 2021.03.22-18:18:30
* Description: 编写程序,实现矩阵(行、3列的转置(即行列互换)。
*/

#include <stdio.h>
#define N 3

int main(void)
{
    int a[N][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }

    printf("----------\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int temp = a[i][j]; // 行列互换
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
