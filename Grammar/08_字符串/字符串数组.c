#include <stdio.h>
#include <string.h>

int main(void)
{
    char weekdays1[7][10] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"};
    char *weekdays2[] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"};

    // 行数
    int row = sizeof(weekdays2) / sizeof(weekdays2[0]);
    int col = sizeof(weekdays2[0]) / sizeof(weekdays2[0][0]);
    // 遍历字符串
    for (int i = 0; i < row; i++)
    {
        puts(weekdays2[i]);
    }

    //!BUG 遍历字符
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c ", weekdays2[i][j]);
        }
        printf("\n");
    }

    return 0;
}