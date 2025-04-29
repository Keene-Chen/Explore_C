#ifndef __ORDER_H__
#define __ORDER_H__
#include "config.h"

// 订单数据结构定义
typedef struct
{
    char id[MAX_SIZE];
    char good_id[MAX_SIZE];
    double price;
    char date[MAX_SIZE];
    char seller_id[MAX_SIZE];
    char buyer_id[MAX_SIZE];
} Order;

// 订单操作接口
/**
 * @brief 从外部文件导入订单信息
 */
void PullOrders();

/**
 * @brief 将订单信息导出到外部文件
 */
void PushOrders();

/**
 * @brief  添加新订单
 * @param  o 待添加的订单指针
 * @return 添加成功返回1，失败返回0
 */
int AddOrder(Order *o);

/**
 * @brief 打印所有订单的信息
 */
void ShowOrders();

/**
 * @brief 打印给定卖家ID的订单
 * @param id 卖家ID
 */
void ShowOrdersSeller(const char *id);

/**
 * @brief 打印给定买家ID的订单
 * @param id 买家ID
 */
void ShowOrdersBuyer(const char *id);

#endif // __ORDER_H__