#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int isOpen(FILE *fp);
int getFileSize(const char *filePath);
void mergeFile(const char *preFilePath, const char *newFilePath, int splitTotal);
void saveFile(const char *fileName, const char *saveData, int dataSize);

int main(void)
{
    mergeFile("test", "asda.c", 3);
    printf("合并成功!\n");

    return 0;
}

int isOpen(FILE *fp)
{
    if (fp == NULL)
    {
        printf("Open file error!\n");
        fclose(fp);
        exit(0);
    }
    return 0;
}

/**
 * @brief 获取文件大小
 * @param const char *filePath 待获取的文件
 * @return long 返回文件的字节数
 */
int getFileSize(const char *filePath)
{
    FILE *fp = fopen(filePath, "rb");
    isOpen(fp);

    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);

    fclose(fp);

    return size;
}

/**
 * @brief 合并文件
 * @param const char* preFilePath 待合并文件前缀
 * @param const char* newFilePath 合并后的文件
 * @param size_t 合并的文件份数，与拆分文件份数对应
 * @return void
 */
void mergeFile(const char *preFilePath, const char *newFilePath, int splitTotal)
{
    for (int i = 0; i < splitTotal; i++)
    {
        char mergeFileName[128] = {0};
        sprintf(mergeFileName, "%s_%d.split", preFilePath, i + 1);
        int readSize = getFileSize(mergeFileName);
        char *readByte = (char *)malloc(readSize);
        assert(readByte);

        FILE *fp = fopen(mergeFileName, "rb");
        fread(readByte, readSize, 1, fp);
        saveFile(newFilePath, readByte, readSize);

        fclose(fp);
        free(readByte);
        readByte = NULL;
    }
}

void saveFile(const char *fileName, const char *saveData, int dataSize)
{
    FILE *fp = fopen(fileName, "ab");
    isOpen(fp);
    fwrite(saveData, dataSize, 1, fp);
    fclose(fp);
}