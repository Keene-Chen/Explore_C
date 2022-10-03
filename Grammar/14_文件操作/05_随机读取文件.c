#include <stdio.h>

#define MAXSIZE 512

int isOpen(FILE *fp);
void isClose(FILE *fp);

int main(void)
{
    FILE *fp = fopen(".\\test.txt", "r");
    isOpen(fp);

    fseek(fp, 1L, SEEK_CUR);

    char buff[MAXSIZE] = {0};
    /* while (fgets(buff, MAXSIZE, fp) != NULL)
    {
        printf("%s", buff);
    } */

    fgets(buff, MAXSIZE, fp);
    printf("%s",buff);

    isClose(fp);

    return 0;
}

int isOpen(FILE *fp)
{
    if (fp == NULL)
    {
        printf("Open Error!");
        return -1;
    }
    return 0;
}

void isClose(FILE *fp)
{
    if (fclose(fp) != 0)
    {
        printf("File Close Error!");
    }
}