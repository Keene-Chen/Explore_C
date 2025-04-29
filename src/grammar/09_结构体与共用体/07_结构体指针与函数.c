#include <stdio.h>

typedef struct tagStudent
{
    char name[20];
    int age;
    float score;
} Student;

void show(Student stu)
{
    printf("name:%s age:%d score:%.2f\n", stu.name, stu.age, stu.score);
}

void show2(Student *pstu)
{
    printf("name:%s age:%d score:%.2f\n", pstu->name, pstu->age, pstu->score);
}

int main(void)
{
    Student stu = {"zhangsan", 18, 93.4};
    show(stu);
    show2(&stu);

    return 0;
}