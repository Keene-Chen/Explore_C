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

/* �����߽ṹ�� */
struct snake_s {
    struct BODY body[WIDE * HIGH]; // ����
    int size; // �ߵĴ�С
} snake;

/* ����ʳ��ṹ�� */
struct food_s {
    int x;
    int y;
} food;

/* ȫ�ֱ��� */
// ����
extern int score;

// �û�����������
extern int kx;
extern int ky;

// �洢��β����
extern int last_x;
extern int last_y;
extern int sleep_second;

/* ���API */
void init_snake(void);
void init_food(void);
void init_ui(void);
void play_game(void);
void init_wall(void);
void show_score(void);

#endif