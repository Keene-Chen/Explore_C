#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 505, 6, 4};
    int *p = arr;

    for (int i = 0; i < 5 - 1; i++) // 比较的轮数
    {
        for (int j = 0; j < 5 - 1 - i; j++) // 每一轮比较的次数，且都需要减1
        {
            if (*(p + j) > *(p + j + 1)) // 交换数据
            {
                int temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}
