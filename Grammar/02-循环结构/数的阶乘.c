#include <stdio.h>

int main(void)
{
    int num = 0, sum = 1;
    printf("请输入一个数计算阶乘\n");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
        sum = sum * i;
    printf("%d", sum);

    return 0;
}