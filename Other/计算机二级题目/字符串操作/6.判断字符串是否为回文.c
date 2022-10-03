/**
* Author:   hellochen
* DateTime: 2021.03.23-15:10:14
* Description: 判断字符串是否为回文,若是,则函数返回1,主函数中输出"YES",否则返回0,主函数中输出"No"。
* 回文是指顺读和倒读都一样的字符串。
* 例如,字符串LEⅤEL是回文,而字符串1231就不是回文。
*/

#include <stdio.h>
#define N 80

int fun(char *str);

void main()
{
    char s[N];

    printf("Enter a string : ");
    gets(s);
    printf("\n");
    puts(s);
    if (fun(s))
        printf("YES\n");
    else
        printf("NO\n");
}

int fun(char *str)
{
    int i, j = 0, flag = 1;
    char *p = str;

    while (*p)  // 通过指针遍历字符串并统计字符个数
    {
        j++;
        p++;
    }
    
    j-=1;   // 字符个数-1才是最后一个字符而不是\0

    for (i = 0; i < j; i++, j--)    // 比较第一个字符和最后一个字符是否相等
    {
        if (str[i] != str[j])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}