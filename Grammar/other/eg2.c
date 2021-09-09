#include <stdio.h>

int main(void)
{
    int i, j, m, *w;
    char t;

    for (i = 1; i <= m; i++) //进行m次的循环左移
    {
        t = w[0];
        for (j = 1; w[j] != '\0'; j++)
            //从第2个字符开始以后的每个字符都依次前移一个字符
            w[j-1] = w[j];
        w[j-1] = t; //将第1个字符放到最后一个字符中
    }
    return 0;
}