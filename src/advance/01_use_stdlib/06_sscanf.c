#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 跳过数据
void test_01(void)
{
    char buf[1024] = { 0 };
    //跳过前面的数字
    //匹配第一个字符是否是数字，如果是，则跳过
    //如果不是则停止匹配
    sscanf("123456aaaa", "%*d%s", buf);
    printf("buf:%s\n", buf);
}

// 2. 读取指定宽度数据
void test_02(void)
{
    char buf[1024] = { 0 };
    //跳过前面的数字
    sscanf("123456aaaa", "%7s", buf);
    printf("buf:%s\n", buf);
}

// 3. 匹配a-z中任意字符
void test_03(void)
{
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符，判断字符是否是a-z中的字符，如果是匹配
    //如果不是停止匹配
    sscanf("abcdefg123456", "%[a-z]", buf);
    printf("buf:%s\n", buf);
}

// 4. 匹配aBc中的任何一个
void test_04(void)
{
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符是否是aBc中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("abcdefg123456", "%[aBc]", buf);
    printf("buf:%s\n", buf);
}

// 5. 匹配非a的任意字符
void test_05(void)
{
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符是否是aBc中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("bcdefag123456", "%[^a]", buf);
    printf("buf:%s\n", buf);
}

// 6. 匹配非a-z中的任意字符
void test_06(void)
{
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符是否是aBc中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("123456ABCDbcdefag", "%[^a-z]", buf);
    printf("buf:%s\n", buf);
}

int main(void)
{
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();

    return 0;
}