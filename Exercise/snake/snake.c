
/**
 * Author     : KeeneChen
 * DateTime   : 2022.09.09-17:08:12
 * Description: snake
 */

#include "snake.h"

#define _CRT_SECURE_NO_WARNINGS

/* 全局变量 */
// 分数
int score = 0;

// 用户按键的坐标
int kx = 0;
int ky = 0;

// 存储蛇尾坐标
int last_x       = 0;
int last_y       = 0;
int sleep_second = 400;

void init_snake(void)
{
    snake.size      = 2;        // 蛇总大小,蛇头和蛇身
    snake.body[0].x = WIDE / 2; // 蛇头x坐标
    snake.body[0].y = HIGH / 2; // 蛇尾y坐标

    snake.body[1].x = WIDE / 2 - 1; // 蛇身第一节x坐标,+1头朝向左边,-1朝向右边
    snake.body[1].y = HIGH / 2;     // 蛇身第一节y坐标

    return;
}

void init_food(void)
{
    food.x = rand() % WIDE;
    food.y = rand() % HIGH;

    return;
}

void init_ui(void)
{
    COORD coord = { 0 }; // 光标移动的位置

    // 画蛇
    for (int i = 0; i < snake.size; i++) {
        coord.X = snake.body[i].x;
        coord.Y = snake.body[i].y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        if (i == 0) {
            putchar('@');
        }
        else {
            putchar('*');
        }
    }

    // 去除蛇尾
    coord.X = last_x;
    coord.Y = last_y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar(' ');

    // 画食物
    coord.X = food.x; // 0-59
    coord.Y = food.y; // 0-19
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar('#');
}

void play_game(void)
{
    // 默认蛇头移动方向
    char key = 77;

    // 判断蛇撞墙
    while (snake.body[0].x >= 0 && snake.body[0].x < WIDE && snake.body[0].y >= 0 && snake.body[0].y < HIGH) {
        // 更新蛇
        init_ui();

        // 接收用户输入
        /*if (_kbhit()) {
            key = _getch();
        }
        switch (key) {
        case 'w':
            kx = 0;
            ky = -1;
            break;
        case 's':
            kx = 0;
            ky = +1;
            break;
        case 'd':
            kx = +1;
            ky = 0;
            break;
        case 'a':
            kx = -1;
            ky = 0;
            break;
        default:
            break;
        }*/
        if (_kbhit()) {
            key = _getch();
            key = _getch();
        }
        switch (key) {
        case 72:
            kx = 0;
            ky = -1;
            break;
        case 80:
            kx = 0;
            ky = +1;
            break;
        case 77:
            kx = +1;
            ky = 0;
            break;
        case 75:
            kx = -1;
            ky = 0;
            break;
        default:
            break;
        }

        // 蛇撞自身身体
        for (int i = 1; i < snake.size; i++) {
            if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
                return;
            }
        }

        // 蛇吃到食物
        if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
            init_food();  // 食物消失
            snake.size++; // 蛇长度加1
            score += 10;  // 分数增加
            // 速度增加
            //sleep_second -= 50;
        }

        // 存储蛇尾坐标
        last_x = snake.body[snake.size - 1].x;
        last_y = snake.body[snake.size - 1].y;

        // 蛇身移动,前一节身体给后一节身体赋值
        for (int i = snake.size - 1; i > 0; i--) {
            snake.body[i].x = snake.body[i - 1].x;
            snake.body[i].y = snake.body[i - 1].y;
        }

        // 蛇头移动,根据用户按键移动
        snake.body[0].x += kx;
        snake.body[0].y += ky;

        Sleep(sleep_second);
    }

    return;
}

void init_wall(void)
{
    for (size_t i = 0; i <= HIGH; i++) // 多行
    {
        for (size_t j = 0; j <= WIDE; j++) // 一行中的多列
        {
            if (j == WIDE) {
                printf("|");
            }
            else if (i == HIGH) {
                printf("_");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void show_score(void)
{
    // 将光标默认位置移动至 不干扰游戏的任意位置。
    COORD coord;

    coord.X = 0;
    coord.Y = HIGH + 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    printf("Game Over!!!\n");
    printf("成绩为：%d\n\n\n", score);
}