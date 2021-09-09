#include <stdio.h>
#include <string.h>

struct student
{
    int id;
    int number;
    char name[50];
    char class[50];
    char depart[50];
    double grade;
};

int main(void)
{
    struct student foo;
    struct student *sp;

    foo.id = 1;
    strcpy(foo.name,"adasdasd");
    sp = &foo;
    
    strcpy(sp->name,"123");
    foo = *sp;

    printf("%s\n",foo.name);
    printf("%d\n",foo.id);
    return 0;
}