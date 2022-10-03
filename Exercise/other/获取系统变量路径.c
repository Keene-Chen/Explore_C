/**
 * Author:   KeeneChen
 * DateTime: 2022.01.27-17:45:31
 * Description: 获取Windows系统环境变量路径
 * TODO:
 *    1.写入文件
 *    2.读取文件到二维字符数组
 *    3.对二维字符数组排序
 *    4.显示二维数组
 *    5.数组去重 --待实现
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void get_path_to_file()
{
    char *buff = (char *)malloc(sizeof(char) * 2048);
    strcpy(buff, getenv("PATH"));
    int len = strlen(buff);

    FILE *fpw = fopen("./test.txt", "w");
    if (!fpw)
        exit(1);

    for (size_t i = 0; i < len; i++)
    {
        if (buff[i] == ';')
        {
            // printf("\n");
            fprintf(fpw, "%s", "\n");
        }
        else
        {
            // printf("%c", buff[i]);
            fprintf(fpw, "%c", buff[i]);
        }
    }

    fclose(fpw);

    free(buff);
    buff = NULL;
}

void select_sort(char str[][MAX_SIZE], int n)
{
    char temp[MAX_SIZE];
    int min = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
        { //本次找最小值的范围是从i开始 到最末尾
            if (strcmp(str[j], str[min]) == -1)
            {
                min = j;
            }
        }
        //此时min指向最小的
        //那么应该把min放在已排序部分的后一个,也就是本次排序的第一个
        strcpy(temp, str[i]);
        strcpy(str[i], str[min]);
        strcpy(str[min], temp);
    }
}

int main()
{
    // 1.写入文件
    get_path_to_file();

    // 2.读取文件到二维字符数组
    FILE *fp = fopen("test.txt", "r");
    char data[MAX_SIZE][MAX_SIZE] = {0};

    if (!fp)
        return -1;

    int i = 0;
    while (!feof(fp))
        fgets(data[i++], MAX_SIZE, fp);

    fclose(fp);

    // 3. 对二维字符数组排序
    select_sort(data, MAX_SIZE);

    // 4. 显示二维数组
    int row = sizeof(data) / sizeof(data[0]);       // 行数
    int col = sizeof(data[0]) / sizeof(data[0][0]); // 列数
    for (size_t i = 0; i < row; i++)
    {
        printf("%s", data[i]);
    }
}
