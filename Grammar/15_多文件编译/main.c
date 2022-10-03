#include "main.h"

int main(void)
{
    extern int a;
    printf("%d", a);
    extern int b;
    printf("%d", b);
    return 0;
}

//  clang .\main.c .\test.c && .\a