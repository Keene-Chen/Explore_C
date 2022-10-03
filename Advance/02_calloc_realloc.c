#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_01(void)
{
    int* p = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }

    int* q = calloc(10, sizeof(int));
    for (int i = 0; i < 10; i++) {
        printf("%d\n", q[i]);
    }

    free(p);
    p = NULL;
    free(q);
    q = NULL;
}

void test_02(void)
{
    int* p = calloc(10, sizeof(int));
    for (size_t i = 0; i < 10; i++)
        p[i] = i + 1;

    // 重新分配内存
    int* q = realloc(p, sizeof(int) * 20);
    printf("%d\n", p);
    printf("%d\n", q);

    // realloc后新的内存空间不会置零
    for (size_t i = 0; i < 20; i++)
        printf("%d ", q[i]);
    printf("\n");

    // 重新赋值并打印
    for (size_t i = 0; i < 20; i++)
        p[i] = i + 1;
    for (size_t i = 0; i < 20; i++)
        printf("%d ", q[i]);
    printf("\n");

    // 如果realloc后内存空间比之前小会释放掉后面的内存
    int* r = realloc(q, sizeof(int) * 5);
    for (size_t i = 0; i < 5; i++)
        printf("%d ", r[i]);
    printf("\n");
    // !error printf("%d\n", r[5]);

    free(q);
}

int main(void)
{
    // test_01();
    test_02();

    return 0;
}