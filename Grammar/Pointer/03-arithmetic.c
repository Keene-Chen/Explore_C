#include <stdio.h>

const int MAX = 3;
int proin();
int contrast();

int main()
{
     proin();
     contrast();
}

int proin()
{
    int arr[] = {10, 100, 200};
    int i, *ptr, *q;

    /* 指针中的数组地址 */
    ptr = arr; // 数组是一个常量指针
    q = &arr[MAX - 1];
    printf("/* 这是指针的递增 */\n");
    for (i = 0; i < MAX; i++)
    {
        printf("存储地址：arr[%d] = %x\n", i, ptr);
        printf("存储值：arr[%d] = %d\n", i, *ptr);

        /* 移动到下一个位置 */
        ptr++;
    }
    printf("\n/* 这是指针的递减 */\n");
    for (i = MAX; i > 0; i--)
    {
        printf("存储地址：arr[%d] = %x\n", i, q);
        printf("存储值：arr[%d] = %d\n", i, *q);

        /* 移动到下一个位置 */
        q--;
    }

    return 0;
}

int contrast()
{
    int *p, *q, *r;
    int arr[] = {1, 3, 2, 3};

    p = &arr[0];
    q = &arr[1];
    r = &arr[3];

    printf("%p %p %p\n", p, q, r);

    if (p != q) // 如果地址相等则输出
    {
        printf("%d!=%d\n", *p, *q);
    }
    if (*q == *r) // 如果值相等则输出
    {
        printf("%p=%p", q, r);
    }

    if (*p > *q)
    {
        /* code */
    }

    return 0;
}

