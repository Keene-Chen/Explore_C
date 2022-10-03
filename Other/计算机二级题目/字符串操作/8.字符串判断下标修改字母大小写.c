/**
* Author:   hellochen
* DateTime: 2021.03.24-14:32:59
* Description: 
*/

#include <stdio.h>

void fun(char *str);

int main(void)
{
    char str[128];

    printf("输入一行字符串：");
    fgets(str, 128, stdin);
    printf("Before：%s", str);
    fun(str);
    printf("After ：%s", str);
    return 0;
}

void fun(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)    // 遍历字符串
    {
        if (i % 2 == 1 && str[i] >= 'a' && str[i] <= 'z')   // 下标为奇数，判断字母
        {
            str[i] = str[i] - 32;   // ASCII码-32为大写，a=97,A=65
        }
    }
}