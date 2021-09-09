#include <stdio.h>
#include <string.h>
union student
{
    int id;
    int number;
    char name[50];
    double grade;
};

int main(void)
{
    union student bar;
    bar.id = 1;
    bar.grade = 100.0;
    strcpy( bar.name, "C Programming");
    
    printf("%d\n",sizeof(bar.id));
    printf("%d\n",sizeof(bar));
    printf("%d\n",sizeof(bar.name));
    return 0;
}