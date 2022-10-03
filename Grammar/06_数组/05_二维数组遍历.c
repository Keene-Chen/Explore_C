/**
 * Author:   KeeneChen
 * DateTime: 2022.07.19-15:10:00
 * Description: 二维数组遍历
 */

#include <stdio.h>

int main(void)
{
    int arr[3][4] = {1, 2, 3, 4,
                     5, 6, 7, 8,
                     9, 10, 11, 12};

    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
