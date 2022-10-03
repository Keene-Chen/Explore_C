/**
 * Author     : KeeneChen
 * DateTime   : 2022.09.09-17:07:33
 * Description: 简易版贪吃蛇 仅Widows
 */

#include "snake.h"

#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    // 去除光标
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize   = sizeof(cci);
    cci.bVisible = FALSE; // TRUE :
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

    // 重随时间种子
    srand((unsigned int)time(NULL));
    init_snake();
    init_food();
    init_wall();
    init_ui();
    play_game();
    show_score();

    // printf("蛇头坐标: x=%d y=%d\n", snake.body[0].x, snake.body[0].y);
    // printf("蛇身坐标: x=%d y=%d\n", snake.body[1].x, snake.body[1].y);
    // printf("食物坐标: x=%d y=%d\n", food.x, food.y);

    system("pause");

    return 0;
}