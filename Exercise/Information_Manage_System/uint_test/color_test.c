/**
 * Author:   KeeneChen
 * DateTime: 2022.02.06-21:11:14
 * Description: color module uint testing
 * command: xmake && xmake r color
 */

#include <stdio.h>
#include "tools/color.h"

#define COLOR_TEST(x, y) printf("%s%s%s\n", x, y, RESET);

int main(void)
{
    COLOR_TEST(FRONT_BLACK, "这是黑色前景色");
    COLOR_TEST(FRONT_RED, "这是红色前景色");
    COLOR_TEST(FRONT_GREEN, "这是绿色前景色");
    COLOR_TEST(FRONT_YELLOW, "这是黄色前景色");
    COLOR_TEST(FRONT_BLUE, "这是蓝色前景色");
    COLOR_TEST(FRONT_PURPLR, "这是紫色前景色");
    COLOR_TEST(FRONT_DARKGREEN, "这是深绿色前景色");
    COLOR_TEST(FRONT_WHITE, "这是白色前景色");
    COLOR_TEST(BACK_BLACK, "这是黑色后景色");
    COLOR_TEST(BACK_RED, "这是红色后景色");
    COLOR_TEST(BACK_GREEN, "这是绿色后景色");
    COLOR_TEST(BACK_YELLOW, "这是黄色后景色");
    COLOR_TEST(BACK_BLUE, "这是蓝色后景色");
    COLOR_TEST(BACK_PURPLR, "这是紫色后景色");
    COLOR_TEST(BACK_DARKGREEN, "这是深绿色后景色");
    COLOR_TEST(BACK_WHITE, "这是白色后景色");
    COLOR_TEST(BOLD, "这是粗体");
    COLOR_TEST(UNDERLINE, "这是下划线");
    COLOR_TEST(TWINKLING, "这是闪烁");
    COLOR_TEST(REVERSE, "这是反转");
    COLOR_TEST(HIDE, "这是隐藏");

    return 0;
}