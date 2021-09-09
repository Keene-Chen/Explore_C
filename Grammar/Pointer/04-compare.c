#include <stdio.h>

int main(void)
{

    int *p, *q, *r;
    int arr[3];
    int max = 0, min = 0;

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);
    }

    p = &arr[0];
    q = &arr[1];
    r = &arr[2];

    printf("%p %p %p\n", p, q, r);

    if (*p < *q)
    {
        max = *q;
        min = *p;
    }else
    {
        max = *p;
        min = *q;
    }
    
    if (max < *r)
    {
        max = *r;
    }

    if (min > *r)
    {
        min = *r;
    }

    printf("max=%d,min=%d", max, min);

    return 0;
}