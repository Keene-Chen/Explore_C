/**
* Author:   hellochen
* DateTime: 2021.03.22-18:08:09
* Description: 请编写函数,统计一行字符串中单词的个数,作为函数值返回。字符串在主函数中输入,规定所有单词由小写字母组成,
* 单词之间有若干个空格隔开,一行的开始没有空格。
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[128];
    int count=0;

    fgets(a,128,stdin);

    for (int i = 0; a[i] != '\0'; i++)  // 遍历字符串
    {
        if (a[i] !=' '&& (a[i+1] ==' '|| a[i+1] == '\0')) 
        {
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}
