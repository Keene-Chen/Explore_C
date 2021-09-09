#include <stdio.h>
#include <string.h>

#define N 3 // 数组长度

typedef struct // 结构体存储学生信息
{
    char num[10];
    int score;
} STU;

void fun(STU a[], STU *p); // 指针带回最小值

int main(void)
{
    STU a[N] = {{"A", 81}, {"B", 89}, {"C", 66}}, m;

    // 遍历学生信息
    for (int i = 0; i < N; i++)
    {
        printf("NUM=%s SCORE=%d\n", a[i].num, a[i].score);
    }

    fun(a, &m);

    printf("Lowest score : %s , %d\n", m.num, m.score);
}

void fun(STU a[], STU *p)
{
    *p = a[0];
    for (int i = 0; i < N; i++)
    {
        if ((p->score) > a[i].score)
        {
            *p = a[i];
        }
    }
}