#include <stdio.h>
#include <stdlib.h>

void fun(char (*str)[3], char *str1);

int main(void)
{
    char str[][3] = {{"www"}, {"sss"}, {"hhh"}}, str1[9];

    fun(str, str1);
    puts(str1);
    return 0;
}

void fun(char (*str)[3], char *str1)
{
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            str1[k++] = str[j][i]; // str[j][i]按列赋值,按行赋值str[i][j];
        }
    }
    str1[k] = '\0';
}