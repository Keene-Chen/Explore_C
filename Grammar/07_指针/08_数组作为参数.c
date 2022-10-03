/**
 * Author     : KeeneChen
 * DateTime   : 2022.07.20-15: 18: 43
 * Description: 08_数组作为参数
 */
#include <stdio.h>

int add(int arr[][2], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int add2(int row, int col, int arr[row][col])
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int add3(int arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    int arr[][2] = {1, 2, 3, 4};
    printf("%d\n", add(arr, 2));
    printf("%d\n", add2(2, 2, arr));
    printf("%d\n", add3((int[]){1, 2, 3, 4, 5}, 5));

    return 0;
}