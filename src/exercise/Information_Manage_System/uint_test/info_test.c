/**
 * Author:   KeeneChen
 * DateTime: 2022.02.06-21:57:28
 * Description: info module uint testing
 * Command: xmake && xmake r info
 */

#include <stdio.h>
#include "tools/info.h"

#define MAXSIZE 128

int main(void)
{
    char time[MAXSIZE], uid[MAXSIZE], gid[MAXSIZE], oid[MAXSIZE];
    GetDate(time);
    printf("%s\n", time);

    GenID(uid, 'U');
    GenID(gid, 'G');
    GenID(oid, 'O');
    printf("用户ID: %s\n商品ID: %s\n订单ID: %s\n", uid, gid, oid);

    return 0;
}