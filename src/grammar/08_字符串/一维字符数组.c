#include <stdio.h>

int main(void)
{
    char s[] = {'a', 'b', 'c', 'd', 'e'};

    // method 1
    for (int i = 0; i < 5; i++)
    {
        printf("%c", s[i]);
    }

    // method 2
    for (int i = 0; i < 5; i++)
    {
        putchar(s[i]);
    }

    // method 3
    printf("%s", s);

    // method 4
    puts(s);

    return 0;
}