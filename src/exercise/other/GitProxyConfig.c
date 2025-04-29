/**
 * Author:   KeeneChen
 * DateTime: 2021.08.11-22:20:08
 * Description: Git 代理配置脚本
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 3

void SetProxy();
void UsetProxy();
void Show();

char str[3][64];
int port = 7890;
const char *ProxyModel[] = {"http", "https", "sock5"};

int main(void)
{
    Show();
    char ch = getchar();
    if ((ch == 'a') || (ch == 'A'))
        SetProxy();
    else if (ch == 'b' || (ch == 'A'))
        UsetProxy();

    return 0;
}

/* 配置Git代理 */
void SetProxy()
{
    puts("Please enter the proxy port: ");
    scanf("%d", &port);

    for (int i = 0; i < LEN; i++)
    {
        sprintf(str[i], "git config --global %s.proxy %s://localhost:%d\n", ProxyModel[i], ProxyModel[i], port);
        system(str[i]);
    }

    system("git config --list");
}

/* 取消Git代理 */
void UsetProxy()
{
    for (int i = 0; i < LEN; i++)
    {
        sprintf(str[i], "git config --global --unset %s.proxy \n", ProxyModel[i]);
        system(str[i]);
    }

    system("git config --list");
}

/* 打印提示 */
void Show()
{
    printf("====================\n");
    printf("a.Configure Git proxy\n");
    printf("b.Cancel Git proxy\n");
    printf("====================\n");
    printf("Plase select mode(a/b): ");
}