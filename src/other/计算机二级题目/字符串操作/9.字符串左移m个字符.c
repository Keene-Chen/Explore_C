/**
* Author:   hellochen
* DateTime: 2021.03.25-15:26:36
* Description: 移动字符串中的内容,移动的规则是把第1~m个字符,平移到字符串的最后,把第m+1到最后的字符移到字符串的前部
* 例如,字符串中原有的内容为 ABCDEFGHUK,m的值为3,移动后,字符串中的内容应该是 DEFGHUKABC。
*/

#include <stdio.h>

void fun(char *a, int m);

int main(void)
{
    char str[80] = {"ABCDEFGHJK"};
    int m = 4;

    fun(str, m);
    puts(str);

    return 0;
}

void fun(char *a, int m)
{
    int j;
    char ch;

    for (int i = 1; i <= m; i++)    // 外层进行m次左移
    {
        ch = a[0];  // 让第一个字符放在临时变量中
        for (j = 1; a[j] != '\0'; j++)  
        {
            a[j - 1] = a[j];    // 从第二个字符开始每一字符依次左移
        }
        a[j - 1] = ch;    // 把第一字符放在最后一个字符的位置
    }
}