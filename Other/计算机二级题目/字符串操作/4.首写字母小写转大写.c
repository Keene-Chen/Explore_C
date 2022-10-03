/**
* Author:   hellochen
* DateTime: 2021.03.22-18:20:16
* Description: 编写函数实现字符串中首写字母小写变为大写
*/

#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char str[128], *p = str;
    fgets(str, 128, stdin);

    int flag = 0;
    for (; *p; p++) // 遍历字符串
    {
        if (flag)
        {
            if (*p == ' ')
                flag = 0;
        }
        else
        {
            if (*p != ' ')
            {
                flag = 1;
                *p = toupper(*p);
            }
        }
    }
    printf("%s", str);
    return 0;
}