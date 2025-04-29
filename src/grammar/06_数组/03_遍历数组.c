/**
 * Author:   KeeneChen
 * DateTime: 2022.07.19-12:16:53
 * Description: 遍历数组
 */
#include <stdio.h>

int main(void)
{
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < 12; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
