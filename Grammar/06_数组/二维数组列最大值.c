#include <stdio.h>

int main(void)
{
    int arr[2][3] = {1, 9, 3,
                     4, 5, 6};
    int max = arr[0][0];

    for (int j = 0; j < 3; j++)
    {
        max = arr[0][j];
        for (int i = 0; i < 2; i++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
        printf("max=%d ", max);
    }

    return 0;
}