#include <stdio.h>
#include <string.h>

int main(void)
{
    const int M = 1024;
    char str[M];
    fgets(str, M, stdin);

    int space = 0;
    int capslock = 0;
    int lowercase = 0;
    int letter = 0;
    int num = 0;
    int other = 0;

    for (int i = 0; i < (int)strlen(str); ++i)
    {
        if (str[i] == ' ')
        {
            space += 1;
        }
        else if (str[i] > 64 && str[i] < 91)
        {
            capslock += 1;
            letter += 1;
        }
        else if (str[i] > 96 && str[i] < 123)
        {
            lowercase += 1;
            letter += 1;
        }
        else if (str[i] > 47 && str[i] < 58)
        {
            num += 1;
        }
        else
        {
            if (str[i] != '\n')
            { //因为fgets()函数会在末尾自动加上\n，影响判断结果，需要判断是否为换行符
                other += 1;
            }
        }
    }
    printf("空格的个数为：%d\n", space);
    printf("英文字母的个数为：%d\n", letter);
    printf("英文大写的个数为：%d\n", capslock);
    printf("英文小写的个数为：%d\n", lowercase);
    printf("数字的个数为：%d\n", num);
    printf("其他字符的个数为：%d\n", other);
}
