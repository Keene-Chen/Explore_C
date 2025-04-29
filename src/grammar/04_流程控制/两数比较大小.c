/**
 * @file    : 两数比较大小.c
 * @author  : KeeneChen <keenechen@qq.com>
 * @date    : 2025.04.29-15:13:57
 * @details : 两数比较大小
 */

#include <stdio.h>

int main(void)
{
    int a   = 1;
    int b   = 2;
    int max = 0;

    if (a > b)
        max = a;
    else
        max = b;

    printf("max: %d\n", max);

    (a > b) ? (max = a) : (max = b);
    printf("max: %d\n", max);

    return 0;
}