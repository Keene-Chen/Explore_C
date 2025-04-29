#include <stdio.h>
#include <string.h>
#define MAXSIZE 512

int isOpen(FILE *fp);
void writeMethod_1(FILE *fp);
void writeMethod_2(FILE *fp);
void writeMethod_3(FILE *fp);

const char *str = "abcdefg";

int main(void)
{
    FILE *fp = fopen(".\\test.txt", "w+");
    isOpen(fp);

    writeMethod_1(fp);
    writeMethod_2(fp);
    writeMethod_3(fp);

    fclose(fp);

    return 0;
}

// 判断文件是否打开
int isOpen(FILE *fp)
{
    if (fp == NULL)
    {
        printf("open error!\n");
        fclose(fp);
        return -1;
    }
    return 0;
}

// 以字符形式写入
void writeMethod_1(FILE *fp)
{
    for (int i = 0; i < strlen(str); i++)
    {
        fputc(str[i], fp);
    }
}

// 以字符串形式写入
void writeMethod_2(FILE *fp)
{
    fputs(str, fp);
}

// 以格式化写入
void writeMethod_3(FILE *fp)
{
    fprintf(fp, "%s", str);
}