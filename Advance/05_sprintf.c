#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // 1.格式化字符串
    char buf[1024] = { 0 };
    sprintf(buf, "你好,%s,欢迎加入我们!", "John");
    printf("buf:%s\n", buf);

    memset(buf, 0, 1024);
    sprintf(buf, "我今年%d岁了!", 20);
    printf("buf:%s\n", buf);

    // 2.拼接字符串
    memset(buf, 0, 1024);
    char str1[] = "hello";
    char str2[] = "world";
    int len = sprintf(buf, "%s %s", str1, str2);
    printf("buf:%s len:%d\n", buf, len);

    // 3.数字转字符串
    memset(buf, 0, 1024);
    int num = 100;
    sprintf(buf, "%d", num);
    printf("buf:%s\n", buf);
    //设置宽度 右对齐
    memset(buf, 0, 1024);
    sprintf(buf, "%8d", num);
    printf("buf:%s\n", buf);
    //设置宽度 左对齐
    memset(buf, 0, 1024);
    sprintf(buf, "%-8d", num);
    printf("buf:%s\n", buf);
    //转成16进制字符串 小写
    memset(buf, 0, 1024);
    sprintf(buf, "0x%x", num);
    printf("buf:%s\n", buf);

    //转成8进制字符串
    memset(buf, 0, 1024);
    sprintf(buf, "0%o", num);
    printf("buf:%s\n", buf);

    return 0;
}