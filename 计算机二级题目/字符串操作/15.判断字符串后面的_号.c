/**
* Author:   hellochen
* DateTime: 2021.03.27-10:05:10
* Description: 删除字符串后面的*
*/

#include <stdio.h>

void fun(char *a);

int main(void)
{
    char str[] = {"****asd*asd****"};
    fun(str);
    puts(str);
    return 0;
}

void fun(char *a)
{
    while (*a)
    {
        a++;    // 遍历字符串，把指针指向最后一个字符及'\0'
    }
    a--;    // 把指针指向最后一个字符的前一个字符
    while (*a == '*')   // 从后面删除*，不等于*就退出
    {
        a--;
        *(a + 1) = 0;
    }
}