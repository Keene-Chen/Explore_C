/**
 * Author:   KeeneChen
 * DateTime: 2022.02.07-11:41:11
 * Description:
 * Command: xmake && xmake r user
 */

#include "user/user.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    User u;
    strcpy(u.id, "U00001");
    strcpy(u.name, "KeeneChen");
    strcpy(u.passwd, "8888");
    strcpy(u.contact, "400-820-8820");
    strcpy(u.address, "四川省成都市");
    u.balance = 999.90;

    AddUsers(&u);
    PushUsers();
    printf("succeed\n");
    ShowUsers();
    return 0;
}