/**
 * Author:   KeeneChen
 * DateTime: 2022.07.19-12:12:53
 * Description: 获取数组大小
 */
#include <stdio.h>

int main(void)
{
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int len = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", len);

    return 0;
}
