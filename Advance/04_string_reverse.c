#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_reverse_01(char* str)
{
    if (str == NULL)
        return;
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

void string_reverse_02(char* str)
{
    if (str == NULL)
        return;
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main(void)
{
    char str[] = "hello";
    string_reverse_01(str);
    string_reverse_02(str);
    printf("%s\n", str);

    return 0;
}