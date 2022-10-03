/**
 * Author:   KeeneChen
 * DateTime: 2022.07.02-14:56:58
 * Description: 获取数据类型极限值
 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("signed char  min_size:[%d],max_size:[%d],size:[%lu]\n", SCHAR_MIN, SCHAR_MAX, sizeof(signed char));
    printf("char   min_size:[%d],max_size:[%d],size:[%lu]\n", CHAR_MIN, CHAR_MAX, sizeof(char));
    printf("short  min_size:[%d],max_size:[%d],size:[%lu]\n", SHRT_MIN, SHRT_MAX, sizeof(short));
    printf("int    min_size:[%d],max_size:[%d],size:[%lu]\n", INT_MIN, INT_MAX, sizeof(int));
    printf("long   min_size:[%ld],max_size:[%ld],size:[%lu]\n", LONG_MIN, LONG_MAX, sizeof(long));
    printf("long long  min_size:[%lld],max_size:[%lld],size:[%lu]\n", LLONG_MIN, LLONG_MAX, sizeof(long long));

    printf("unsigned char    max_size:[%u],size:[%lu]\n", UCHAR_MAX, sizeof(unsigned char));
    printf("unsigned short   max_size:[%u],size:[%lu]\n", USHRT_MAX, sizeof(unsigned short));
    printf("unsigned int     max_size:[%u],size:[%lu]\n", UINT_MAX, sizeof(unsigned int));
    printf("unsigned long    max_size:[%lu],size:[%lu]\n", ULONG_MAX, sizeof(unsigned long));
    printf("unsigned long long    max_size:[%llu],size:[%lu]\n", ULLONG_MAX, sizeof(unsigned long long));
    return 0;
}