/**
 * Author     : KeeneChen
 * DateTime   : 2022.09.09-17:08:12
 * Description: snake
 */

#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HIGH 20
#define WIDE 60

struct BODY {
    int x;
    int y;
};

/* 定义蛇结构体 */
struct snake_s {
    struct BODY body[WIDE * HIGH]; // 蛇身
    int size; // 蛇的大小
} snake;

/* 定义食物结构体 */
struct food_s {
    int x;
    int y;
} food;

/* 全局变量 */
// 分数
extern int score;

// 用户按键的坐标
extern int kx;
extern int ky;

// 存储蛇尾坐标
extern int last_x;
extern int last_y;
extern int sleep_second;

/* 相关API */
void init_snake(void);
void init_food(void);
void init_ui(void);
void play_game(void);
void init_wall(void);
void show_score(void);

#endif