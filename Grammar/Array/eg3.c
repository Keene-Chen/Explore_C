#include <stdio.h>

#define N 3

int main(void)
{
    int i, j, k, sum;

    double arr[3][3] = {1, 2, 5,
                        1, 2, 1,
                        1, 2, 1};

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
            {
                sum += arr[i][j];
                //k++;
            }
        }
    }
    printf("%d\n", sum);

    return 0;
}