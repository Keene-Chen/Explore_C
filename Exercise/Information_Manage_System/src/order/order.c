#include "config.h"
#include "tools/info.h"
#include "order/order.h"
#include <stdio.h>
#include <string.h>

static Order orders[MAX_ORDER]; // 所有订单
static int total_order = 0;     // 订单的总数
static const char *file_path = "data/order.txt";

/**
 * @brief 从外部文件导入订单信息
 */
void PullOrders()
{
    total_order = 0;
    FILE *fp = fopen(file_path, "r");
    IsOpen(fp);

    if (fp)
    {
        while (fscanf(fp, "%s%s%lf%s%s%s",
                      orders[total_order].id,
                      orders[total_order].good_id,
                      &orders[total_order].price,
                      orders[total_order].date,
                      orders[total_order].seller_id,
                      orders[total_order].buyer_id) != EOF)
        {
            total_order++;
        }

        fclose(fp);
    }
}

/**
 * @brief 将订单信息导出到外部文件
 */
void PushOrders()
{
    FILE *fp = fopen(file_path, "w");
    IsOpen(fp);
    
    for (int i = 0; i < total_order; i++)
    {
        fprintf(fp, "%s,%s,%.2f,%s,%s,%s\n",
                orders[i].id,
                orders[i].good_id,
                orders[i].price,
                orders[i].date,
                orders[i].seller_id,
                orders[i].buyer_id);
    }

    fclose(fp);
}

/**
 * @brief  添加新订单
 * @param  o 待添加的订单指针
 * @return 添加成功返回1，失败返回0
 */
int AddOrder(Order *o)
{
    if (total_order == MAX_ORDER)
        return 0;
    GenID(o->id, 'O');
    GetDate(o->date);
    orders[total_order++] = *o;
    return 1;
}

static const char *header = "|ID         |Good       |Price      |Date       |Seller     |Buyer      |";
static const char *divide = "+-----------+-----------+-----------+-----------+-----------+-----------+";

/**
 * @brief 打印单个订单作为表格的一行
 * @param index 用户下标
 */
static void PrintOrder(int index)
{
    printf("|%-10s |%-10s |%-10.2f |%-10s |%-10s |%-10s |\n",
           orders[index].id,
           orders[index].good_id,
           orders[index].price,
           orders[index].date,
           orders[index].seller_id,
           orders[index].buyer_id);
}

/**
 * @brief 打印所有订单的信息
 */
void ShowOrders()
{
    print_header for (int i = 0; i < total_order; i++)
    {
        PrintOrder(i);
        print_divide
    }
}

/**
 * @brief 打印给定卖家ID的订单
 * @param id 卖家ID
 */
void ShowOrdersSeller(const char *id)
{
    print_header for (int i = 0; i < total_order; i++) if (strcmp(orders[i].seller_id, id) == 0)
    {
        PrintOrder(i);
        print_divide
    }
}

/**
 * @brief 打印给定买家ID的订单
 * @param id 买家ID
 */
void ShowOrdersBuyer(const char *id)
{
    print_header for (int i = 0; i < total_order; i++) if (strcmp(orders[i].buyer_id, id) == 0)
    {
        PrintOrder(i);
        print_divide
    }
}
