#include <stdio.h>
#include <string.h>
#include <math.h>

int isOpen(FILE *fp);
long getFileSize(const char *filePath);
char *getFileName(const char *filePath);

int main(void)
{
    const char *filePath = "F:\\06_ISO\\linuxmint-20.1-xfce-64bit.iso";
    long size = getFileSize(filePath);

    printf("FileName: %s\n", getFileName(filePath));

    printf("Size: %ld bytes %ld KB %ld MB %.2f GB", size, (long)(size / pow(2, 10)), (long)(size / pow(2, 20)), (double)(size / pow(2, 30)));

    return 0;
}

/**
 * @brief 判断文件是否打开
 * @param FILE *fp 文件指针
 * @return int
 */
int isOpen(FILE *fp)
{
    if (fp == NULL)
    {
        printf("Open file error!\n");
        fclose(fp);
        return -1;
    }
    return 0;
}

/**
 * @brief 获取文件大小
 * @param const char *filePath 待获取的文件
 * @return long 返回文件的字节数
 */
long getFileSize(const char *filePath)
{
    FILE *fp = fopen(filePath, "r");
    isOpen(fp);

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);

    fclose(fp);

    return size;
}

/**
 * @brief 获取文件名字
 * @param const char *filePath 待获取的文件
 * @return char * 返回文件名字
 */
char *getFileName(const char *filePath)
{
    char ch = '\\';                         // 其中一个反斜杠是转义字符
    char *name = strrchr(filePath, ch) + 1; // 注意这里要+1
    return name;
}
