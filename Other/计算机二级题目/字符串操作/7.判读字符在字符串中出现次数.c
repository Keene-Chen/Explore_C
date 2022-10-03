/**
* Author:   hellochen
* DateTime: 2021.03.23-11:50:20
* Description: 请编写一个函数,判断字符在字符串中出现的次数
*/

#include <stdio.h>
#include <string.h>

int fun(char ch[], char b);

int main(void)
{
    char buf[25], b = 0;
    printf("\n");
    printf("请输入一个字符串和一个字符以空格分隔,判断字符在字符串中出现的次数\n");
    scanf("%s %c", buf, &b);

    printf("字符%c出现的次数：%d次\n", b, fun(buf, b));
    return 0;
}

int fun(char ch[], char b)
{
    int count = 0;
    for (int i = 0; i < strlen(ch); i++)
    {
        if (b == ch[i])
        {
            count++;
        }
    }
    return count;
}