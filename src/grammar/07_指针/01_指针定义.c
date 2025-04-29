/**
 * Author     : KeeneChen
 * DateTime   : 2022.07.20-09: 39: 03
 * Description: 01_指针定义
 */
#include <stdio.h>

int main(void)
{
    int   a = 10;
    float b = 12.3;
    char  c = 'c';

    int   *ap = &a;
    float *bp = &b;
    char  *cp = &c;

    printf("%p %p %p\n", ap, bp, cp);
    printf("%d %.2f %c\n", *ap, *bp, *cp);

    return 0;
}