/**
 * @file    : attribute_a.c
 * @author  : KeeneChen <keenechen@qq.com>
 * @date    : 2025.04.29-11:29:10
 * @details : attribute_a
 */

#include <stdio.h>
#include "attribute.h"

void __attribute__((weak)) test1(void)
{
    printf("weak\n");
}
