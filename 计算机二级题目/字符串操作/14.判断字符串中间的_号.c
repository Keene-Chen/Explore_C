/**
* Author:   hellochen
* DateTime: 2021.03.26-18:43:23
* Description: 除了字符串前导和尾部的*号外,将串中其它的*号全部删除。形参h已指向字符串中第一个字母,形参p指向字符串的中最后一个* 字母。在编写函数时,不得使用C语言提供的字符串函数。
* 例如,若字符串中的内容为****A*BC*DEF*G****,删除后,字符串中的内容应当是:****ABCDEFG****在编写函数时,不得使用C语言提供的字符* 串函数。
*/

#include <stdio.h>
void fun(char *a, char *h, char *p);
int main(void)
{
    char str[] = {"****ABC**D*E***FG****"}, *t, *f;

    t = f = str;
    while (*t)
        t++;
    t--;
    while (*f == '*')
        f++;
    while (*t == '*')
        t--;
    fun(str, f, t);
    printf("The string after deleted:\n");
    puts(str);
    return 0;
}

void fun(char *a, char *h, char *p)
{
    int i = 0;
    char *q = a;

    while (q < h)
    {
        a[i++] = *q;
        q++;
    }
    while (q < p)
    {
        if (*q != '*')
            a[i++] = *q;
        q++;
    }
    while (*q)
    {
        a[i++] = *q;
        q++;
    }
    a[i] = '\0';
}