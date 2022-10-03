#include <stdio.h>

int main(void)
{
    struct Student
    {
        char name[20];
        int age;
        float score;
    } stu1 = {"张三", 18, 94.3};

    struct Student stu2 = {
        .name = "李四",
        .age = 19,
        .score = 99.3};

    printf("name:%s age:%d score:%f\n", stu1.name, stu1.age, stu1.score);
    printf("name:%s age:%d score:%f\n", stu2.name, stu2.age, stu2.score);

    return 0;
}
