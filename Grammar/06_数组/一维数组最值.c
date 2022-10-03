#include <stdio.h>

int main(void)
{
    int arr[5] = {1, 2, 4, 3, 5};
    int max, min = arr[0];
    int lenth = 0;
    lenth = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < lenth; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("max=%d,min=%d", max, min);

    return 0;
}