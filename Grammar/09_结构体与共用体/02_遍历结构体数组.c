#include <stdio.h>

int main(void)
{
    struct Student
    {
        char name[20];
        int age;
        float score;
    };

    struct Student stu_arr[3] = {
        {"张三", 18, 93.4},
        {"李四", 19, 95.4},
        {.name = "王五", .age = 18, .score = 94.9}};

    for (int i = 0; i < 3; i++)
    {
        printf("name:%s age:%d score:%f\n", stu_arr[i].name, stu_arr[i].age, stu_arr[i].score);
    }

    return 0;
}