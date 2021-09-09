/**
* Author:   hellochen
* DateTime: 2021.03.25-15:55:31
* Description: 冒泡排序
*/

#include <stdio.h>

void fun(int arr[], int len);

int main(void)
{
    int arr[] = {13, 25, 39, 4, 5, 6};

    int len = sizeof(arr) / sizeof(arr[0]);

    fun(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void fun(int arr[], int len)
{
    int temp = 0;

    for (int i = 0; i < len - 1; i++) // 外循环为排序趟数，len个数进行len-1趟
    {
        for (int j = 0; j < len - 1 - i; j++) // 内循环为每趟比较的次数，第i趟比较len-i次
        {
            if (arr[j] > arr[j + 1]) // 相邻元素比较，若逆序则交换（升序为左大于右，降序反之）
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}