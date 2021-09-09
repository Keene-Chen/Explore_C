#include <stdio.h>

int main(void)
{
    float arr[5];
    int lenth = sizeof(arr) / sizeof(arr[0]);
    float sum = 0.0, avg = 0.0;

    // 输入5个数
    printf("请输入5个数进行打分！（去掉最高最低分取平均值）\n");
    for (int i = 0; i < lenth; i++)
    {
        scanf("%f", &arr[i]);
    }

    // 选择排序
    for (int i = 0; i < lenth - 1; i++)
    {
        for (int j = i + 1; j < lenth; j++)
        {
            if (arr[j] < arr[i])
            {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // 算平均值
    for (int i = 1; i < lenth - 1; i++)
    {
        sum += arr[i];
    }
    avg = sum / (lenth - 2);

    printf("%.2f", avg);

    return 0;
}