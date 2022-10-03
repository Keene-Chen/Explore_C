#include <stdio.h>

typedef struct tagStudent
{
    int score : 8;
    int age : 1;
} Student;

int main(void)
{
    Student s = {5, 1};
    printf("%d,%d\n", sizeof(Student), sizeof(Student));
    return 0;
}