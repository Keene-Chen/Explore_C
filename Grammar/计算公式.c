/**
 * 根据下列公式计算s，计算结果作为函数值返回；n通过形参传入。
 * S=1+1/(1+2)+1/(1+2+3)...+1/(1+2+3...+n)
*/
#include <stdio.h>
float fun(int n);

int main(void)
{
	int n;
	float s;
	scanf("%d", &n);
	s = fun(n);
	printf("%f", s);
	return 0;
}

float fun(int n)
{
	float s = 1.0, sum = 1.0;
	for (int i = 2; i <= n; i++)
	{
		sum += i;
		s += 1.0/ sum;
	}
	return s;
}