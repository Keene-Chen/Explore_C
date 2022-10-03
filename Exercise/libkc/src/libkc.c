#include "libkc.h"

/**
 * @brief 产生double随机数
 * @param  min 区间最小值
 * @param  max 区间最大值
 * @return double 类型的随机数
 */
double KC_GetRandData(int min, int max)
{
    double m1 = (double)(rand() % 101) / 101;
    // 计算 0，1之间的随机小数,得到的值域近似为(0,1)
    min++;
    //将 区间变为(min+1,max),
    double m2 = (double)((rand() % (max - min + 1)) + min);
    //计算 min+1,max 之间的随机整数，得到的值域为[min+1,max]
    m2 = m2 - 1;
    //令值域为[min,max-1]
    return m1 + m2;
    //返回值域为(min,max),为所求随机浮点数
}

// 加法
double KC_Add(double num1, double num2)
{
    return num1 + num2;
}

// 字符串截取函数
char *KC_StrCutLeft(char *destination, const char *source, int n)
{
    char *p = source;
    char *q = destination;
    int len = strlen(source);
    if (n > len)
        n = len;
    while (n--)
        *(q++) = *(p++);
    *(q++) = '\0';
    return destination;
}

char *KC_StrCutRight(char *destination, const char *source, int n)
{
    char *p = source;
    char *q = destination;
    int len = strlen(source);
    if (n > len)
        n = len;
    p += (len - n);
    while (*(q++) = *(p++))
        ;
    return destination;
}

char *KC_StrCutSub(char *destination, const char *source, int start, int len)
{
    char *p = destination;
    char *q = source;
    int length = strlen(source);
    if (start >= length || start < 0)
        return NULL;
    if (len > length)
        len = length - start;
    q += start;
    while (len--)
    {
        *(p++) = *(q++);
    }
    *(p++) = '\0';
    return destination;
}