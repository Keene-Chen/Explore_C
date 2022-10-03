#include <stdio.h>

double fun(int a[], int *yy);

int main(void)
{
    int a[] = {1101, 1202, 1303, 1404, 1505, 2611, 2712, 2813, 2914, 3202, 4222};
    int yy = 0;
    double av = 0;
    av = fun(a, &yy);
    printf("%d %f", yy, av);
    return 0;
}

double fun(int a[], int *yy)
{
    double js = 0, es = 0;
    int k1 = 0, k2 = 0;
    for (int i = 0; i < 11; i++)
    {
        if (a[i] % 2 == 1)
        {
            k1++;
            js += a[i];
        }
        else
        {
            k2++;
            es += a[i];
        }
    }

    if (js > es)
    {
        *yy = k1;
        return js / k1;
    }
    else
    {
        *yy = k2;
        return es / k2;
    }
}