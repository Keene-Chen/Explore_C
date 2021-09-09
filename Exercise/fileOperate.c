#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch[255];
    FILE *fp = NULL;
    fp = fopen("./1.txt", "r+");
    
    if (fp == NULL)
    {
        puts("error");
        exit(0);
    }

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            fprintf(fp, "%d*%d=%d\t", j, i, i * j);
        }
        fprintf(fp, "\n");
    }

    /*  while (fgets(ch, 255, fp) != NULL)
    {
        printf("%s", ch);
    } */

    fclose(fp);
    return 0;
}