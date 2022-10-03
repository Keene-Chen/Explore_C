#include <stdio.h>

int comparison_of_size(int a, int b);

int main(void)
{
    int num1 = 0, num2 = 0;

    printf("输入两个整数比较大小，输入任意字符退出程序\n");
    while (scanf("%d %d", &num1, &num2) == 2)
    {
        printf("%d and %d,min=%d\n", num1, num2, comparison_of_size(num1, num2));
        printf("输入两个整数比较大小，输入任意字符退出程序\n");
    }
    printf("bye\n");
    return 0;
}

int comparison_of_size(int a, int b)
{
    int min;

    (a > b) ? (min = b) : (min = a);

    return min;
}