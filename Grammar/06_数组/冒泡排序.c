#include <stdio.h>

int main(void)
{
    int arr[5];
    int lenth = sizeof(arr) / sizeof(arr[0]);

    printf("请输入五个整数进行排序：\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("排序前：");
    for (int i = 0; i < lenth; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n排序后：");

    for (int i = 0; i < lenth - 1; i++) // 比较的轮数
    {
        for (int j = 0; j < lenth - 1 - i; j++) // 每一轮比较的次数，且都需要减1
        {
            if (arr[j] > arr[j + 1]) // 交换数据
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < lenth; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}