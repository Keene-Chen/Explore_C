#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int age;
    double (*add)(double x, double y);
    double (*sub)(double x, double y);
    double (*mul)(double x, double y);
    double (*division)(double x, double y);
} test_t;

static double add(double x, double y)
{
    return x + y;
}

static double sub(double x, double y)
{
    return x - y;
}

static double mul(double x, double y)
{
    return x * y;
}

static double division(double x, double y)
{
    return x / y;
}

int main(void)
{
    test_t test = {
        .add      = add,
        .sub      = sub,
        .mul      = mul,
        .division = division,
    };

    printf("%f\n", test.add(1, 2));
    printf("%f\n", test.sub(1, 2));
    printf("%f\n", test.mul(1, 2));
    printf("%f\n", test.division(1, 2));

    return 0;
}