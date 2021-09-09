#include <stdio.h>

#define N 3

int main(void)
{
    int i, j, temp;
    int b[N][N];
    int arr[3][3] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++)
        {
           // temp = arr[i][j];
            b[j][i]=arr[i][j];
           // arr[j][i] = temp;
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%2d", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}