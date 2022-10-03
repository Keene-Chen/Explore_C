#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strstr(const char* src, const char* dest)
{
    int count = 0;
    while (*src != '\0') {
        if (*src != *dest) {
            src++;
            count++;
            continue;
        }

        // 创建临时指针进行二次比较
        const char* temp_src = src;
        const char* temp_dest = dest;
        while (*temp_dest != '\0') {
            // 二次匹配失败
            if (*temp_src != *temp_dest) {
                src++;
                count++;
                break;
            }
            temp_src++;
            temp_dest++;
        }
        // 匹配成功
        if (*temp_dest == '\0') {
            return count;
        }
    }
    return -1;
}

int main(void)
{
    const char* str1 = "asdnfdnfghdsnf";
    const char* str2 = "dnfg";
    int ret = my_strstr(str1, str2);
    if (ret != -1) {
        printf("%s\n", str1);
        for (int i = 0; i < ret; i++)
            printf(" ");
        printf("%s\n", str2);

        printf("查找到子串位置: %d\n", ret);
    } else {
        printf("未找到子串\n");
    }

    return 0;
}