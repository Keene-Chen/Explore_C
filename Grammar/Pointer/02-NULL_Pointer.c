#include <stdio.h>

int main(void)
{
    // 当没有变量给指针赋值时可以使用NULL作为初始值
    int *p = NULL;
    printf("%p", p);
    return 0;
}