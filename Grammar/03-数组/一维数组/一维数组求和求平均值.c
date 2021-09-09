#include <stdio.h>

int main(void)
{
    float arr[5] = {1.2, 2.9, 3.6, 4.0, 6.5};

    int lenth = 0;
    lenth = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    float avg = 0.0;
    for (int i = 0; i < lenth; i++)
        sum += arr[i];
    avg = (float)sum / lenth;

    printf("sum=%d,avg=%f", sum, avg);

    return 0;
}