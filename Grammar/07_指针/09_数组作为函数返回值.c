/**
 * Author     : KeeneChen
 * DateTime   : 2022.07.20-15:39:19
 * Description: 09_数组作为函数返回值
 */
#include <stdio.h>

int *get_array()
{
    static int arr[] = {1, 2, 3};
    return arr;
}

int main(void)
{
    int *p = get_array();
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", *(p + i));
    }

    return 0;
}