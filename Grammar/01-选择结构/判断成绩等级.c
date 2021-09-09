#include <stdio.h>
int main()
{
    int a, b;
    printf("请输入100以内的分数：");
    scanf("%d", &a);

    if (a > 100 || a < 0)
        printf("请输入100以内的数！");
    else if (a >= 90 && a <= 100)
        b = 1;
    else if (a >= 80 && a <= 89)
        b = 2;
    else if (a >= 70 && a < 80)
        b = 3;
    else if (a >= 60 && a < 70)
        b = 4;
    else if (a < 60)
        b = 5;

    switch (b)
    {
    case 1:
        printf("your score is A");
        break;
    case 2:
        printf("your score is B");
        break;
    case 3:
        printf("your score is C");
        break;
    case 4:
        printf("your score is D");
        break;
    case 5:
        printf("your score is E");
        break;
    }
    return 0;
}