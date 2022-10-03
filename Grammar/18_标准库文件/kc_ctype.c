#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int flag = 0;
    // flag = isalpha(ch = getchar());
    // flag = isalnum(ch = getchar());
    flag = iscntrl(ch = getchar());

    if (flag)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    return 0;
}