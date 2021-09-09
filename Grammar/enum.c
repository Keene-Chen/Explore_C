#include <stdio.h>

// 先定义枚举类型，再定义枚举变量
enum DAY
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};
enum DAY day;

// 定义枚举类型的同时定义枚举变量
enum DAY
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
} day;

// 省略枚举名称，直接定义枚举变量

enum 
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
} day;

int main(void)
{
    // 定义枚举变量
    enum DAY day;
    day = SUN;
    printf("%d\n", day);
}
