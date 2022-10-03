#include <stdio.h>
#define MAXSIZE 512

int main(void)
{
    FILE *fp = fopen(".\\test.bin", "rb");
    if (fp == NULL)
    {
        printf("File open error!");
    }

    char buff[MAXSIZE] = {0};
    fread(buff, MAXSIZE, 1, fp);
    printf("%s", buff);

    if (fclose(fp) != 0)
        printf("File close error!");

    return 0;
}