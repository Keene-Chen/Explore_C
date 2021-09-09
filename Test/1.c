#include <stdio.h>

typedef struct
{
    char *name;
    int age;
    float score;
} Student;

typedef struct
{
    char *name;
    Student sArray[5];
} Teacher;

void allocateSpace(Teacher tArray[], int len);
void showTeacher(Teacher tArray[], int len);

int main(void)
{
    Teacher tArray[3];

    int len = sizeof(tArray) / sizeof(Teacher);

    allocateSpace(tArray, len);
    showTeacher(tArray, len);

    return 0;
}

void allocateSpace(Teacher tArray[], int len)
{
    char *tName = "教师";
    char *sName = "学生";
    char *nameSeed = "ABCDE";

    for (int i = 0; i < len; i++)
    {
        tArray[i].name = tName + nameSeed[i];
        for (int j = 0; j < 5; j++)
        {
            tArray[i].sArray[j].name = sName + nameSeed[j];
            tArray[i].sArray[j].score = 40;
        }
    }
}
void showTeacher(Teacher tArray[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s", tArray[i].name);
        for (int j = 0; j < 5; j++)
        {
            printf("%s\n", tArray[i].sArray[j].name);
        }
    }
}