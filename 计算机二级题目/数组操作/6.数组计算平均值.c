/**
* Author:   hellochen
* DateTime: 2021.03.24-15:04:57
* Description: 将低于平均分的人数作为函数值返回,将低于平均分的分数放在beow所指的数组中。
* 例如,当 score数组中的数据为10、20、30、40、50、60、70、80、90时,函数返回的人数应该是4, below中的数据应为10、20、30、40
*/

#include <stdio.h>

int fun(int score[], int below[], int m);

int main(void)
{
    int score[] = {10, 20, 30, 40, 50, 60, 70, 80, 90}, below[9];
    int n = 0;

    n = fun(score, below, 9);
    printf("低于平均数人数：%d\n", n);
    printf("低于平均数成绩：");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", below[i]);
    }

    printf("\n");

    return 0;
}

int fun(int score[], int below[], int m)
{
    float av = 0.0;
    int sum = 0, j = 0;

    for (int i = 0; i < m; i++)
        sum += score[i];

    av = (float)sum / m;

    printf("平均数为：%f\n", av);

    for (int i = 0; i < m; i++)
        if (score[i] < av)
            below[j++] = score[i];

    return j;
}