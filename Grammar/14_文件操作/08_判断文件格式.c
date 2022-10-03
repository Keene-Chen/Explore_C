/**
 * Author     : KeeneChen
 * DateTime   : 2022.09.08-20:28:24
 * Description: 判断文件格式为Linux文件还是Windows文件
 */

#include <stdio.h>

int main(void)
{
    const char* filepath = "./test.log";
    FILE* fp = fopen(filepath, "rb");
    if (fp == NULL) {
        printf("failed to open file\n");
        return -1;
    }
    fputs("hello", fp);

    char buf[1024] = { 0 };
    fgets(buf, sizeof(buf), fp);

    int len = 0;
    while (buf[len]) {
        if (buf[len] == '\n') {
            if (buf[len - 1] == '\r') {
                printf("Windows File\n");
            } else {
                printf("Linux File\n");
            }
        }
        len++;
    }

    fclose(fp);

    return 0;
}