/**
* Author:   hellochen
* DateTime: 2021.03.22-18:02:27
* Description: 将M行N列的二维数组中的数据,按行的顺序依次放到一维数组中,一维数组中数据的个数存放在形参n所指的存储单元中
* 例如,若二维数组中的数据为:{33, 33, 33, 33}, {44, 44, 44, 44}, {55, 55, 55, 55},
* 则一维数组为：{33, 33, 33, 33,44, 44, 44, 44, 55, 55, 55, 55}
*/

#include <stdio.h>

void fun(int (*a)[10], int *b, int *n, int MM, int NN);

int main(void)
{
    int w[10][10] = {{33, 33, 33, 33}, {44, 44, 44, 44}, {55, 55, 55, 55}}, i, j;
    int a[100] = {0}, n = 0;

    printf("Before conversion:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d", w[i][j]);
        printf("\n");
    }
    fun(w, a, &n, 3, 4);

    printf("After conversion:\n");
    for (i = 0; i < n; i++)
        printf("%3d", a[i]);
    printf("\n");
    return 0;
}

void fun(int (*a)[10], int *b, int *n, int MM, int NN)
{
    int count = 0;
    for (int i = 0; i < MM; i++)
    {
        for (int j = 0; j < NN; j++)
        {
            b[count++] = a[i][j]; // 将二维数组中的元素赋值给一维数组
        }
    }
    *n = count; // 将数组个数通过指针返回
}