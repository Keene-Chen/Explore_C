#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_01(void)
{
    char str[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    printf("%s\n", str);

    char str1[64] = { 'h', 'e', 'l', 'l', 'o' };
    printf("%s\n", str1);

    char str2[] = "hello";
    // sizeof 计算数组长度包含'\0' strlen 不包含'\0'
    printf("sizeof str2:%lu\n", sizeof(str2));
    printf("strlen str2:%lu\n", strlen(str2));

    char str3[] = "hello\0world";
    printf("%s\n", str3); // hello
    printf("sizeof str3:%lu\n", sizeof(str3)); // 12
    printf("strlen str3:%lu\n", strlen(str3)); // 5

    //再请问下面输入结果是多少？sizeof结果是多少？strlen结果是多少？
    char str4[] = "hello\012world";
    printf("%s\n", str4); // hello \n world
    printf("sizeof str4:%lu\n", sizeof(str4)); // 12
    printf("strlen str4:%lu\n", strlen(str4)); // 11
}

// 字符串拷贝
// 1.使用[]实现
void string_copy_01(char* dest, const char* src)
{
    int len = strlen(src);
    for (int i = 0; i < len; i++)
        dest[i] = src[i];
    // dest[len] = 0;
    dest[len] = '\0';
}

// 2.利用指针
void string_copy_02(char* dest, const char* src)
{
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    // *dest = 0;
    *dest = '\0';
}

// 3.利用指针
void string_copy_03(char* dest, const char* src)
{
    while ((*dest++) = (*src++))
        ;
    // int a = 1;
    // while (a = 0) {
    //     printf("test\n");
    // }
}

void test_02(void)
{
    const char* str = "hello world";
    char buf[1024] = { 0 };
    // string_copy_01(buf, str);
    // string_copy_02(buf, str);
    string_copy_03(buf, str);
    printf("%s\n", buf);
}

int main(void)
{
    // test_01();
    test_02();

    return 0;
}