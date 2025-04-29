/**
 * @file    : main.c
 * @author  : KeeneChen <keenechen@qq.com>
 * @date    : 2025.04.29-11:28:05
 * @details : main
 */

#include <stdio.h>
#include "attribute.h"

void test2(int arr[static 2])
{
    printf("%d\n", arr[0]);
}

int main(void)
{
    test1();
    printf("%d\n", __STDC_VERSION__);

    int arr[] = { 1 };
    test2(arr);

    return 0;
}