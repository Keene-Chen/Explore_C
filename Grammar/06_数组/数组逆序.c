/**
 * Author:   KeeneChen
 * DateTime: 2021.10.21-14:34:55
 * Description: 数组逆序
 * Essence: 数组第0个元素和最后一个元素交换，然后向中间移动直到第0个元素下标和最后一个元素下标相遇时结束。
 */

#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}