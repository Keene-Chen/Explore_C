#include <stdio.h>

int fun(char *s);

int main(void)
{
    printf("%d",fun("cat brush confident "));
    return 0;
}
int fun(char *s)
{
    int i, j = 0;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
            j++;
    return j;
}
