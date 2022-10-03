/**
 * Author:   KeeneChen
 * DateTime: 2022.01.16-15:35:00
 * Description: 正则表达式
 * Command: gcc 正则表达式.c -lregex
 */

#include <stdio.h>
#include <sys/types.h>
#include <regex.h>

#define MAXSIZE 256

void regex_errlog(int result, regex_t reg, char *errbuff)
{
    if (result)
    {
        regerror(result, &reg, errbuff, MAXSIZE);
        printf("%s\n", errbuff);
        regfree(&reg);
    }
}

void regex_show(regmatch_t *pmatch, char *test_str)
{
    printf("源字符串: %s\n正则匹配: ", test_str);
    for (int i = pmatch[0].rm_so; i < pmatch[0].rm_eo; ++i)
    {
        printf("%c", test_str[i]);
    }
}

int main(void)
{
    int result;
    int cflags = REG_EXTENDED | REG_ICASE;
    regex_t reg;
    const size_t nmatch = 1;
    regmatch_t pmatch[1];
    char errbuff[MAXSIZE];

    char test_str[MAXSIZE] = {0};
    char reg_str[MAXSIZE]  = {0};

    printf("请输入待查找字符串: ");
    scanf("%s", test_str);
    printf("请输入正则表达式: ");
    scanf("%s", reg_str);

    result = regcomp(&reg, reg_str, cflags);
    regex_errlog(result, reg, errbuff);

    result = regexec(&reg, test_str, nmatch, pmatch, 0);
    regex_errlog(result, reg, errbuff);

    if (!result)
        regex_show(pmatch, test_str);

    return 0;
}