/**
 * Author     : KeeneChen
 * DateTime   : 2022.09.08-20:28:18
 * Description: 07_删除文件与重命名文件
 */

#include <stdio.h>

int main(void)
{
    const char* filepath = "./test.log";
    const char* new_filepath = "./test.txt";
    FILE* fp = fopen(filepath, "w+");
    if (fp == NULL) {
        printf("failed to open file\n");
        return -1;
    }
    fputs("hello", fp);
    fclose(fp);

    int ret = rename(filepath, new_filepath);
    if (ret < 0) {
        printf("rename file error\n");
        return -1;
    }

    ret = remove(new_filepath);
    if (ret < 0) {
        printf("remove file error\n");
        return -1;
    }

    return 0;
}