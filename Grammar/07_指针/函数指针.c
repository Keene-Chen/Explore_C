#include <stdio.h>

int add(int foo, int bar)
{
    return foo + bar;
}
int sub(int foo, int bar)
{
    return foo - bar;
}
int mul(int foo, int bar)
{
    return foo * bar;
}
int divi(int foo, int bar)
{
    return foo / bar;
}

// 函数指针即指针指向的是函数的入口地址
int (*pf)(int a, int b);
void test_1()
{
    pf = add;
    printf("函数指针：%d\n", pf(10, 20));
}

// 函数指针变量类型,注意大写开头的类型是否为函数指针变量
typedef int (*PF)(int a, int b);
void test_2()
{
    PF ptr = sub;
    printf("函数指针变量类型：%d\n", ptr(10, 20));
}

// 函数指针数组,数组中元素都是函数入口地址
int (*pf1[4])(int a, int b) = {add, sub, mul, divi};
void test_3()
{
    for (int i = 0; i < sizeof(pf1) / sizeof(pf1[0]); i++)
    {
        printf("函数指针数组：%d\n", pf1[i](10, 20));
    }
}

int main(void)
{
    test_1();
    test_2();
    test_3();
    return 0;
}
