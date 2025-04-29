#include "menu/menu.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    menu(MAIN);
    menu(ADMIN);
    menu(USER);
    menu(BUYER);
    menu(SELLER);
    menu(MODIFY);
    menu(GOOD);

    return 0;
}