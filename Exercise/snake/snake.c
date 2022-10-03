
/**
 * Author     : KeeneChen
 * DateTime   : 2022.09.09-17:08:12
 * Description: snake
 */

#include "snake.h"

#define _CRT_SECURE_NO_WARNINGS

/* ȫ�ֱ��� */
// ����
int score = 0;

// �û�����������
int kx = 0;
int ky = 0;

// �洢��β����
int last_x       = 0;
int last_y       = 0;
int sleep_second = 400;

void init_snake(void)
{
    snake.size      = 2;        // ���ܴ�С,��ͷ������
    snake.body[0].x = WIDE / 2; // ��ͷx����
    snake.body[0].y = HIGH / 2; // ��βy����

    snake.body[1].x = WIDE / 2 - 1; // �����һ��x����,+1ͷ�������,-1�����ұ�
    snake.body[1].y = HIGH / 2;     // �����һ��y����

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
    COORD coord = { 0 }; // ����ƶ���λ��

    // ����
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

    // ȥ����β
    coord.X = last_x;
    coord.Y = last_y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar(' ');

    // ��ʳ��
    coord.X = food.x; // 0-59
    coord.Y = food.y; // 0-19
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar('#');
}

void play_game(void)
{
    // Ĭ����ͷ�ƶ�����
    char key = 77;

    // �ж���ײǽ
    while (snake.body[0].x >= 0 && snake.body[0].x < WIDE && snake.body[0].y >= 0 && snake.body[0].y < HIGH) {
        // ������
        init_ui();

        // �����û�����
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

        // ��ײ��������
        for (int i = 1; i < snake.size; i++) {
            if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
                return;
            }
        }

        // �߳Ե�ʳ��
        if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
            init_food();  // ʳ����ʧ
            snake.size++; // �߳��ȼ�1
            score += 10;  // ��������
            // �ٶ�����
            //sleep_second -= 50;
        }

        // �洢��β����
        last_x = snake.body[snake.size - 1].x;
        last_y = snake.body[snake.size - 1].y;

        // �����ƶ�,ǰһ���������һ�����帳ֵ
        for (int i = snake.size - 1; i > 0; i--) {
            snake.body[i].x = snake.body[i - 1].x;
            snake.body[i].y = snake.body[i - 1].y;
        }

        // ��ͷ�ƶ�,�����û������ƶ�
        snake.body[0].x += kx;
        snake.body[0].y += ky;

        Sleep(sleep_second);
    }

    return;
}

void init_wall(void)
{
    for (size_t i = 0; i <= HIGH; i++) // ����
    {
        for (size_t j = 0; j <= WIDE; j++) // һ���еĶ���
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
    // �����Ĭ��λ���ƶ��� ��������Ϸ������λ�á�
    COORD coord;

    coord.X = 0;
    coord.Y = HIGH + 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    printf("Game Over!!!\n");
    printf("�ɼ�Ϊ��%d\n\n\n", score);
}