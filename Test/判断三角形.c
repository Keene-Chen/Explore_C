#include <stdio.h>

int main(void)
{
    int a = 0, b = 0, c = 0;
    scanf("%d%d%d", &a, &b, &c);
    
    ((a + b > c) && (b + c > a) && (a + c > b)) ? printf("yes") : printf("no");

    return 0;
}