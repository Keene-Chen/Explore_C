/**
* Author:   hellochen
* DateTime: 2021.03.22-18:19:04
* Description: 编写一个函数,其功能是:从传入的num个字符中找出最长的一个字符串,
* 并通过形参指针max传回该串地址(用*作为结束输入的标识)。
*/

#include <stdio.h>
#include <string.h>

char *fun(char (*a)[128], int num, char *max);

int main(void)
{
    char *max;
    char (*a)[128]={"asd","assd","asadd"};
    fun(a[0],3,max);
    printf("%s",max);
    return 0;
}

char *fun(char (*a)[128], int num, char *max)
{
    max = a[0];
    for (int i = 0; i < num; i++)
    {
        if (strlen(max) < strlen(a[i]))
        {
            max = a[i];
        }
    }
    return max;
}