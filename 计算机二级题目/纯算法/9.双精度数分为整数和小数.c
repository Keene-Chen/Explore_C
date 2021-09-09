/**
* Author:   hellochen
* DateTime: 2021.03.26-17:37:22
* Description: 把双精度数转换为整数部分和小数部分
* Thought: 把双精度数强转为int就是整数部分，再用原来的数减去整数部分就是小数部分
*/

#include <stdio.h>

int main(void)
{
    double a = 456.123;
    int b = 0;
    b = (int)a; 
    printf("%d %f", b, a - b);
    return 0;
}