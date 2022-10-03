/**
 * Author     : KeeneChen
 * DateTime   : 2022.07.20-13: 33: 23
 * Description: 06_数组指针与指针数组
 */
#include <stdio.h>
#define MAX_SIZE 3

int main(void)
{
    // 数组指针定义
    int arr1[MAX_SIZE] = {1, 2, 3};
    int *p             = arr1;
    printf("arr1 address: %p\n", arr1);
    printf("p address: %p\n", p);

    int a = 1, b = 2, c = 3;
    // 指针数组定义
    int *arr2[MAX_SIZE] = {&a, &b, &c};
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("arr2[%d] address: %p\n", i, arr2[i]);
    }

    return 0;
}