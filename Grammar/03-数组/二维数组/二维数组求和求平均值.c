#include <stdio.h>

int main(void)
{
    int arr[2][3];
    int sum = 0;
    float avg = 0.0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
    }
    avg = (float)sum / 6;
    printf("%d,%f", sum, avg);

    return 0;
}