/**
 * Author:   KeeneChen
 * DateTime: 2022.02.07-21:30:39
 * Description: 
 * Command: xmake && xmake r order
 */

#include "order/order.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    Order o;
    AddOrder(&o);
    ShowOrders();
    PushOrders();
    return 0;
}