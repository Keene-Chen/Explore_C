/**
 * 输入一个数,组成不重复的三位数 
 */
#include <stdio.h>

int main(void)
{
    int num = 3;
    int count = 0;

    scanf("%d", &num);

    for (int i = 1; i <= num; i++)

        for (int j = 1; j <= num; j++)

            for (int k = 1; k <= num; k++)

                if (i != j && j != k && i != k)
                {
                    printf("%d%d%d ", i, j, k);
                    count++;
                }

    printf("\n共有 %d 种情况。 \n", count);
    return 0;
}