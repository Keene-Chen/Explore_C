/**
* Author:   hellochen
* DateTime: 2021.05.11-17:20:45
* Description: 数组逆序
*/

#include <stdio.h>
#define N 9

int main(void)
{
    int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, temp = 0;

    for (int i = 0; i < N / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[N - i - 1];
        arr[N - i - 1] = temp;
    }

    for (int i = 0; i < N; i++)
        printf("%d", arr[i]);

    return 0;
}