#include <stdio.h>

int main(void)
{
    int arr[3][3] = {1, 9, 7, 2, 3, 8, 4, 5, 6};
    printf("%d\n", arr[3][3]);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            arr[j][i] = arr[j][i] * 2;
            printf("%d", arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}