#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkNumArg(int argc, char **argv);

int main(int argc, char *argv[])
{
    // checkNumArg(argc, argv);

    if (!strcmp(argv[2], "+"))
    {
        printf("%s+%s=%d\n", argv[1], argv[3],
               atoi(argv[1]) + atoi(argv[3]));
    }
    else if (!strcmp(argv[2], "-"))
    {
        printf("%s-%s=%d\n", argv[1], argv[3],
               atoi(argv[1]) - atoi(argv[3]));
    }
    // 星号获取不到
    else if (!strcmp(argv[2], "x"))
    {
        printf("%s*%s=%d\n", argv[1], argv[3],
               atoi(argv[1]) * atoi(argv[3]));
    }
    else if (!strcmp(argv[2], "/"))
    {
        printf("%s/%s=%d\n", argv[1], argv[3],
               atoi(argv[1]) / atoi(argv[3]));
    }

    printf("主函数参数个数：%d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("第%d个参数是：%s\n", i, argv[i]);
    }

    return 0;
}

// 检查参数个数
void checkNumArg(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: %s src_file dest_file\n", argv[0]);
        exit(0);
    }
}