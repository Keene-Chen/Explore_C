/**
* Author:   hellochen
* DateTime: 2021.03.24-16:01:04
* Description: 求出数组的最大元素在数组中的下标并存放在k所指向的存储单元中。
* 例如,输入如下整数876,675,896,101,301,401,980,431,451,777,则输出结果为980。
*/

#include <stdio.h>

int fun(int *s, int t, int *k);

int main(void)
{
    int s[5] = {0}, t = 5, k;

    printf("请输入五个数比较大小：\n");

    for (int i = 0; i < t; i++)
    {
        scanf("%d", s);
    }

    fun(s, t, &k);

    printf("%d\n", s[k]);

    return 0;
}

int fun(int *s, int t, int *k)
{
    *k = 0;
    for (int i = 0; i < t; i++)
    {
        if (s[i] > s[*k])
            *k = i; // 让最大元素的下标赋值给k
    }

    return s[*k]; // 返回数组中最大元素
}