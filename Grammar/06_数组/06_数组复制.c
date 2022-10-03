/**
 * Author:   KeeneChen
 * DateTime: 2022.07.19-16:05:54
 * Description: 06_数组复制
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    int a[3] = {0};
    int b[3] = {1, 2, 3};

    // 方式一: for 循环
    for (int i = 0; i < 3; i++)
    {
        a[i] = b[i];
        printf("%d ", a[i]);
    }
    printf("\n");

    // 方式二: memcpy 函数
    memcpy(a, b, sizeof(b));
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}