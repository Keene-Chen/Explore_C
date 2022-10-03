/**
 * Author     : KeeneChen
 * DateTime   : 2022.07.20-10: 19: 11
 * Description: 03_指针运算
 */
#include <stdio.h>

int main(void)
{
    int a  = 10;
    int *p = &a;

    printf("pointer size: %lu bytes\n", sizeof(p));
    printf("p: %p\n", p);
    printf("p+1: %p\n", p + 1);
    printf("p-1: %p\n", p - 1);
    printf("p++: %p\n", p++);
    printf("++p: %p\n", ++p);
    printf("p--: %p\n", p--);
    printf("--p: %p\n", --p);

    int b   = 10;
    int c   = 20;
    int *bp = &b;
    int *cp = &c;
    printf("%ld\n", bp - cp);

    if (bp > cp)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}