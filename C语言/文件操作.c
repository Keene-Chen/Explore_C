/**
* Author:   hellochen
* DateTime: 2021.03.22-18:08:09
* Description: 请编写程序：从键盘输入一个字符串，将其中的小写字母全部转换成大写* 字母，输出到磁盘文件“upper.txt”中保存。输入的字符串以“!”结束。
* 然后再将文upper.txt中的内容读出显示在屏幕上。
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE *fp = NULL;
    char str[255], ch, *p = str;

    int i = 0;

    while ((ch = getchar()) != '!') // 标准输入以'!'结束
        str[i++] = ch;

    while (*p) // 未知数组长度最好不迭代遍历字符串，小写转大写
    {
        if (*p >= 'a' && *p <= 'z')
            *p -= 32;
        // *p = toupper(*p); 调用<ctype.h>库函数实现转换
        p++;
    }

    fp = fopen("./upper.txt", "w+"); // 打开一个文件，允许读写

    fputs(str, fp);
    rewind(fp); // 指针从文件结束符EOF重新指向文件开始
    fgets(str, 255, fp);
    puts(str);

    fclose(fp);

    return 0;
}
