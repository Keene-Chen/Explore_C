/**
* Author:   hellochen
* DateTime: 2021.03.24-15:07:37
* Description: 求出能整除x且不是偶数的各整数,并按从小到大的顺序放在p所指的数组中,这些除数的个数通过形参n返回。
* 例如,若x中的值为30,则有4个数符合要求,它们是1、3、5、15
*/

#include <stdio.h>
void fun(int x, int pp[], int *n);
int main(void)
{
    int x = 0, n = 0, pp[30];

    printf("输入一个数进行运算：\n");
    scanf("%d", &x);

    fun(x, pp, &n);

    printf("总共%d个", n);
    printf("能被%d整除且不是偶数的数为:", x);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", pp[i]);
    }
    printf("\n");

    return 0;
}

void fun(int x, int pp[], int *n)
{
    int j = 0;

    for (int i = 1; i < x; i += 2) // 循环条件为奇数，从1开始每次加2
    {
        if (x % i == 0)
            pp[j++] = i; // 把能整除的数放入数组中
    }

    *n = j; // 指针带回满足条件的数
}