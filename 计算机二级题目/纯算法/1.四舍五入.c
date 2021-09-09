/**
* Author:   hellochen
* DateTime: 2021.03.22-18:16:52
* Description: 该函数的功能是:使变量h中的值保留两位小数,并对第三位进行四舍五入规定h中的值为正数
* 例如,若h值为1234.567,则函数返回1234.570000若h值为1234.564,则函数返回1234.560000
*/

#include <stdio.h>

double fun(double h);

int main(void)
{
    double a = 123.452;
    printf("%f\n", fun(a));
    return 0;
}

double fun(double h)
{
    h = (int)(h * 100 + 0.5) / 100.0;

    return h;
}