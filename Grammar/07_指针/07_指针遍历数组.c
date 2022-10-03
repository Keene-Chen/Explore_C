/**
 * Author     : KeeneChen
 * DateTime   : 2022.07.20-14: 33: 28
 * Description: 07_指针遍历数组
 */
#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int *p    = arr;

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(p + i));
    }

    return 0;
}