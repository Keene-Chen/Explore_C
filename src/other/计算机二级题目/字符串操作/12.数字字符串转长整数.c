/**
* Author:   hellochen
* DateTime: 2021.03.25-16:06:17
* Description: 字符串的值复制到另一个字符串中，不能用标准库中的字符串复制函数
* Thought: 1. 数字字符转换为整型数字等于 ASCII-48
*          2. 数字字符串转为长整型数，将每一个数*10在+下一个数字
*/

#include <stdio.h>
#include <string.h>

long method1(char *str);
long method2(char *str);
long method3(char *str);

int main(void)
{
    char str[] = {"123456789"};

    printf("Method1: %ld\n", method1(str));
    printf("Method2: %ld\n", method2(str));
    printf("Method3: %ld\n", method3(str));

    return 0;
}

// method1
long method1(char *str)
{
    int sum = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        sum = sum * 10 + str[i] - 48;
    }

    return sum;
}

// method2
long method2(char *str)
{
    int sum = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        sum = sum * 10 + *str - 48;
        str++;
    }

    return sum;
}

// method3
long method3(char *str)
{
    int sum = 0;

    while (*str) // *str!='\0'
    {
        sum = sum * 10 + *str - 48;
        str++;
    }
    
    return sum;
}