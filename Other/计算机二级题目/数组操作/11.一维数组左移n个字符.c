/**
* Author:   hellochen
* DateTime: 2021.03.25-21:27:43
* Description: 一维数组左移n个字符
*/

#include <stdio.h>

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ch = 0;

    for (int i = 0; i <= 4; i++)
    {
        ch = a[0];
        int j;
        for (j = 1; j < 9; j++)
        {
            a[j - 1] = a[j];
        }
        a[j - 1] = ch;
    }

    for (int i = 0; i < 9; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}