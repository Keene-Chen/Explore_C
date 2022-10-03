#include <stdio.h>

int factorial(unsigned int a);

int main(void)
{
    int num = 0;
    printf("请输入一个数计算阶乘\n");
    scanf("%d", &num);
    printf("%d的阶乘为%d\n", num, factorial(num));
    return 0;
}

int factorial(unsigned int a)
{
    if (a <= 1)
        return 1;
    return a * factorial(a - 1);
}