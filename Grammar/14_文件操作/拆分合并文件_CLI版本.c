#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXSIZE 128

void isOpen(FILE *fp);
int getFileSize(const char *filePath);
void splitFile(const char *filePath, const char *newFilePath, size_t splitTotal);
void saveFile(const char *fileName, const char *saveData, size_t dataSize);
void mergeFile(const char *preFilePath, const char *newFilePath, size_t splitTotal);
void appendFile(const char *fileName, const char *saveData, size_t dataSize);
void menu();

int main(void)
{
    char splitFilePath[MAXSIZE], newSplitFilePath[MAXSIZE], mergePreFile[MAXSIZE], mergeFilePath[MAXSIZE];
    int splitCount, mergeCount = 0;

    menu();
    char ch = getchar();
    if ((ch == 'S') || (ch == 's'))
    {
        printf("拆分文件路径 | 拆分文件后名称 | 拆分总份数\n");
        scanf("%s %s %d", splitFilePath, newSplitFilePath, &splitCount);
        splitFile(splitFilePath, newSplitFilePath, splitCount);
    }

    else if (ch == 'M' || (ch == 'm'))
    {
        printf("合并文件前缀 | 合并文件后名称 | 合并总份数\n");
        scanf("%s %s %d", mergePreFile, mergeFilePath, &mergeCount);
        mergeFile(mergePreFile, mergeFilePath, mergeCount);
    }
    else
        exit(0);

    return 0;
}

/**
 * @brief  判断文件是否打开
 * @param  FILE *fp 文件指针
 * @return void
 */
void isOpen(FILE *fp)
{
    if (fp == NULL)
    {
        printf("Open file error!\n");
        fclose(fp);
        exit(0);
    }
}

/**
 * @brief  获取文件大小
 * @param  const char *filePath 待获取的文件
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

/**
 * @brief  拆分函数
 * @param  const char *filePath 待拆分文件路径
 * @param  const char *newFilePath 拆分文件后的新名称
 * @param  size_t splitTotal 拆分总份数
 * @return void
 */
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
        char splitFileName[MAXSIZE] = {0};
        sprintf(splitFileName, "%s_%d.split", newFilePath, i + 1);
        saveFile(splitFileName, readByte, readSize);

        free(readByte);  // 释放本轮读取数据
        readByte = NULL; // 防止野指针出现
    }

    // 处理最后一份未读取的数据
    char *readByte = (char *)malloc(lastSize);
    assert(readByte);
    fread(readByte, lastSize, 1, fp);
    char splitFileName[MAXSIZE] = {0};
    sprintf(splitFileName, "%s_%zu.split", newFilePath, splitTotal);
    saveFile(splitFileName, readByte, lastSize);

    fclose(fp);
    free(readByte);  // 释放最后一轮读取数据
    readByte = NULL; // 防止野指针出现

    printf("文件拆分成功!\n");
}

/**
 * @brief  辅助拆分函数保存到文件
 * @param  const char *fileName 保存文件名
 * @param  const char *saveData 保存文件信息
 * @param  size_t dataSize 保存文件大小
 * @return void
 */
void saveFile(const char *fileName, const char *saveData, size_t dataSize)
{
    FILE *fp = fopen(fileName, "wb");
    isOpen(fp);
    fwrite(saveData, dataSize, 1, fp);
    fclose(fp);
}

/**
 * @brief  合并文件
 * @param  const char* preFilePath 待合并文件前缀
 * @param  const char* newFilePath 合并后的文件路径
 * @param  size_t splitTotal 合并的文件份数，与拆分文件份数对应
 * @return void
 */
void mergeFile(const char *preFilePath, const char *newFilePath, size_t splitTotal)
{
    for (int i = 0; i < splitTotal; i++)
    {
        char mergeFileName[MAXSIZE] = {0};
        sprintf(mergeFileName, "%s_%d.split", preFilePath, i + 1);
        int readSize = getFileSize(mergeFileName);
        char *readByte = (char *)malloc(readSize);
        assert(readByte);

        FILE *fp = fopen(mergeFileName, "rb");
        fread(readByte, readSize, 1, fp);
        appendFile(newFilePath, readByte, readSize);

        fclose(fp);
        free(readByte);
        readByte = NULL;
    }
    printf("文件合并成功!\n");
}

/**
 * @brief  辅助合并函数追加保存到文件
 * @param  const char *fileName 保存文件名
 * @param  const char *saveData 保存文件信息
 * @param  size_t dataSize 保存文件大小
 * @return void
 */
void appendFile(const char *fileName, const char *saveData, size_t dataSize)
{
    FILE *fp = fopen(fileName, "ab+");
    isOpen(fp);
    fwrite(saveData, dataSize, 1, fp);
    fclose(fp);
}

void menu()
{
    printf("\n*********************************************\n");
    printf("* Designed by KeeneChen using C11           *\n");
    printf("*                                           *\n");
    printf("*        文 件 拆 分/合 并 工 具            *\n");
    printf("*       支持音频、图像、可执行文件等        *\n");
    printf("*                                           *\n");
    printf("*    拆分(s/S) | 合并(m/M) | 退出(任意键)   *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("请输入你的选择: ");
}