#include <stdio.h>

#define N 3
// int Transpose();
int Corner(int arr[N][N], int m);

int arr[N][N] = {1, 1, 1,
                 1, 2, 1,
                 1, 1, 1};

int main(void)
{
    int sum = 0;
    int sum1 = 0;
    float average = 0;

    /*  for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    } */

    for (int i = 0; i < N; i++)
    {
        sum += arr[i][i];
        sum1 += arr[i][N - i - 1];
        average = sum / 3;
    }

    printf("%d\n%d\n", sum, sum1);
    printf("%f", average);

    Corner(arr[N][N], N);
    return 0;
}
/* Transpose()
{
    int temp;
    temp = arr[i][j];
    arr[i][j] = arr[j][i];
    arr[j][i] = temp;
} */
int Corner(int arr[][N], int m)
{

    int i, j;
    for (j = 0; j < N; j++)
    {
        for (i = 0; i <= j; i++)
        {
            arr[i][j] = arr[i][j] * m;
            printf("%d", arr[i][j]);
        }
    }
}