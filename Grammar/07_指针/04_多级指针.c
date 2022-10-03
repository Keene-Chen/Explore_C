/**
 * Author     : KeeneChen
 * DateTime   : 2022.07.20-10: 33: 55
 * Description: 04_多级指针
 */
#include <stdio.h>

int main(void)
{
    int a      = 10;
    int *p     = &a;
    int **pp   = &p;
    int ***ppp = &pp;

    printf("a address: %p\n", &a);
    printf("p value: %d\n", *p);
    printf("p address: %p\n", p);
    printf("pp value: %d\n", **pp);
    printf("pp address: %p\n", pp);
    printf("ppp value: %d\n", ***ppp);
    printf("ppp address: %p\n", ppp);

    return 0;
}