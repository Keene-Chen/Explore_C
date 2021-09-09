/**
* Author:   hellochen
* DateTime: 2021.03.23-16:23:05
* Description: 删除一维数组中所有相同的数,使之只剩一个。数组中的数已按由小到大的顺序排列,函数返回删除后数组中数据的个数。
* 例如,若一维数组中的数据是:2223445666677899101010 删除后,数组中的内容应该是2345678910
*/

#include <stdio.h>
#define N 80

int fun(int a[], int n);

int main(void)
{
    int a[N] = {2, 2, 2, 3, 4, 4, 5, 6, 6, 6, 6, 7, 7, 8, 9, 9, 10, 10, 10, 10}, i, n = 20;

    printf("The original data :\n");
    for (i = 0; i < n; i++)
        printf("%3d", a[i]);

    n = fun(a, n);

    printf("\nThe data after deleted :\n");
    for (i = 0; i < n; i++)
        printf("%3d", a[i]);
    printf("\n");
}

int fun(int a[], int n)
{
    int i, j = 1;
    for (i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
            a[j++] = a[i];
    }
    return j;
}