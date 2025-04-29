#include <stdio.h>
#include <string.h>
#define MAXSIZE 512

const char *str = "Hello World!";

int main(void)
{
    FILE *fp = fopen(".\\test.bin", "wb+");
    if (fp == NULL)
    {
        printf("File open error!");
        return -1;
    }

    fwrite(str, strlen(str), 10, fp);

    fclose(fp);

    return 0;
}