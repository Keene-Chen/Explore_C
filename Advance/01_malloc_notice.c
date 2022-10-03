/**
 * Author     : KeeneChen
 * DateTime   : 2022.09.12-12:32:37
 * Description: malloc_notice 主调函数没有分配内存，被调函数需要用更高一级的指针去修饰低级指针，进行分配内存
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate_space_01(char* pp)
{
    char* temp = malloc(100);
    memset(temp, 0, 100);
    strcpy(temp, "hello");
    pp = temp;
}

void test_01(void)
{
    char* p = NULL;
    allocate_space_01(p);
    printf("%s\n", p);
}

void allocate_space_02(char** pp)
{
    char* temp = malloc(100);
    memset(temp, 0, 100);
    strcpy(temp, "hello");
    *pp = temp;
}

void test_02(void)
{
    char* p = NULL;
    allocate_space_02(&p);
    printf("%s\n", p);
}

int main(void)
{
    test_01();
    test_02();

    return 0;
}