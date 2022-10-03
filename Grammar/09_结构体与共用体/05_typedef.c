#include <stdio.h>

int main(void)
{
    typedef unsigned int uint;
    typedef unsigned char uchar;

    uint foo = 10;
    uchar bar = 'a';

    printf("%d %c\n", foo, bar);

    typedef struct tagStudent
    {
        char name[20];
        int age;
        float score;
    } Student;

    typedef struct
    {
        char name[20];
        int age;
        float score;
    } Teacher;

    Student stu = {"张三", 18, 93.4};
    Teacher tea = {"张三", 18, 93.4};

    return 0;
}