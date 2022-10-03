#include <stdio.h>

int main(void)
{
    typedef struct tagStudent
    {
        char name[20];
        int age;
        float score;
    } Student;

    Student stu = {"张三", 18, 93.4};
    // 等价于 struct tagStudent stu = {"张三", 18, 93.4};

    Student *pstu = &stu;
    // 等价于 struct tagStudent *pstu = &stu;

    printf("name:%s age:%d score:%f\n", (*pstu).name, (*pstu).age, (*pstu).score);
    printf("name:%s age:%d score:%f\n", pstu->name, pstu->age, pstu->score);

    return 0;
}