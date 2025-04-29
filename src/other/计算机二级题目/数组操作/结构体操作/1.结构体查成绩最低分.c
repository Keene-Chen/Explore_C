/**
* Author:   hellochen
* DateTime: 2021.03.22-18:12:03
* Description: 已知学生的记录由学号和学习成绩构成,N名学生的数据已存入结构体数组中。
* 请编写函数,该函数的功能是:找出成绩最低的学生记录,通过形参返回主函数规定只有一个最低分)。已给出函数的首部,请完成该函数。
*/

#include <stdio.h>
#define N 3

typedef struct
{
    char number[10];
    int score;
} STU;

void fun(STU student[], STU *p);

int main(void)
{
    STU student[N] = {{"A", 12}, {"B", 52}, {"C", 92}}, lowest;

    for (int i = 0; i < N; i++)
    {
        printf("%s %d\n", student[i].number, student[i].score);
    }

    fun(student, &lowest);
    printf("最低分成绩：%d\n", lowest.score);

    return 0;
}

void fun(STU student[], STU *p)
{
    *p = student[0];
    for (int i = 0; i < N; i++)
    {
        if ((p->score) > student[i].score)
        {
            *p = student[i];
        }
    }
}