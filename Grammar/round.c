#include <stdio.h>

int main(void)
{
    float h;
    int temp ;

    h = 123.564;
    temp = (int)(h*1000+5)/10;
    printf("%f",(float)temp/100.0);
    return 0;
}