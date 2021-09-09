#include <stdio.h>

int main(void)
{
    int arr[5] = {6, 5, 2, 4, 8};
    int lenth = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < lenth - 1; i++) // 比较的轮数
    {
        for (int j = i + 1; j < lenth; j++)
        {
            if (arr[j] < arr[i]) // 交换数据
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < lenth; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}