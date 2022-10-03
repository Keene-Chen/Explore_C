#include <stdio.h>

int main(void)
{
    char ch;
    printf("请输入一个字符\n");
    ch = getchar();

    if (ch >= 'a' && ch <= 'z')
    {
        ch = ch - 32;
        putchar(ch);
    }
    else
        printf("This is not a character");

    return 0;
}