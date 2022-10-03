#include <stdio.h>

int add(int foo, int bar)
{
    return foo + bar;
}

// 函数指针作形参，回调函数
int getValue(int (*pf)(int a, int b), int c, int d)
{
    return add(c, d);
}

int main(void)
{
    int res = getValue(add,10,20);
    printf("%d\n",res);

    return 0;
}