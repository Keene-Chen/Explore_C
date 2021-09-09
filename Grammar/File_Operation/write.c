#include <stdio.h>

int main()
{
    FILE *fp = NULL;

    fp = fopen("E:\\ZM\\C_Language\\Base\\File_Operation\\test.txt", "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fputs("This is testing for fpu54546ts...\n", fp);
    fclose(fp);
    printf("写入成功!");
}