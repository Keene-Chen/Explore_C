/**
* Author:   hellochen
* DateTime: 2021.03.25-16:06:17
* Description: 字符串的值复制到另一个字符串中，不能用标准库中的字符串复制函数
*/

#include <stdio.h>

void fun(char *a, char *b);

int main(void)
{
    char str[] = {"asd6asd5s4d65"}, str1[20];
    fun(str, str1);

    for (int i = 0; i < 14; i++)
    {
        printf("%c", str1[i]);
    }

    return 0;
}

void fun(char *a, char *b)
{
    while (*a)
    {
        *b = *a;
        a++;
        b++;
    }
    *b = '\0';
}