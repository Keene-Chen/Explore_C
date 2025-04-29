/**
 * Author     : KeeneChen
 * DateTime   : 2022.07.20-12: 52: 40
 * Description: 05_const_修饰指针
 */
#include <stdio.h>

int main(void)
{
    // 修饰变量
    const int a = 10;
    int   *ap   = &a;
          *ap   = 20;
    printf("%d\n", a);

    //修饰指针
    // 1. const int *ptr
    // int b = 10, c = 20;
    // const int *ptr = &b;
    // // *ptr = 30;
    // ptr = &c;
    // printf("ptr value: %d\n", *ptr);

    // 2. int const *ptr
    // int b = 10, c = 20;
    // int const *ptr = &b;
    // // *ptr = 30;
    // ptr = &c;
    // printf("ptr value: %d\n", *ptr);

    // 3. int *const ptr
    // int b = 10, c = 20;
    // int *const ptr = &b;
    // *ptr = 30;
    // // ptr = &c;
    // printf("ptr value: %d\n", *ptr);

    // 4. const int * const ptr
    int   b              = 10, c = 20;
    const int *const ptr = &b;
    // *ptr = 30;
    // ptr = &c;
    printf("ptr value: %d\n", *ptr);

    return 0;
}