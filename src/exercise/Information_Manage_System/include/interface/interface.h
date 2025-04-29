#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "tools/hint.h"
#include "user/user.h"
#include "good/good.h"
#include "order/order.h"
#include "menu/menu.h"

/**
 * @brief 
 * | 1.User Login | 2.User Sign Up | 3.Admin Login | 4.Exit |
 */
void MainInterface();

/**
 * @brief 
 * | 1.Goods | 2.Search | 3.Orders | 4.Users | 5.Delete | 6.Ban | 7.Back |
 */
void AdminInterface();

/**
 * @brief 
 * | 1.Buyer | 2.Seller | 3.Information | 4.Back |
 */
void UserInterface();

/**
 * @brief 
 * | 1.Goods | 2.Buy | 3.Search | 4.Order | 5.Infomation | 6.Back |
 */
void BuyerInterface();

/**
 * @brief 
 * | 1.Sell | 2.Goods | 3.Modify | 4.Ban | 5.Order | 6.Back |
 */
void SellerInterface();

/**
 * @brief 
 * | 1.Information | 2.Modify | 3.Top Up | 4.Back |
 */
void InfoInterface();

/**
 * @brief 
 * | 1.Password | 2.Contact | 3.Address | 4.Back |
 */
void ModifyInterface();

/**
 * @brief 
 * | 1.Name | 2.Price | 3.Description | 4.Back |
 */
void GoodInterface();


#endif // __INTERFACE_H__