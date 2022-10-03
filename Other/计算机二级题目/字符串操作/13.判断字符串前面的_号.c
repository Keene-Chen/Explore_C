/**
* Author:   hellochen
* DateTime: 2021.03.26-18:23:50
* Description: 使字符串的前导*号不得多于n个,若多于n个,则删除多余的*号;若少于或等n个,则不做处理,字符串中间和尾部的*号不删除
* 例如,字符串中的内容为:********A*BC*DEF*G**,若n的值为4,删除后,字符串中的内容应当是:****A*BC*DEF*G**;
* 若n的值为8,则字符串中的内容仍为A*BC*DEF*G**。n的值在主函数中输入。
*/

#include <stdio.h>

void fun(char *a, int n);

int main(void)
{
    char str[] = {"********A*BC*DEF*G**"};
    int n = 0;
    scanf("%d",&n);

    puts(str);
    fun(str, n);
    puts(str);
    return 0;
}

void fun(char *a, int n)
{
    int i = 0, count = 0;
    char *p, *q;
    p = q = a;
    while (*q == '*')
    {
        count++;    // 统计字符串中前面的*号个数
        q++;
    }
    if (count > n)  // 比较前面的*个数和n是否大于
    {
        while (*p)
        {
            a[i++] = *(p + count - n);  // 删除多余的*号，使用指针偏移count-n个单位，及删除*后的字符放在a[]
            p++;
        }
        a[i] = '\0';
    }
}