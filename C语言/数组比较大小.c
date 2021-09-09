/**
* Author:   hellochen
* DateTime: 2021.05.11-17:19:21
* Description: 数组比较大小并保存下标
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a[10];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % 100;
    }

    int max = a[0], max_index = 0, min = a[0], min_index = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("%-3d", a[i]);
        if (max < a[i])
        {
            max = a[i];
            max_index = i;
        }
        if (min > a[i])
        {
            min = a[i];
            min_index = i;
        }
    }
    printf("\n%d,%d,%d,%d", max, max_index, min, min_index);

    return 0;
}