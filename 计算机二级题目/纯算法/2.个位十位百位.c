/**
* Author:   hellochen
* DateTime: 2021.03.24-14:31:51
* Description: 将a、b中的两个正整数合并形成一个新的整数放在中,合并的方式是
* 将a中的十位和个位数依次放在变量的十位和千位上,b中的十位和个位数依次放在变量c的个位和百位上
* 例如,当a=45,b=12。调用该函数后,c=5241。
*/

#include <stdio.h>

void fun(int a, int b, long *c);

int main(void)
{
    int num1 = 0, num2 = 0;
    long p = 0;

    scanf("%d %d", &num1, &num2);
    fun(num1, num2, &p);
    printf("%ld\n", p);
    return 0;
}

void fun(int a, int b, long *c)
{
    // 取个位%10，取十位/10%10，取百位/100%10
    *c = (a % 10) * 1000 + (b % 10) * 100 + (a / 10 % 10) * 10 + (b / 10);
}