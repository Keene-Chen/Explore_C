#include <stdio.h>

int main(void)
{
    int i, j, temp;

    double arr[3][3] = {1, 2, 5,
                        1, 2, 1,
                        1, 2, 1};

    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            temp = arr[i][j];
            arr[j][i] = arr[i][j];
            arr[j][i] = temp;
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}