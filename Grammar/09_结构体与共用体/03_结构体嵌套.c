#include <stdio.h>

int main(void)
{
    struct Student
    {
        char name[20];
        int age;
        float score;
    };

    struct Class
    {
        int number;
        struct Student stu;
    };

    struct Student stu_arr[3] = {
        {"张三", 18, 93.4},
        {"李四", 19, 95.4},
        {.name = "王五", .age = 18, .score = 94.9}};
    struct Class class =
        {
            .number = 1,
            .stu = {"张三", 18, 93.4}};

    printf("class:%d name:%s age:%d score:%f\n",
           class.number, class.stu.name, class.stu.age, class.stu.score);

    return 0;
}