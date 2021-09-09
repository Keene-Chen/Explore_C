#include <stdio.h>

/**
 * 在数学上，斐波那契数列以如下被以递推的方法定义：
 * F(0)=0，F(1)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 2，n ∈ N*）
*/
int main(void)
{
    int arr[10];
    arr[0] = 1, arr[1] = 1;
    for (int i = 2; i < 10; i++)
    {
        arr[i] = arr[i - 2] + arr[i - 1];
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}