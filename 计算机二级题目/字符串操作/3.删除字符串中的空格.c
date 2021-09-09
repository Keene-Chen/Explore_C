/**
* Author:   hellochen
* DateTime: 2021.03.22-18:05:31
* Description: 请编写一个函数,用来删除字符串中的所有空格。
* 例如,输入 asd af aa z67,则输出为 asdafaaz67。
*/

#include <stdio.h>

int main(void)
{
    char str[128],*p=str;
    int i=0;
    fgets(str,128,stdin);

    while(*p)   // 遍历数组
    {
        if (*p!=' ')
        {
            str[i++]=*p;
        }
        p++;
    }
    str[i]='\0'; // 字符串结束符
    
    printf("%s",str);
    return 0;
}