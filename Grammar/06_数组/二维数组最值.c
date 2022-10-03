#include <stdio.h>

int main(void)
{
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    int max = arr[0][0], min = arr[0][0];

    for (int i = 0; i < 2; i++)
    {
        max = arr[i][0];
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }

    printf("max=%d,min=%d", max, min);

    return 0;
}