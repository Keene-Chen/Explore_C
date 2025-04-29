/**
* Author:   hellochen
* DateTime: 2021.05.11-17:11:04
* Description: 1-200内所有包含3的和
*/

#include <stdio.h>

int main(void)
{
    int count = 0;
    for (int i = 1; i <= 200; ++i)
    {
        if (i % 10 == 3 || i / 10 % 10 == 3||i/3==0)
        {
            printf("%d ", i);
            count += i;
        }
    }
    printf("\n%d\n", count);

    return 0;
}