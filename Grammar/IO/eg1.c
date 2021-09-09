#include <stdio.h>
#include <stdlib.h>

struct foo
{
    int a;
    float b;
    double c;
    unsigned int d;
    char e;
    char arr[50];
}bar = {-1,1.0,2.0,1,65,"hello"};


int main(void)
{   
    printf("%d\n",bar.a);
    printf("%o\n",bar.a);
    printf("%x\n",bar.a);
    printf("%u\n",bar.d);
    printf("%c\n",bar.e);
    printf("%s\n",bar.arr);
    printf("%f\n",bar.b);
    printf("%e\n",bar.a);
    printf("%g\n",bar.a);
    system("CLS");
    return 0;
}