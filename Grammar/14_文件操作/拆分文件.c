#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int isOpen(FILE *fp);
int getFileSize(const char *filePath);
void splitFile(const char *filePath, const char *newFilePath, size_t splitTotal);
void saveFile(const char *fileName, const char *saveData, size_t dataSize);

int main(void)
{
    const char *filePath = "test.c";
    splitFile(filePath, "test", 3);
    printf("文件拆分成功!");
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
 * @return int 返回文件的字节数
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

void splitFile(const char *filePath, const char *newFilePath, size_t splitTotal)
{
    // 获取文件的大小
    long fileSize = getFileSize(filePath);
    // 拆分文件
    int readSize = fileSize / splitTotal;
    int lastSize = (fileSize / splitTotal) + (fileSize % splitTotal);
    FILE *fp = fopen(filePath, "rb");
    isOpen(fp);
    for (int i = 0; i < splitTotal - 1; i++)
    {
        // 读取源文件的部分信息
        char *readByte = (char *)malloc(readSize);
        // 使用断言判断内存是否申请成功
        assert(readByte);
        fread(readByte, readSize, 1, fp);
        // 处理拆分后的文件名
        char splitFileName[128] = {0};
        sprintf(splitFileName, "%s_%d.split", newFilePath, i + 1);
        saveFile(splitFileName, readByte, readSize);

        free(readByte);  // 释放本轮读取数据
        readByte = NULL; // 防止野指针出现
    }
    // 处理最后一份未读取的数据
    char *readByte = (char *)malloc(lastSize);
    assert(readByte);
    fread(readByte, lastSize, 1, fp);
    char splitFileName[128] = {0};
    sprintf(splitFileName, "%s_%zu.split", newFilePath, splitTotal);
    saveFile(splitFileName, readByte, lastSize);

    fclose(fp);
    free(readByte);  // 释放最后一轮读取数据
    readByte = NULL; // 防止野指针出现
}

void saveFile(const char *fileName, const char *saveData, size_t dataSize)
{
    FILE *fp = fopen(fileName, "wb");
    isOpen(fp);
    fwrite(saveData, dataSize, 1, fp);
    fclose(fp);
}