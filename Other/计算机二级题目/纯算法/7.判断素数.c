/**
* Author:   hellochen
* DateTime: 2021.03.26-16:11:21
* Description: 其功能是求出小于或等于lim的所有素数并放在a数组中,并返回所求出的素数的个数。
* Thought: 所谓素数是指除了 1 和它本身以外，不能被任何整数整除的数，例如17就是素数，因为它不能被 2~16 的任一整数整除。
*/

#include <stdio.h>
int fun(int *a, int lim);

int main(void)
{
    int a[80], lim, len;
    scanf("%d", &lim);
    len = fun(a, lim);
    printf("素数个数：%d\n分别为：", len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

int fun(int *a, int lim)
{
    int i, j, k = 0;
    for (i = 2; i <= lim; i++) // 求出所有<=lim的素数
    {
        for (j = 2; j < i; j++)
            if (i % j == 0)
                break;

        if (j == i) // 判断能被整除那个数
            a[k++] = i;
    }

    return k;
}