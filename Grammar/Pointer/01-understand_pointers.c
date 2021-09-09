#include <stdio.h>

int main(void)
{
    int foo = 10;
    int *p;    // 定义int型指针变量
    float *q;  // 定义float型指针变量
    double *r; // 定义double型指针变量
    char *s;   // 定义char型指针变量

    p = &foo;             // 将变量的地址赋值给指针变量
    *p = 20;              // 通过*访问指针的值，可以修改变量的值
    printf("%p\n", &foo); // &变量名 取出变量的地址
    printf("%p\n", p);    // %p 以十六进制打印地址，不足补0
    printf("%d", *p);
}