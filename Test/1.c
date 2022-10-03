#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 10;
    int* p = (int*)malloc(sizeof(int));
    *p = 20;

    printf("%d %d\n", a, *p);
    free(p);

    return 0;
}