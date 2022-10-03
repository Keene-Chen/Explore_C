#include <stdio.h>
#define MAXSIZE 512

int isOpen(FILE *fp);
void readMethod_1(FILE *fp);
void readMethod_2(FILE *fp);
void readMethod_3(FILE *fp);

int main(void)
{
    FILE *fp = fopen(".\\test.txt", "r");
    isOpen(fp);

    readMethod_1(fp);
    rewind(fp);
    readMethod_2(fp);
    rewind(fp);
    readMethod_3(fp);

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

// 以字符形式读取
void readMethod_1(FILE *fp)
{
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
}

// 以字符串形式读取
void readMethod_2(FILE *fp)
{
    char buff[MAXSIZE] = {0};

    while (fgets(buff, MAXSIZE, fp) != NULL)
    {
        printf("%s", buff);
    }
}

// 格式化读取
void readMethod_3(FILE *fp)
{
    char buff[MAXSIZE] = {0};
    while (fscanf(fp, "%c", buff) != EOF)
    {
        printf("%s", buff);
    }
}