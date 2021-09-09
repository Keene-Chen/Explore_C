/**
* Author:   hellochen
* DateTime: 2021.05.12-20:51:19
* Description: 从键盘输入10个整数，统计正数，负数，零的个数，并输出
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int a[10], zero = 0, z = 0, f = 0;

    srand((unsigned)time(NULL));

    for (int i = 0; i < 10; i++)
    {
        // scanf("%d", &a[i]);
        a[i] = (rand() % 21) - 10; // 生成-10~10总数21个
    }

    for (int i = 0; i < 10; i++)
    {
        if (a[i] == 0)
            zero++;
        else if (a[i] > 0)
            z++;
        else if (a[i] < 0)
            f++;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n零的个数=%d,正数的个数=%d,负数的个数=%d\n", zero, z, f);

    return 0;
}