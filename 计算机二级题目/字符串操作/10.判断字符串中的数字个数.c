/**
* Author:   hellochen
* DateTime: 2021.03.25-16:06:17
* Description: 字符串统计数字个数
*/

#include <stdio.h>

int main(void)
{
    char str[] = {"asd6asd5s4d65"};
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}