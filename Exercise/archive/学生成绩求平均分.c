#include <stdio.h>

int main(void)
{
    float score[10], sum = 0, avg = 0, max = score[0], min = score[0];

    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &score[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        sum += score[i];
        if (max < score[i])
            max = score[i];

        if (min > score[i])
            min = score[i];
    }
    avg = sum / 10;
    printf("%f,%f,%f", max, min, avg);

    return 0;
}