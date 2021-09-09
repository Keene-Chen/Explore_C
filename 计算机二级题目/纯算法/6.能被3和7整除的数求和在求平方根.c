/**
* Author:   hellochen
* DateTime: 2021.03.24-16:36:25
* Description: 求小于形参n同时能被3与7整除的所有自然数之和的平方根,并作为函数值返回例如,
* 若n为1000时,程序输出应为:s=153909064
* Remark: libz,librt,libm,libc,在Linux环境下使用以下库时需要在gcc后面加对应参数，gcc 1.c -o 1 -lm
* 压缩库（Z）
* 实时库（real time）
* 数学库（math）
* 标准C库（C lib）
*/

#include <stdio.h>
#include <math.h>

double fun(int n);

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("%f\n", fun(n));
    return 0;
}

double fun(int n)
{
    double sum = 0;
    for (int i = 0; i <= n; i++) // 在n范围内遍历
    {
        if ((i % 3 == 0) && (i % 7 == 0)) // 满足能被3和7整除的数
        {
            sum += i;
        }
    }

    return sqrt(sum); // 使用math.h文件中的求根函数算平方根
}