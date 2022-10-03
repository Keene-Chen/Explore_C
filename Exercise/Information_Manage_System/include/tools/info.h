#ifndef __INFO_H__
#define __INFO_H__

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 获取时间
 * @param dest 存储时间的字符串
 */
void GetDate(char *dest);

/**
 * @brief 构造一个ID
 *
 * @param dest 存储ID的字符串
 * @param type ID类型(U,G,O)
 */
void GenID(char *dest, char type);

/**
 * @brief  判断文件是否打开
 * @param  fp 文件指针
 */
void IsOpen(FILE *fp);

// helper macro for print
#define print_header        \
    printf("%s\n", divide); \
    printf("%s\n", header); \
    printf("%s\n", divide);

#define print_divide \
    printf("%s\n", divide);

#endif // __INFO_H__
