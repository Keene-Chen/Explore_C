/**
 * Author:   KeeneChen
 * DateTime: 2022.02.07-21:31:00
 * Description:
 * Command: xmake && xmake r good
 */

#include "good/good.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    Good g;
    // strcpy(g.id,"G00001");
    strcpy(g.name, "yashuaer");
    g.price = 22.96;
    strcpy(g.seller_id, "U00001");
    g.state = 2;

    AddGood(&g);
    AddGood(&g);
    PushGoods();
    GoodInfo(0);
    ShowGoods();

    return 0;
}