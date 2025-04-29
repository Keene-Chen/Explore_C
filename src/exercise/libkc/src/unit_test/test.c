#include "libkc.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("%f\n", KC_GetRandData(1, 2));

    printf("%f\n", KC_Add(1, 2));
    printf("%d\n", KC_MAX(1, 6));

    char dst[5] = {0};
    const char *src = "撒打算打算多所多";

    printf("%s\n", KC_StrCutSub(dst, src, 0,9));
    printf("%s\n", KC_StrCutLeft(dst, src, 6));
    printf("%s\n", KC_StrCutRight(dst, src, 9));
    printf("%s\n",dst);

    return 0;
}
